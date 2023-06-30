#pragma once
#include "employee.h"
// Declares and defines professional class
class Professional : public Employee {
    private:
        double monthlySalary;
        int vacationDays;

    public:
        // Class constructor
        Professional(const string& name, double monthlySalary, int vacationDays)
        : Employee(name), monthlySalary(monthlySalary), vacationDays(vacationDays) {}
        // finds weekly salaray by dividing monthly salary by 4
        double CalcWeeklySalary() const {
            return monthlySalary / 4;
        }
        // finds HCC by taking 6% of the monthly salary
        double CalcHealthcareContribution() const {
            return monthlySalary * .06;
        }
        // vacation days are an input parameter to the class constructor 
        // So this is basically just a getter function
        double CalcVacationDays() const {
            return vacationDays;
        }

};