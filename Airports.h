#ifndef AIRPORT_AIRPORTS_H
#define AIRPORT_AIRPORTS_H
#include <string>
#include <vector>
using namespace std;

class Airports {
    private:
        string ident;
        string airport_type;
        string name;
        int elevation_ft;
        string continent;
        string iso_country;
        string iso_region;
        string municipality;
        string icao_code;
        string iata_code;
        string gps_code;
        string local_code;
        string coordinates;

    public:
        void set(string id, string type, string n, int elev, string con, string country,
                 string region, string m, string icao, string iata, string gps, string loc, string coord);

        string getID() const;
        string getType() const;
        string getName() const;
        int getElevationFt() const;
        string getContinent() const;
        string getIsoCountry() const;
        string getIsoRegion() const;
        string getMunicipality() const;
        string getIcaoCode() const;
        string getIataCode() const;
        string getGpsCode() const;
        string getLocalCode() const;
        string getCoordinates() const;

        Airports();
        void print() const;
};

#endif //AIRPORT_AIRPORTS_H