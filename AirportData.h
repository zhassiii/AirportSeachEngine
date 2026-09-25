#ifndef AIRPORT_AIRPORTSEARCH_H
#define AIRPORT_AIRPORTSEARCH_H

#include "Airports.h"
#include <vector>
#include <map>

using namespace std;

class AirportData {
    private:
        vector<Airports> Airport;
    public:
        void ReadFromCSV();
        void NewAirport();
        void SaveAirport() const;

        void NumberOnly(int& num);
        void Cleaning(string& info) const;
        void AirportViewing(int viewing);

        vector <Airports> SearchByID(const string& id);
        vector<Airports> SearchByName(const string& name);
        vector<Airports> SearchByCountryCode(const string& country);
        vector<Airports> SearchByIATA(const string& iata);
        map<string, int> CountByAirportType(const vector<Airports>& result) const;

        void groupByMunic();
        void MinMaxElev();
        void MissingIATA();
        void sortByName();
        void sortByCountry();
        void sortByType();
        void sortByElevation();


};

#endif