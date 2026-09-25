#include "AirportData.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;
using namespace boost::algorithm;

// ------ SEARCHING FOR AN AIRPORT ------

vector <Airports> AirportData::SearchByID(const string& id) {
    vector <Airports> search;
    bool found = false;
    for (const Airports&a : Airport) {
        if (a.getID() == id) {
            search.push_back(a);
            found = true;
        }
    } if (!found) cout << "No airports found." << endl;
    return search;
}

vector <Airports> AirportData::SearchByName(const string& name) {
    vector <Airports> search;
    bool found = false;
    for (const Airports&a : Airport) {
        // Checks if user's input was matched with any of the airports
        // string::npos means not found, in the code means NOT not found, which is found
        if (a.getName().find(name) != string::npos) {
            search.push_back(a);
            found = true;
        }
    } if (!found) cout << "No airports found." << endl;
    return search;
}

vector <Airports> AirportData::SearchByCountryCode(const string& country) {
    vector <Airports> search;
    bool found = false;
    for (const Airports&a : Airport) {
        if (a.getIsoCountry() == country) {
            search.push_back(a);
            found = true;
        }
    } if (!found) cout << "No airports found." << endl;
    return search;
}

vector <Airports> AirportData::SearchByIATA(const string& iata) {
    vector <Airports> search;
    bool found = false;
    for (const Airports&a : Airport) {
        if (a.getIataCode() == iata) {
            search.push_back(a);
            found = true;
        }
    } if (!found) cout << "No airports found." << endl;
    return search;
}
// https://www.geeksforgeeks.org/cpp/map-associative-containers-the-c-standard-template-library-stl/
map<string, int> AirportData::CountByAirportType(const vector<Airports>& result) const {
    map<string, int> count;

    for (const Airports&a : result) {
        string type = a.getType();
        Cleaning(type);
        count[type]++;
    }
    for (pair<const string, int>& part : count )
        cout << "There are " << part.second << " of " << part.first << endl;
    return count;
}