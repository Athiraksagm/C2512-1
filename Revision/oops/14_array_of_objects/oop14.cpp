/*
Array of Objects
Task: Write a program to store details of 5 employees using an array of objects of class Employee. 
 */

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Function to input employee details
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // To consume the newline character left by `cin`
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main() {
    const int numEmployees = 5; // Number of employees
    Employee employees[numEmployees]; // Array of Employee objects

    // Input details for each employee
    cout << "Enter details of " << numEmployees << " employees:" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        employees[i].inputDetails();
        cout << endl;
    }

    // Display details of each employee
    cout << "Details of Employees:" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        employees[i].displayDetails();
        cout << endl;
    }

    return 0;
}

