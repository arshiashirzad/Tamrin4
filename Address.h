#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
using namespace std;
class Address {
private:
    string country;
    string city;
    string street;

public:
    // Constructor
    Address(const string& country, const string& city, const string& street);

    // Getter methods
    string getCountry() const;
    string getCity() const;
    string getStreet() const;

    // Setter methods
    void setCountry(const string& country);
    void setCity(const string& city);
    void setStreet(const string& street);

    // Friend functions
    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};

#endif // ADDRESS_H
