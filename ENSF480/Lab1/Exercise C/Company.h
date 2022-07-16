//File Name: Company.h
//Assignment: Lab 1 Exercise C
//Completed by: Quentin Jennings
//Submission Date: Sept. 24, 2021

#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "Customer.h"
#include <string>
#include <vector>
using namespace std;

class Company {
    private:
        string companyName;
        string companyAddress;
        string dateEstablished;
        vector<Employee> employees;
        vector<Customer> customers;
};

#endif