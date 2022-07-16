//File Name: Point.h
//Assignment: Lab 1 Exercise D
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point{
    private:
        friend class Human;
        double x;     // x coordinate of a location on Cartisian Plane
        double y;     // y coordinate of a location on Cartisian Plane

        Point(double a =0, double b =0);                      
        void set_x(double a);
        void set_y(double a);

    public:
        double get_x()const;                     
        double get_y()const;
};

#endif