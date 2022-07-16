//File Name: Customer.h
//Assignment: Lab 1 Exercise C
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
    private:
        friend class Company;
        friend class Employee;
        string customerName;
        string customerAddress;
        string customerPhone;
};

#endif