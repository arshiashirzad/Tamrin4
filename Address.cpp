#include "Address.h"

// Constructor
Address::Address(const string& country, const string& city, const string& street)
        : country(country), city(city), street(street) {}

string Address::getCountry() const {
    return country;
}

string Address::getCity() const {
    return city;
}

string Address::getStreet() const {
    return street;
}

void Address::setCountry(const string& country) {
    this->country = country;
}

void Address::setCity(const string& city) {
    this->city = city;
}

void Address::setStreet(const string& street) {
    this->street = street;
}

// Friend functions
ostream& operator<<(ostream& os, const Address& address) {
    os << "Country: " << address.country << ", City: " << address.city << ", Street: " << address.street;
    return os;
}

istream& operator>>(istream& is, Address& address) {
    cout << "Enter country: ";
    getline(is, address.country);
    cout << "Enter city: ";
    getline(is, address.city);
    cout << "Enter street: ";
    getline(is, address.street);
    return is;
}
