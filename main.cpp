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

class Employee {
public:
    std::string name;
    std::string id;
    Address address;

private:
    double hourWork;
    double salaryPerHour;
    double workToDo;
    double workDone;

    bool isValid(const std::string& id) {
        return true;
    }

public:
    Employee(const std::string& name, const std::string& id, const Address& address, double hourWork, double salaryPerHour, double workToDo, double workDone)
            : name(name), id(id), address(address), hourWork(hourWork), salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {
        if (!isValid(id)) {
            std::cout << "Invalid ID" << std::endl;
        }
    }
    // Copy Constructor
    Employee(const Employee& other)
            : name(other.name), id(other.id), address(other.address), hourWork(other.hourWork), salaryPerHour(other.salaryPerHour), workToDo(other.workToDo), workDone(other.workDone) {}

    double getHourWork() const {
        return hourWork;
    }

    double getSalaryPerHour() const {
        return salaryPerHour;
    }

    double getWorkToDo() const {
        return workToDo;
    }

    double getWorkDone() const {
        return workDone;
    }

    void setHourWork(double hourWork) {
        this->hourWork = hourWork;
    }

    void setSalaryPerHour(double salaryPerHour) {
        this->salaryPerHour = salaryPerHour;
    }

    void setWorkToDo(double workToDo) {
        this->workToDo = workToDo;
    }

    void setWorkDone(double workDone) {
        this->workDone = workDone;
    }

    void setId(const std::string& id) {
        if (isValid(id)) {
            this->id = id;
        } else {
            std::cout << "Invalid ID" << std::endl;
        }
    }

    // Overload =
    Employee& operator=(const Employee& other) {
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

    // Function to calculate salary based on work done
    double calculateSalary() const {
        return hourWork * salaryPerHour;
    }

    // Friend functions to overload << and >>
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    friend std::istream& operator>>(std::istream& is, Employee& employee);
};

// Overload << operator for Employee
std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os << "Name: " << employee.name << ", ID: " << employee.id << ", Address: " << employee.address
       << ", Hours Worked: " << employee.hourWork << ", Salary Per Hour: " << employee.salaryPerHour
       << ", Work To Do: " << employee.workToDo << ", Work Done: " << employee.workDone;
    return os;
}

// Overload >> operator for Employee
std::istream& operator>>(std::istream& is, Employee& employee) {
    std::cout << "Enter name: ";
    std::getline(is, employee.name);
    std::cout << "Enter ID: ";
    std::getline(is, employee.id);
    if (!employee.isValid(employee.id)) {
        std::cout << "Invalid ID" << std::endl;
    }
    std::cout << "Enter address details:" << std::endl;
    is >> employee.address;
    std::cout << "Enter hours worked: ";
    is >> employee.hourWork;
    std::cout << "Enter salary per hour: ";
    is >> employee.salaryPerHour;
    std::cout << "Enter work to do: ";
    is >> employee.workToDo;
    std::cout << "Enter work done: ";
    is >> employee.workDone;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the remaining newline character
    return is;
}
int main() {
    return 0;
}
