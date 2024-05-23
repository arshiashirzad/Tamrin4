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
    Address(const string& country, const string& city, const string& street)
            : country(country), city(city), street(street) {}

    string getCountry() const {
        return country;
    }

    string getCity() const {
        return city;
    }

    string getStreet() const {
        return street;
    }

    void setCountry(const string& country) {
        this->country = country;
    }

    void setCity(const string& city) {
        this->city = city;
    }

    void setStreet(const string& street) {
        this->street = street;
    }

    // Friend functions
    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};

// Overload <<
ostream& operator<<(ostream& os, const Address& address) {
    os << "Country: " << address.country << ", City: " << address.city << ", Street: " << address.street;
    return os;
}

// Overload >>
istream& operator>>(istream& is, Address& address) {
    cout << "Enter country: ";
    getline(is, address.country);
    cout << "Enter city: ";
    getline(is, address.city);
    cout << "Enter street: ";
    getline(is, address.street);
    return is;
}

int main() {

    return 0;
}
