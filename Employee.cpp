#include "Employee.h"

// Constructor
Employee::Employee(const string &name, const string &id, const Address &address, double hourWork, double salaryPerHour,
                   double workToDo, double workDone)
        : name(name), id(id), address(address), hourWork(hourWork), salaryPerHour(salaryPerHour), workToDo(workToDo),
          workDone(workDone) {
    if (!isValidId(id)) {
        cout << "Invalid ID" << endl;
    }
}

// Copy Constructor
Employee::Employee(const Employee &other)
        : name(other.name), id(other.id), address(other.address), hourWork(other.hourWork),
          salaryPerHour(other.salaryPerHour), workToDo(other.workToDo), workDone(other.workDone) {}


double Employee::getHourWork() const {
    return hourWork;
}

double Employee::getSalaryPerHour() const {
    return salaryPerHour;
}

double Employee::getWorkToDo() const {
    return workToDo;
}

double Employee::getWorkDone() const {
    return workDone;
}


void Employee::setId(const string &id) {
    if (isValidId(id)) {
        this->id = id;
    } else {
        cout << "Invalid ID" << endl;
    }
}

void Employee::setHourWork(double hourWork) {
    this->hourWork = hourWork;
}

void Employee::setSalaryPerHour(double salaryPerHour) {
    this->salaryPerHour = salaryPerHour;
}

void Employee::setWorkToDo(double workToDo) {
    this->workToDo = workToDo;
}

void Employee::setWorkDone(double workDone) {
    this->workDone = workDone;
}

// Overload =
Employee &Employee::operator=(const Employee &other) {
    if (this != &other) {
        name = other.name;
        id = other.id;
        address = other.address;
        hourWork = other.hourWork;
        salaryPerHour = other.salaryPerHour;
        workToDo = other.workToDo;
        workDone = other.workDone;
    }
    return *this;
}

// Function to calculate percentage of work done
double Employee::percentage() const {
    return (workDone / workToDo);
}

// Function to calculate salary based on work done
double Employee::calculateSalary() const {
    double lastSalary = (hourWork * salaryPerHour) * (1 - percentage());
    return lastSalary;
}

// Function to calculate efficiency
double Employee::efficiency() const {
    return (percentage() / salaryPerHour);
}

// Friend functions
ostream &operator<<(ostream &os, const Employee &Employee) {
    os << "Name: " << Employee.name << ", ID: " << Employee.id << ", Address: " << Employee.address
       << ", Hours Worked: " << Employee.hourWork << ", Salary Per Hour: " << Employee.salaryPerHour
       << ", Work To Do: " << Employee.workToDo << ", Work Done: " << Employee.workDone;
    return os;
}

istream &operator>>(istream &is, Employee &Employee) {
    cout << "Enter name: ";
    getline(is, Employee.name);
    cout << "Enter ID: ";
    getline(is, Employee.id);
    cout << "Enter address details:" << endl;
    is >> Employee.address;
    cout << "Enter hours worked: ";
    is >> Employee.hourWork;
    cout << "Enter salary per hour: ";
    is >> Employee.salaryPerHour;
    cout << "Enter work to do: ";
    is >> Employee.workToDo;
    cout << "Enter work done: ";
    is >> Employee.workDone;
    return is;
}

    // Function to validate ID
    bool Employee::isValidId(const string &id) const {
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
    if (id[2] == '*') {
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
