/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise A
 * Completed By: Apostolos S, Quentin J
 * Submission Date: 
 */

#ifndef CIRC_H
#define CIRC_H

#include "shape.h"
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846264338327950288; //pi

//child of Shape, represents a circle with a radius
class Circle : virtual public Shape {
    protected:
        double radius;

    public:
        //constructor
        Circle(const double x, const double y, const double r, const char* shapeName);
        // REQUIRES: shapeName points to the first character of a c-string
        // PROMISES: initializes circle with the passed in values

        double area() const { return PI * radius * radius; }
        // PROMISES: returns area of circle

        double perimeter() const { return 2 * PI * radius; }
        // PROMISES: returns perimeter of circle

        //getters/setters
        double get_radius() const { return radius; }
        // PROMISES: returns radius

        void display() const;
        // PROMISES: displays circle name, x/y coords, radius, area and perimeter
};

#endif
