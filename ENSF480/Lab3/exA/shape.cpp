/*
 * File Name: shape.cpp
 * Assignment: Lab 2 Exercise A
 * Completed By: Beau McCartney, Quentin Jennings
 * Submission Date: September 30th, 2021
 */

#include "shape.h"

//constructor
Shape::Shape(const Point origin, const char *shapeName) :
    origin(origin), shapeName(new char[strlen(shapeName) + 1])
{
    strcpy(this->shapeName, shapeName);
}

//assignment operator
Shape& Shape::operator=(const Shape& s) {
    if(this != &s) {
        origin = Point(s.getOrigin().getX(), s.getOrigin().getY());
        shapeName = new char[strlen(s.getName() + 1)];
        strcpy(shapeName, s.getName());
    }
    return *this;
}

//copy constructor
Shape::Shape(const Shape& s) : 
    origin(Point(s.getOrigin().getX(), s.getOrigin().getY())) 
{
    shapeName = new char[strlen(s.getName() + 1)];
    strcpy(shapeName, s.getName());
}

//displays the shape name and coordinates of its origin
void Shape::display() const {
    cout << "Shape Name: " << shapeName << endl;
    origin.display();
}

double Shape::distance(Shape& other) const {
    return Point::distance(this->origin, other.origin);
}

double Shape::distance(Shape& the_shape, Shape& other) {
    return Point::distance(the_shape.getOrigin(), other.getOrigin());
}

void Shape::move(double dx, double dy) {
    origin.x += dx;
    origin.y += dy;
}
