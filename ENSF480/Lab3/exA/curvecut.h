/*
 * File Name: curvecut.h
 * Assignment: Lab 3 Exercise A
 * Completed By: Apostolos S, Quentin J
 * Submission Date: 
 */

#ifndef CURV_H
#define CURV_H

#include "circle.h"
#include "rectangle.h"
#include <iostream>
using namespace std;

//child of Shape, represents a circle with a radius
class CurveCut : public Rectangle, public Circle
{
    public:
        //constructor
        CurveCut(const double x, const double y, const double side_a, const double side_b,
                const double r, const char* shapeName);
        // REQUIRES: shapeName points to the first character of a c-string
        // PROMISES: initializes curvecut with the passed in values

        virtual double area() const { return Rectangle::area() - Circle::area() / 4; }
        // PROMISES: returns area of curvecut

        virtual double perimeter() const { return Rectangle::perimeter() - 2 * radius + Circle::perimeter() / 4; }
        // PROMISES: returns perimeter of curvecut

        virtual void display() const;
        // PROMISES: displays circle name, x/y coords, side_a, side_b, radius, area and perimeter
};

#endif
