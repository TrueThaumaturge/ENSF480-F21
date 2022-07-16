//File Name: Human.cpp
//Assignment: Lab 1 Exercise D
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#include "Human.h"

Human::Human(const char* name, double x, double y) {
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    location = Point(x, y);
}

Human::~Human() {
    delete [] name;
}

Human& Human::operator=(const Human& source){
    delete [] name;
    name = new char[strlen(source.get_name()) + 1];
    strcpy(name, source.get_name());

    location.set_x(source.get_point().get_x());
    location.set_y(source.get_point().get_y());
    return *this;
}

Human::Human(const Human &source){
    name = new char[strlen(source.get_name()) + 1];
    strcpy(name, source.get_name());
    location.set_x(source.get_point().get_x());
    location.set_y(source.get_point().get_y());
}

char* Human::get_name() const {return name;}

void Human::set_name(char* name) {
    delete [] name;
    this -> name = new char [strlen(name) + 1];
    strcpy (this -> name, name);
}

Point Human::get_point() const {return location;}

void Human::display() {
    cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << ", "
        << location.get_y() << ".\n" << endl;
}