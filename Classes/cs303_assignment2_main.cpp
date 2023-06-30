#include "cs303_assignment2.h"
#include "employee.h"
#include "professional.h"
#include "nonprofessional.h"

int main() {
    // The program has cout statements telling the user what is happening in the program
    cout << "Creating professional object named Seth..." << endl;
    cout << "Creating nonprofessional object named James..." << endl;

    cout << "\nCalling all three functions for Seth..." << endl;
    // Creates professional object Seth
    Professional Seth = Professional("Seth", 4500, 30);
    // Calls the functions
    cout << "Seth's healthcare contribution = " << Seth.CalcHealthcareContribution() << endl; 
    cout << "Seth's vacation days = " << Seth.CalcVacationDays() << endl; 
    cout << "Seth's weekly salary = " << Seth.CalcWeeklySalary() << endl;

    cout << "\nCalling all three functions for James..." << endl;
    // Creates nonprofessional object James
    Nonprofessional James = Nonprofessional("James", 40, 80, 10);
    // Calls the functions
    cout << "James' healthcare contribution = " << James.CalcHealthcareContribution() << endl; 
    cout << "James' healthcare contribution = " << James.CalcVacationDays() << endl; 
    cout << "James' healthcare contribution = " << James.CalcWeeklySalary() << endl;

    cout << "Exiting ..." << endl;
}