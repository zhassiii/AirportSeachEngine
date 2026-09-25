#include "AirportData.h"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace boost::algorithm;
using namespace std;

// https://www.geeksforgeeks.org/cpp/how-to-use-cin-fail-method-in-cpp/
// Using cin.fail() to check if the user has put an integer or not
void AirportData::NumberOnly(int &num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "This is not a number, please enter a number: ";
        cin >> num;
    }
}
// https://www.geeksforgeeks.org/cpp/boosttrim-in-cpp-library/
void AirportData::Cleaning(string &info) const {
    trim(info);
    erase_all_copy(info, "\"");
}

// ------LOADING THE CSV AND READING FROM IT------
void AirportData::ReadFromCSV() {
    ifstream file("airports.csv");
    string line;

    getline(file, line);

    while (getline(file, line)) {
        // Allows to use the getline but now watches out for commas
        stringstream ss(line);
        string temp;

        Airports a;
        string id, type, n, con, country, region, m, icao, iata, gps, loc, coord;
        int elev;

        try {
            // ',' means it stops reading when reaching a comma
            getline(ss, id, ',');   Cleaning(id);
            getline(ss, type, ','); Cleaning(type);
            getline(ss, n, ',');    Cleaning(n);
            getline(ss, temp, ','); elev = stoi(temp); erase_all_copy(temp, "\"");
            getline(ss, con, ',');  Cleaning(con);
            getline(ss, country, ','); Cleaning(country);
            getline(ss, region, ',');   Cleaning(region);
            getline(ss, m, ',');    Cleaning(m);
            getline(ss, icao, ','); Cleaning(icao);
            getline(ss, iata, ','); Cleaning(iata);
            getline(ss, gps, ',');  Cleaning(gps);
            getline(ss, loc, ',');  Cleaning(loc);
            getline(ss, coord);         Cleaning(coord);
            getline(ss, loc, ',');  Cleaning(loc);

            //Saves into the vector of the airports
            a.set(id, type, n, elev, con, country, region,
                m, icao, iata, gps, loc, coord);
            Airport.push_back(a);
        } catch (...) {
        }
    }

    file.close();
}
// ------ ADDING A NEW AIRPORT TO THE CSV ------
// Entering string with spaces
// https://www.geeksforgeeks.org/cpp/take-long-string-input-with-spaces-in-cpp/
void AirportData::NewAirport() {
    Airports a;
    string id, type, n, con, country, region, m, icao, iata, gps, loc, coord;
    int elev;
    cout << "===========================================" << endl;
    cout << "Enter the details of a new airport " << endl;
    cout << "Airport ID: " ;         cin >> id; to_upper(id);
    cout << "Airport type: " ;        cin >> type; to_lower(type); cin.ignore(10000, '\n');
    cout << "Airport name: ";          getline(cin, n); n[0] = toupper(n[0]);
    cout << "Elevation feat: ";         if (!(cin >> elev)) NumberOnly(elev); cin.ignore(10000, '\n');
    cout << "Airport's continent: ";    cin >> con; to_upper(con);
    cout << "Airport's ISO country: ";  cin >> country; to_upper(country);
    cout << "Airport's ISO region: ";   cin >> region; to_upper(region); cin.ignore(10000, '\n');
    cout << "Airport's Municipality: "; getline(cin, m); m[0] = toupper(m[0]);
    cout << "Airport's ICAO code: ";    getline(cin, icao); to_upper(icao);
    cout << "Airport's IATA code: ";    getline(cin, iata); to_upper(iata);
    cout << "Airport's GPS code: ";     cin >> gps; to_upper(gps);
    cout << "Airport's Local code: ";   cin.ignore(1000, '\n'); getline(cin, loc); to_upper(loc);
    cout << "Airport's Latitude and Longitude: "; getline(cin, coord);

    int confirm;
    cout << "Do you wish to proceed (1) or change the information (you will need to start over) (2)? ";
    cin >> confirm;
    NumberOnly(confirm);
    if (confirm == 2) {
        NewAirport();
        return;
    }

    a.set(id, type, n, elev, con, country, region, m, icao, iata, gps, loc, coord);
    Airport.push_back(a);

    SaveAirport();

    cout << "Airport added successfully! " << endl;
}

void AirportData::SaveAirport() const{
    ofstream file("airports.csv");

    file << "ident,type,name,elevation_ft,continent,iso_country,iso_region,"
            "municipality,icao_code,iata_code,gps_code,local_code,coordinates\n";

    for (const Airports&a : Airport) {
        file << a.getID() << ","
             << a.getType() << ","
             << a.getName() << ","
             << a.getElevationFt() << ","
             << a.getContinent() << ","
             << a.getIsoCountry() << ","
             << a.getIsoRegion() << ","
             << a.getMunicipality() << ","
             << a.getIcaoCode() << ","
             << a.getIataCode() << ","
             << a.getGpsCode() << ","
             << a.getLocalCode() << ","
             << a.getCoordinates() << "\n";
    }
    file.close();
}
