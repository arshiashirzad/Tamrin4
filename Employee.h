#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

class Employee {
public:
    string name;
    string id;
    Address address;

private:
    double hourWork;
    double salaryPerHour;
    double workToDo;
    double workDone;

    bool isValid(const string& id);

public:
    // Constructors
    Employee(const string& name, const string& id, const Address& address, double hourWork, double salaryPerHour, double workToDo, double workDone);
    // Copy constructor
    Employee(const Employee& other);

    double getHourWork() const;
    double getSalaryPerHour() const;
    double getWorkToDo() const;
    double getWorkDone() const;

    void setHourWork(double hourWork);
    void setSalaryPerHour(double salaryPerHour);
    void setWorkToDo(double workToDo);
    void setWorkDone(double workDone);
    void setId(const string& id);

    // Operator overloads
    Employee& operator=(const Employee& other);
    friend ostream& operator<<(ostream& os, const Employee& employee);
    friend istream& operator>>(istream& is, Employee& employee);

    // Member functions
    double percentage() const;
    double calculateSalary() const;
    double efficiency() const;

};

#endif
