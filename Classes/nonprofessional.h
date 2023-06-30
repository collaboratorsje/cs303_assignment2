#pragma once
#include "employee.h"

// Declares and defines nonprofessional class
class Nonprofessional : public Employee {
    private:
        // private data members
        double hourlyRate;
        int hoursWorked;
        int vacationHours;

    public:
        // constructor
        Nonprofessional(const string& name, double hourlyRate, int hoursWorked, int vacationHours)
        : Employee(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked), vacationHours(vacationHours) {}

        // finds pay per week with hourly wage * hours worked
        double CalcWeeklySalary() const {
            return hourlyRate * hoursWorked;
        }
        // finds HCC with 6% of weekly salary
        double CalcHealthcareContribution() const {
            return CalcWeeklySalary() * .06;
        }
        // finds Vacation days by awarding 6 hours vacation per 80 hours worked
        double CalcVacationDays() const {
            // finds % of 80 hours worked and multiplies it by 6 to give hours
            // divides by 24 to convert to days
            return ((static_cast<double> (hoursWorked) / 80) * 6) / 24;
        }
};