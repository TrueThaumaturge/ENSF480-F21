//File Name: Human.h
//Assignment: Lab 1 Exercise D
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#ifndef HUMAN_H
#define HUMAN_H

#include "Point.h"
#include <cstring>
#include <iostream>
using namespace std;

class Human {
    protected:
        Point location;
        char *name;

    public:
        Human(const char* name = "", double x = 0, double y = 0);
        ~Human();
        Human& operator=(const Human& source);
        Human(const Human &source);

        char* get_name() const;
        Point get_point() const;
        void set_name(char* name);
        
        virtual void display();
};

#endif