#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <stdexcept>
#include "Point.h"

using namespace std;

class Rectangle {
private:
    Point startPoint;
    double width;
    double height;

public:
    // Constructor
    Rectangle(const Point& startPoint, double width, double height);
    // Copy Constructor
    Rectangle(const Rectangle& other);

    Point getStartPoint() const;
    double getWidth() const;
    double getHeight() const;

    void setStartPoint(const Point& startPoint);
    void setWidth(double width);
    void setHeight(double height);

    // Operator overloads
    Rectangle& operator+=(const Rectangle& other);
    Rectangle& operator-=(const Rectangle& other);
    Rectangle operator/(const Rectangle& other) const;

    // Friend functions
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
    friend istream& operator>>(istream& is, Rectangle& rect);

    // Member functions
    bool isCollisionDetected(const Rectangle& other) const;
};

#endif
