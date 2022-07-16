//File Name: Point.cpp
//Assignment: Lab 1 Exercise D
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#include "Point.h"

Point::Point(double a, double b): x(a), y(b) {}          

void Point::set_x(double a) { 
    x = a;
}

void Point::set_y(double a) {
    y = a;
}

double Point::get_x()const {
    return x;
}     

double Point::get_y()const {
    return y;
} 