#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Address.h"

class Person {

private:
    string name;
    string id;
    Address address;

    bool isValidId(const string& id);

public:
    // Constructors
    Person(const string& name, const string& id, const Address& address);
    // Copy constructor
    Person(const Person& other);

    string getName() const;
    string getId() const;
    Address getAddress() const;

    void setName(const string& name);
    void setId(const string& id);
    void setAddress(const Address& address);

    // Overload assignment operator
    Person& operator=(const Person& other);

    // Friend functions
    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& is, Person& person);
};

#endif
