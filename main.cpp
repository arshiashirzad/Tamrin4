#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Address.h"
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main() {
    Address address1("iran", "sari", "farhang");
    Address address2("iran", "rasht", "golsar");
    cout << "Address 1: " << address1 << endl;
    cout << "Address 2: " << address2 << endl;

    Person person1("arshia shirzad", "90trw2345", address1);
    Person person2("reza molaei", "90trw2345", address2);
    cout << "Person 1: " << person1 << endl;
    cout << "Person 2: " << person2 << endl;

    Employee employee1("arshia ", "90trw2345", address1, 160, 25.0, 160, 140);
    Employee employee2("refigh arshia", "90trw2345", address2, 160, 30.0, 160, 150);
    cout << "Employee 1: " << employee1 << endl;
    cout << "Employee 2: " << employee2 << endl;

    Point point1(3.0, 4.0);
    Point point2(1.0, 2.0);
    Point point3 = point1 + point2;
    Point point4 = point1 - point2;
    point1 /= 2.0;
    cout << "Point 1: " << point1 << endl;
    cout << "Point 2: " << point2 << endl;
    cout << "Point 3 (Point 1 + Point 2): " << point3 << endl;
    cout << "Point 4 (Point 1 - Point 2): " << point4 << endl;

    Rectangle rect1(Point(1, 1), 10, 5);
    Rectangle rect2(Point(3, 2), 8, 4);

    try {
        rect1 += rect2;
        cout << "Final rectangle: " << rect1 << endl;
    } catch (const std::runtime_error& e) {
        cerr << e.what() << endl;
    }

    Rectangle rect3 = rect1 / rect2;
    cout << "Divided rectangle: " << rect3 << endl;

    bool collision = rect1.isCollisionDetected(rect2);
    if (collision) {
        cout << "Collision detected!" << endl;
    } else {
        cout << "No collision detected." << endl;
    }

    return 0;
}
