#pragma once
#include "Employee.h"

class GeneralEmployee : public Employee { //derived from Employee class for General Employee type employees

public:

	GeneralEmployee() :Employee("GeneralEmployee") { //default constructor
	}

	GeneralEmployee(string  name, string userName, string password) :Employee(name, password, userName, "GeneralEmployee") { //constructor to add object
	}
	void menu() {  //menu for General Employee type employees
		cout << "1. View Own Employee Record" << endl;
	}
};