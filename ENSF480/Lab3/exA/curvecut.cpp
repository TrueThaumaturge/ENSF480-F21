/*
 * File Name: curvecut.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By: Apostolos S, Quentin J
 * Submission Date: 
 */

#include "curvecut.h"

CurveCut::CurveCut(const double x, const double y, const double side_a, const double side_b, 
        const double r, const char* shapeName) 
        : Shape(Point(x, y), shapeName), Rectangle(x, y, side_a, side_b, shapeName), Circle(x, y, r, shapeName)
{
    if(r > side_a || r > side_b) {
        cout << "Error: Radius cannot be greater than one of the sides. Terminating program.";
        exit(1);
    }
}

void CurveCut::display() const {
    cout << "CurveCut Name: " << getName() << endl;
    origin.display();
    cout << "Width: " << side_a << endl;
    cout << "Length: " << side_b << endl;
    cout << "Radius: " << radius << endl;
}