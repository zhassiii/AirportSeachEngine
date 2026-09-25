#include "Airports.h"
#include "AirportData.h"
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

// SETTERS AND GETTERS
Airports::Airports() {}

void Airports::set(string id, string type, string n, int elev, string con, string country,
                   string region, string m, string icao, string iata, string gps, string loc, string coord) {
    ident = id;
    airport_type = type;
    name = n;
    elevation_ft = elev;
    continent = con;
    iso_country = country;
    iso_region = region;
    municipality = m;
    icao_code = icao;
    iata_code = iata;
    gps_code = gps;
    local_code = loc;
    coordinates = coord;
}

string Airports::getID() const {return ident;}
string Airports::getType() const {return airport_type;}
string Airports::getName() const {return name;}
int Airports::getElevationFt() const {return elevation_ft;}
string Airports::getContinent() const {return continent;}
string Airports::getIsoCountry() const {return iso_country;}
string Airports::getIsoRegion() const {return iso_region;}
string Airports::getMunicipality() const {return municipality;}
string Airports::getIcaoCode() const {return icao_code;}
string Airports::getIataCode() const {return iata_code;}
string Airports::getGpsCode() const {return gps_code;}
string Airports::getLocalCode() const {return local_code;}
string Airports::getCoordinates() const {return coordinates;}

// PRINTING Airports

void Airports::print() const {
    cout << "=================================" << endl;
    cout << "Airport ID: " << ident << endl;
    cout << "Airport type: " << airport_type << endl;
    cout << "Airport name: " << name << endl;
    cout << "Elevation feat: " << elevation_ft << endl;
    cout << "Airport's continent: " << continent << endl;
    cout << "ISO country: " << iso_country << endl;
    cout << "ISO region: " << iso_region << endl;
    cout << "Municipality: " << municipality << endl;
    cout << "ICAO code: " << icao_code << endl;
    cout << "IATA code: " << iata_code << endl;
    cout << "GPS code: " << gps_code << endl;
    cout << "Local code: " << local_code << endl;
    cout << "Latitude and longitude: " << coordinates << endl;
}