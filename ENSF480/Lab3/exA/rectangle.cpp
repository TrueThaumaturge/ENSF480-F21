/*
 * File Name: rectangle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By: Apostolos S, Quentin J
 * Submission Date:
 */

#include "rectangle.h"

//constructor
Rectangle::Rectangle(const double x, const double y, const double side_a, const double side_b, 
    const char* shapeName) : Shape(Point(x, y), shapeName), Square(x, y, side_a, shapeName)
{
    this->side_b = side_b;
}

void Rectangle::display() const {
    cout << "Rectangle Name: " << getName() << endl;
    origin.display();
    cout << "Side a: " << side_a << endl;
    cout << "Side b: " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl; 
}
