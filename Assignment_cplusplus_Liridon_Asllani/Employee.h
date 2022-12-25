#pragma once
using  namespace std;

class Employee { //create employee class for all employees

private: //attributes as private. Use constructors to access attributes.
	
	string name;
	string password;
	string userName;
	string employeeType;


public:

	Employee(string employeeType) { //default constructor
		this->name = "";
		this->password = "";
		this->userName = "";
		this->employeeType = employeeType;
	}

	Employee(string name, string password, string userName, string  employeeType) { //constructor to add employee objects
		this->name = name;
		this->employeeType = employeeType;
		this->userName = userName;
		this->password = password;
	}

	void setName(string name) { //constructor to set the name of the object
		this->name = name;
	}

	string getName() { //constructor to access the name of the object
		return this->name;
	}

	void setPassword(string password) { //constructor to set the password of the object
		this->password = password;
	}

	string getPassword() { //constructor to access the password of the object
		return this->password;
	}
	void setUserName(string userName) { //constructor to set the userName of the object
		this->userName = userName;
	}

	string getUserName() { //constructor to access the userName of the object
		return this->userName;
	}
	void setEmployeeType(string employeeType) { //constructor to set the employeeType of the object
		this->employeeType = employeeType;
	}
	string getEmployeeType() { //constructor to access the employeeType of the object
		return this->employeeType;
	}

	void display() { //function that is used to display the employee data in the program
		cout << "Type    : " << this->getEmployeeType() << endl
			<< "Name    : " << this->getName() << endl
			<< "password: " << this->getPassword() << endl
			<< "user Id : " << this->getUserName() << endl;
	}

	void validateUserName() { //function that is used in the source file as part of the userName validation function
		this->getUserName();
	}
};