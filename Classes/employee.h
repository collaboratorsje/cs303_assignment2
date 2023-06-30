#pragma once
#include "cs303_assignment2.h"

// Declares and defines abstract employee class with virtual functions
class Employee {
    protected:
        string name;
    public:
        Employee(const string& name) : name(name) {}

        virtual double CalcWeeklySalary() const = 0;
        virtual double CalcHealthcareContribution() const = 0;
        virtual double CalcVacationDays() const = 0;

        virtual ~Employee() {}
};