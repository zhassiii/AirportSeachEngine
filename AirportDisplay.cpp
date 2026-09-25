#include "AirportDisplay.h"
#include "AirportData.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

AirportDisplay::AirportDisplay() {}

void AirportDisplay::display() const {
    AirportData airport;
    airport.ReadFromCSV();
    // Menu interface
    int choice = 0;
    do {
        cout << "====== Nottingham SkyRoute Explorer ======" << endl;
        cout << "1. Search airports by ID" << endl;
        cout << "2. Search airports by name" << endl;
        cout << "3. Search airports by country code" << endl;
        cout << "4. Search airports by IATA code" << endl;
        cout << "5. Add a new airport" << endl;
        cout << "6. Advanced features" << endl;
        cout << "7. Exit and Save" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        airport.NumberOnly(choice);
        cin.ignore(1000, '\n');

        if (choice == 1) {
            string ids;
            cout << "Enter ID: ";
            getline(cin, ids); to_upper(ids);
            vector<Airports> results = airport.SearchByID(ids);
            for (const Airports&a : results) a.print();
            airport.CountByAirportType(results);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter airport's partial name: ";
            getline(cin, name); name[0] = toupper(name[0]);
            vector<Airports> results = airport.SearchByName(name);
            for (Airports&a : results) a.print();
            airport.CountByAirportType(results);
        }
        else if (choice == 3) {
            string country;
            cout << "Enter country code: ";
            getline(cin, country); to_upper(country);
            vector<Airports> results = airport.SearchByCountryCode(country);
            for (const Airports&a : results) a.print();
            airport.CountByAirportType(results);
        }
        else if (choice == 4) {
            string iata;
            cout << "Enter the IATA code: ";
            getline(cin, iata); to_upper(iata);
            vector<Airports> results = airport.SearchByIATA(iata);
            for (const Airports&a : results) a.print();
            airport.CountByAirportType(results);
        }
        else if (choice == 5) {
            airport.NewAirport();
        }
        else if (choice == 6) {
            int advanced;
            do {
                cout << "====== Advanced Search ======" << endl;
                cout << "1. View highest and lowest elevation airports" << endl;
                cout << "2. View airports with missing IATA codes" << endl;
                cout << "3. Group airports by their municipality" << endl;
                cout << "4. Sort by airport name" << endl;
                cout << "5. Sort by country" << endl;
                cout << "6. Sort by airport type" << endl;
                cout << "7. Sort by elevation" << endl;
                cout << "8. Exit" << endl;
                cout << "===================================" << endl;
                cout << "Enter your choice: ";
                cin >> advanced;
                airport.NumberOnly(advanced);

                if (advanced == 1) {
                    airport.MinMaxElev();
                }
                else if (advanced == 2) {
                    airport.MissingIATA();
                }
                else if (advanced == 3) {
                    airport.groupByMunic();
                }
                else if (advanced == 4) {
                    airport.sortByName();
                }
                else if (advanced == 5) {
                    airport.sortByCountry();
                }
                else if (advanced == 6) {
                    airport.sortByType();
                }
                else if (advanced == 7) {
                    airport.sortByElevation();
                }
            } while (advanced != 8);
        }
        else if (choice == 7) {
            airport.SaveAirport();
            cout << "Thank you for using Nottingham SkyRoute Explorer." << endl;
        }
    } while (choice != 7);
}