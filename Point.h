#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x = 0, double y = 0);
    // Copy Constructor
    Point(const Point& other);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    // Operator overloads
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point& operator/=(double divisor);
    Point& operator=(const Point& other);
    bool operator>=(const Point& other) const;

    // Friend functions
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};

#endif
