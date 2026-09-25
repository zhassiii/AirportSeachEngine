#include "AirportData.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

void AirportData::AirportViewing(int viewing) {
    int count = 0;
    if (count == viewing) cout << "Exiting..." << endl;
    else if (count < viewing) {
        for (int i = 0; i < viewing && Airport.size(); i++) {
            Airport[i].print();
        }
    }
}
// Understanding how to access items in vector of vectors
// https://www.geeksforgeeks.org/cpp/vector-of-vectors-in-c-stl-with-examples/
void AirportData::groupByMunic() {
    vector<string> munic;
    vector<vector<string>> airNameInMunic;

    int viewing, count = 0;
    cout << "How many municipalities would you like to see? ";
    cin >> viewing;
    NumberOnly(viewing);
    cin.ignore(1000, '\n');
    if (count == viewing) cout << "Exiting..." << endl;

    for (int i = 0; i < Airport.size(); i++) {
        string curMun = Airport[i].getMunicipality();
        string airName = Airport[i].getName();
        bool municFound = false;

        for (int j = 0; j < munic.size(); j++) {
            if (munic[j] == curMun) {
                municFound = true;

                bool airFound = false;
                for (int k = 0; k < airNameInMunic[j].size(); k++) {
                    if (airNameInMunic[j][k] == airName) {
                        airFound = true;
                        break;
                    }
                }
                if (!airFound) airNameInMunic[j].push_back(airName);
                break;
            }
        }
        if (!municFound) {
            munic.push_back(curMun);
            vector<string> emptyVec;
            emptyVec.push_back(airName);
            airNameInMunic.push_back(emptyVec);
        }
    }
    for (int i = 0; i < munic.size() && i < viewing; i++) {
        cout << "\n---------Airports at" << munic[i] << "---------" << endl;

        for (int j = 0; j < airNameInMunic[i].size(); j++) {
            cout << airNameInMunic[i][j] <<  endl;
        }
    }
}

void AirportData::MinMaxElev() {
    Airports lowest = Airport[0];
    Airports highest = Airport[0];
    for (const Airports&a : Airport) {
        if (a.getElevationFt() < lowest.getElevationFt())
            lowest = a;
        if (a.getElevationFt() > highest.getElevationFt())
            highest = a;
    }
    cout << "Highest elevation airport is: " << highest.getName()
         << " at " << highest.getElevationFt() << endl;
    cout << "Lowest elevation airport is: " << lowest.getName()
         << " at " << lowest.getElevationFt() << endl;
}

void AirportData::MissingIATA() {
    int count, viewing = 0;
    cout << "How many airports with missing IATA code would you like to view? ";
    cin >> viewing;
    NumberOnly(viewing);
    cout << "Missing IATA airports: " << endl;
    for (const Airports&a : Airport) {
        if (a.getIataCode().empty()) {
            if (count <= viewing) {
                cout << a.getName() << endl;
            }
            count++;
        }
    }
}

void AirportData::sortByName() {
    cout << "How many airports would you like to see? ";
    sort(Airport.begin(), Airport.end(), [](Airports a, Airports b) {
        return a.getName() < b.getName();
    });
    int viewing; cin >> viewing;
    NumberOnly(viewing);
    AirportViewing(viewing);
}

void AirportData::sortByCountry() {
    cout << "How many airports would you like to see? ";
    sort(Airport.begin(), Airport.end(), [](Airports a, Airports b) {
        return a.getIsoCountry() < b.getIsoCountry();
    });
    int viewing; cin >> viewing;
    NumberOnly(viewing);
    AirportViewing(viewing);
}

void AirportData::sortByType() {
    cout << "How many airports would you like to see? ";
    sort(Airport.begin(), Airport.end(), [](Airports a, Airports b) {
        return a.getType() < b.getType();
    });
    int viewing; cin >> viewing;
    NumberOnly(viewing);
    AirportViewing(viewing);
}

void AirportData::sortByElevation() {
    cout << "How many airports would you like to see? ";
    sort(Airport.begin(), Airport.end(), [](Airports a, Airports b) {
        return a.getElevationFt() < b.getElevationFt();
    });
    int viewing; cin >> viewing;
    NumberOnly(viewing);
    AirportViewing(viewing);
}
