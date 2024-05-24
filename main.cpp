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
    string name;
    string id;
    Address address;

private:
    double hourWork;
    double salaryPerHour;
    double workToDo;
    double workDone;

    bool isValid(const string& id) {
        return true;
    }

public:
    Employee(const string& name, const string& id, const Address& address, double hourWork, double salaryPerHour, double workToDo, double workDone)
            : name(name), id(id), address(address), hourWork(hourWork), salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {
        if (!isValid(id)) {
            cout << "Invalid ID" << endl;
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

    void setId(const string& id) {
        if (isValid(id)) {
            this->id = id;
        } else {
            cout << "Invalid ID" << endl;
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

    // Friend functions
    friend ostream& operator<<(ostream& os, const Employee& employee);
    friend istream& operator>>(istream& is, Employee& employee);
};

// Overload <<
ostream& operator<<(ostream& os, const Employee& employee) {
    os << "Name: " << employee.name << ", ID: " << employee.id << ", Address: " << employee.address
       << ", Hours Worked: " << employee.hourWork << ", Salary Per Hour: " << employee.salaryPerHour
       << ", Work To Do: " << employee.workToDo << ", Work Done: " << employee.workDone;
    return os;
}

// Overload >>
istream& operator>>(istream& is, Employee& employee) {
    cout << "Enter name: ";
    getline(is, employee.name);
    cout << "Enter ID: ";
    getline(is, employee.id);
    if (!employee.isValid(employee.id)) {
        cout << "Invalid ID" << endl;
    }
    cout << "Enter address details:" << endl;
    is >> employee.address;
    cout << "Enter hours worked: ";
    is >> employee.hourWork;
    cout << "Enter salary per hour: ";
    is >> employee.salaryPerHour;
    cout << "Enter work to do: ";
    is >> employee.workToDo;
    cout << "Enter work done: ";
    is >> employee.workDone;
    is.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the remaining newline character
    return is;
}

//Codes for Point and rectangle here:
class Point {
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Copy Constructor
    Point(const Point& other) : x(other.x), y(other.y) {}

    // Getters
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Setters
    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    // Overload +
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload -
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // Overload /=
    Point& operator/=(double divisor) {
        if (divisor == 0) {
            cout<< "cant divide by zero"<<endl;
        }else{
        x /= divisor;
        y /= divisor;
        }
        return *this;
    }

    // Overload =
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    // Overload >= operator (compare distance from (0,0))
    bool operator>=(const Point& other) const {
        double distance1 = sqrt(x * x + y * y);
        double distance2 = sqrt(other.x * other.x + other.y * other.y);
        return distance1 >= distance2;
    }

    // Friend functions
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};

// Overload <<
ostream& operator<<(ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

// Overload >>
istream& operator>>(istream& is, Point& point) {
    cout << "Enter x: ";
    is >> point.x;
    cout << "Enter y: ";
    is >> point.y;
    return is;
}

class Rectangle {
private:
    Point startPoint;
    double width;
    double height;

public:
    // Constructor
    Rectangle(const Point& startPoint, double width, double height)
            : startPoint(startPoint), width(width), height(height) {}

    // Copy Constructor
    Rectangle(const Rectangle& other)
            : startPoint(other.startPoint), width(other.width), height(other.height) {}

    Point getStartPoint() const {
        return startPoint;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setStartPoint(const Point& startPoint) {
        this->startPoint = startPoint;
    }

    void setWidth(double width) {
        this->width = width;
    }

    void setHeight(double height) {
        this->height = height;
    }

    // Overload +=
    Rectangle& operator+=(const Rectangle& other) {
        if (startPoint.getX() != other.startPoint.getX() || startPoint.getY() != other.startPoint.getY()) {
            throw runtime_error("Start points are not equal");
        }else {
            width = max(width, other.width);
            height = max(height, other.height);
        }
        return *this;
    }

    // Overload -=
    Rectangle& operator-=(const Rectangle& other) {
        if (startPoint.getX() != other.startPoint.getX() || startPoint.getY() != other.startPoint.getY()) {
            cout<<("Start points are not equal");
        }else {
            width = min(width, other.width);
            height = min(height, other.height);
            return *this;
        }
    }

    // Overload /
    Rectangle operator/(const Rectangle& other) const {
        Point averageStartPoint((startPoint.getX() + other.startPoint.getX()) / 2,
                                (startPoint.getY() + other.startPoint.getY()) / 2);

        double max_width = max(width, other.width);
        double min_width = min(width, other.width);
        double max_height = max(height, other.height);
        double min_height = min(height, other.height);

        double new_width = max_width / min_width;
        double new_height = max_height / min_height;

        return Rectangle(averageStartPoint, new_width, new_height);
    }

    // Friend functions
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
    friend istream& operator>>(istream& is, Rectangle& rect);
    //
    bool isCollisionDetected(const Rectangle& other) const {
        double thisLeft = startPoint.getX();
        double thisRight = startPoint.getX() + width;
        double thisTop = startPoint.getY();
        double thisBottom = startPoint.getY() + height;
        double otherLeft = other.startPoint.getX();
        double otherRight = other.startPoint.getX() + other.width;
        double otherTop = other.startPoint.getY();
        double otherBottom = other.startPoint.getY() + other.height;
        if (thisRight < otherLeft || otherRight < thisLeft) {
            return false;
        }
        if (thisBottom < otherTop || otherBottom < thisTop) {
            return false;
        }
        return true;
    }

};

// Overload <<
ostream& operator<<(ostream& os, const Rectangle& rect) {
    os << "Start Point: " << rect.startPoint << ", Width: " << rect.width << ", Height: " << rect.height;
    return os;
}

// Overload >>
istream& operator>>(istream& is, Rectangle& rect) {
    cout << "Enter start point details:" << endl;
    is >> rect.startPoint;
    cout << "Enter width: ";
    is >> rect.width;
    cout << "Enter height: ";
    is >> rect.height;
    return is;
}

int main() {
    return 0;
}
