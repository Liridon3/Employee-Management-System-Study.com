#pragma once
#include "Employee.h"

class HumanResource : public Employee { //derived from Employee class for Human Resource type employees

public:
	
	HumanResource() : Employee("HumanResource") { //default constructor
	}

	HumanResource(string name, string userName, string password) : Employee(name, password, userName, "HumanResource") { //constructor to add object
	}

	void menu() { //menu for Human Resource type employees
		cout << "1. Add Employee Record" << endl;
		cout << "2. View Employee Record" << endl;
		cout << "3. Search Employees" << endl;
		cout << "4. Modify Employee Record" << endl;
		cout << "5. Delete Employee Record" << endl;
	}
};