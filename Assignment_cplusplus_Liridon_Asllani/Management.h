#pragma once
#include "Employee.h"

class Management : public Employee { //derived from Employee class for Management type employees

public:

	Management() : Employee("Management") { //default constructor
	}

	Management(string name, string userName, string password) : Employee(name, password, userName, "Management") { //constructor to add object
	}

	void menu() { //menu for Management type employees
		cout << "1. View Employee Record" << endl;
		cout << "2. Search Employees" << endl;
		cout << "3. View Own Employee Record" << endl;
	}
};