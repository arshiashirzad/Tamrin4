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
    Address(const string& country, const string& city, const string& street) : country(country), city(city), street(street) {}

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

class Person {
private:
    string name;
    string id;
    Address address;

    bool isValid(const string& id) {
        return true;
    }

public:
    Person(const string& name, const string& id, const Address& address)
            : name(name), id(id), address(address) {
        if (!isValid(id)) {
            cout << "Invalid ID" << endl;
        }
    }
    //Copy Constructors
    Person(const Person& other) : name(other.name), id(other.id), address(other.address) {}

    string getName() const {
        return name;
    }

    string getId() const {
        return id;
    }

    Address getAddress() const {
        return address;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setId(const string& id) {
        if (isValid(id)) {
            this->id = id;
        } else {
            cout << "Invalid ID" << endl;
        }
    }

    void setAddress(const Address& address) {
        this->address = address;
    }

    // Overload =
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            id = other.id;
            address = other.address;
        }
        return *this;
    }

    // Friend functions
    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& is, Person& person);
};

// Overload <<
ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << person.name << ", ID: " << person.id << ", Address: " << person.address;
    return os;
}

// Overload >>
istream& operator>>(istream& is, Person& person) {
    cout << "Enter name: ";
    getline(is, person.name);
    cout << "Enter ID: ";
    getline(is, person.id);
    if (!person.isValid(person.id)) {
        cout << "Invalid ID" << endl;
    }
    cout << "Enter address details:" << endl;
    is >> person.address;
    return is;
}
int main() {
    return 0;
}
