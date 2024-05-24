#include "Point.h"
#include <cmath>

// Constructor
Point::Point(double x, double y)
        : x(x), y(y) {}

// Copy Constructor
Point::Point(const Point& other)
        : x(other.x), y(other.y) {}

double Point::getX() const {
    return x;
}
double Point::getY() const {
    return y;
}
void Point::setX(double x) {
    this->x = x;
}
void Point::setY(double y) {
    this->y = y;
}

// Overload +
Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

// Overload -
Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

// Overload /=
Point& Point::operator/=(double divisor) {
    if (divisor == 0) {
        cout << "Error: Division by zero" << endl;
    } else {
        x /= divisor;
        y /= divisor;
    }
    return *this;
}

// Overload =
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Overload >= operator (compare distance from (0,0))
bool Point::operator>=(const Point& other) const {
    double distance1 = sqrt(x * x + y * y);
    double distance2 = sqrt(other.x * other.x + other.y * other.y);
    return distance1 >= distance2;
}

// Friend functions
ostream& operator<<(ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& point) {
    cout << "Enter x: ";
    is >> point.x;
    cout << "Enter y: ";
    is >> point.y;
    return is;
}
