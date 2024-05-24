#include "Rectangle.h"
#include <stdexcept>

// Constructor
Rectangle::Rectangle(const Point& startPoint, double width, double height)
        : startPoint(startPoint), width(width), height(height) {}

// Copy Constructor
Rectangle::Rectangle(const Rectangle& other)
        : startPoint(other.startPoint), width(other.width), height(other.height) {}

Point Rectangle::getStartPoint() const {
    return startPoint;
}
double Rectangle::getWidth() const {
    return width;
}
double Rectangle::getHeight() const {
    return height;
}
void Rectangle::setStartPoint(const Point& startPoint) {
    this->startPoint = startPoint;
}
void Rectangle::setWidth(double width) {
    this->width = width;
}
void Rectangle::setHeight(double height) {
    this->height = height;
}

// Overload +=
Rectangle& Rectangle::operator+=(const Rectangle& other) {
    if (startPoint.getX() != other.startPoint.getX() || startPoint.getY() != other.startPoint.getY()) {
        throw std::runtime_error("Start points are not equal");
    }
    width = std::max(width, other.width);
    height = std::max(height, other.height);
    return *this;
}

// Overload -=
Rectangle& Rectangle::operator-=(const Rectangle& other) {
    if (startPoint.getX() != other.startPoint.getX() || startPoint.getY() != other.startPoint.getY()) {
        throw std::runtime_error("Start points are not equal");
    }
    width = std::min(width, other.width);
    height = std::min(height, other.height);
    return *this;
}

// Overload /
Rectangle Rectangle::operator/(const Rectangle& other) const {
    Point averageStartPoint((startPoint.getX() + other.startPoint.getX()) / 2.0,
                            (startPoint.getY() + other.startPoint.getY()) / 2.0);

    double max_width = std::max(width, other.width);
    double min_width = std::min(width, other.width);
    double max_height = std::max(height, other.height);
    double min_height = std::min(height, other.height);

    double new_width = max_width / min_width;
    double new_height = max_height / min_height;

    return Rectangle(averageStartPoint, new_width, new_height);
}

// Overload <<
std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Start Point: " << rect.startPoint << ", Width: " << rect.width << ", Height: " << rect.height;
    return os;
}

// Overload >>
std::istream& operator>>(std::istream& is, Rectangle& rect) {
    std::cout << "Enter start point details:" << std::endl;
    is >> rect.startPoint;
    std::cout << "Enter width: ";
    is >> rect.width;
    std::cout << "Enter height: ";
    is >> rect.height;
    return is;
}

// Collision detection
bool Rectangle::isCollisionDetected(const Rectangle& other) const {
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
