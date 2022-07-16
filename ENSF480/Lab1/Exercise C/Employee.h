//File Name: Employee.h
//Assignment: Lab 1 Exercise C
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    enum State {
            ACTIVE,
            SUSPENDED,
            RETIRED,
            FIRED
        };

    private:
        friend class Company;
        string employeeName;
        string employeeAddress;
        string dateOfBirth;
        State currentState;
};

#endif