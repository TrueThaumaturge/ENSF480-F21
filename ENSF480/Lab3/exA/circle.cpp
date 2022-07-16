/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By: Apostolos S, Quentin J
 * Submission Date: 
 */

#include "circle.h"

//constructor
Circle::Circle(const double x, const double y, const double r, const char* shapeName)
    : Shape(Point(x,y), shapeName)
{
    this->radius = r;
}

void Circle::display() const {
    cout << "Circle Name: " << getName() << endl;
    origin.display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl; 
}