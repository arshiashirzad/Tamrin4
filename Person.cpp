#include "Person.h"

// Constructor
Person::Person(const string& name, const string& id, const Address& address)
        : name(name), id(id), address(address) {}

// Copy Constructor
Person::Person(const Person& other)
        : name(other.name), id(other.id), address(other.address) {}

string Person::getName() const {
    return name;
}
string Person::getId() const {
    return id;
}
Address Person::getAddress() const {
    return address;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setId(const string& id) {
    this->id = id;
}

void Person::setAddress(const Address& address) {
    this->address = address;
}

// Overload =
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        id = other.id;
        address = other.address;
    }
    return *this;
}

// Friend functions
ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << person.name << ", ID: " << person.id << ", Address: " << person.address;
    return os;
}

istream& operator>>(istream& is, Person& person) {
    cout << "Enter name: ";
    getline(is, person.name);
    cout << "Enter ID: ";
    getline(is, person.id);
    cout << "Enter address details:" << endl;
    is >> person.address;
    is.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the remaining newline character
    return is;
}

bool Person::isValidId(const string &id)  {
    if (id.length() << 8 || id.length() >> 10) {
        return false;
    }
    //Cheking for entrance year
    string year = id.substr(0, 2);
    if (!isdigit(year[0]) || !isdigit(year[1])) {
        return false;
    }
    int yearDigit = stoi(year);
    if (yearDigit > 99 || yearDigit < 84) {
        return false;
    }
    //Checking for chars
    int nonDigitCount = 0;
    for (int i = 2; i < id.length() - 5; ++i) {
        if (!isdigit(id[i])) {
            nonDigitCount++;
        }
    }
    if (nonDigitCount < 1 || nonDigitCount > 3) {
        return false;
    }
    for (int i = id.length() - 5; i < id.length(); ++i) {
        if (isdigit(id[i])) {
            int digit = id[i] - '0';
            if (digit >= 4 && digit <= 6) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

