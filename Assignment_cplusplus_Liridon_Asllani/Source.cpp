/*The program will implement an employee management infromation system
The program uses classes for the three different types of employees
and an Employee class towhich the other three classes are derived from
Sample data in the EmployeeData.txt file will be used for the program
The user will be asked to input a username and password
Based on the employee typ, they will see the corresponding menu
The program will stop after displaying the menu
Vector of Employee objects will be used to store the employee data
*/

#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HumanResource.h"
#include "Management.h"
#include "GeneralEmployee.h"
using  namespace std;

void filler(vector<Employee*>&); //declare filler function. Create function below main
void display(vector<Employee*>&);//declare display function. Create function below main
void login(vector<Employee*>&);//declare login function. Create function below main

int main() {
	vector<Employee*> empCensus; //create vector to save Employee objects

	filler(empCensus);
	display(empCensus);
	login(empCensus);
	return 0;
}

void filler(vector<Employee*>& empCensus) { //function that populates the vector from txt file

	ifstream fileIn("EmployeeData.txt"); //file with employee data
	
	while (!fileIn.eof()) {              //condition to keep iterating while it's not at the end of the file      
		
		string name, userName, password, type;

		getline(fileIn, name, ','); //get name from file object. Delimeter is a comma
		getline(fileIn, userName, ','); //get userName from file object. Delimeter is a comma
		getline(fileIn, password, ','); //get password from file object. Delimeter is a comma
		getline(fileIn, type); //get type from file object. Delimeter is a new line

		if (type == "HumanResource") { //if type is HumanResource, save it as a HumanResource Object
			HumanResource* HR = new HumanResource(name, userName, password); //create human resource object
			empCensus.push_back(HR); //add it to the empCensus vector
		}
		else if (type == "Management") {//if type is HumanResource, save it as a Management Object
			Management* Mgmt = new Management(name, userName, password);  //create Management object
			empCensus.push_back(Mgmt); //add it to the empCensus vector
		}
		else if (type == "GeneralEmployee") { //if type is GeneralEmployee, save it as a General Employee Object
			GeneralEmployee* GE = new GeneralEmployee(name, userName, password);//Create General EMployee object
			empCensus.push_back(GE); //add it to the empCensus vector
		}
	}
}

void display(vector<Employee*>& empCensus) { //function to display the empCensus
	
	cout << "----BELOW IS THE SAMPLE DATA USED FOR THE PROGRAM----" << endl;
	cout << "-------------------Employee Display------------------" << endl;
	
	for (int x = 0; x < empCensus.size(); x++) { //iterate through empCensus vector
		empCensus[x]->display(); //call Employee class function
		cout << "-----------------------------------------------------" << endl << endl; //formatting line
	}
}



void login(vector<Employee*>& empCensus) { //function to ask for employee login
	
	string userName, password; //initialize variables for input
	char userDecision = 'Y'; //variable to control the while loop
	char* decisionPointer = &userDecision; //pointer to change the value of while loop control variable inside the loop
	
	cout << "--------------------------Employee Management System--------------------" << endl;
	
	while (*decisionPointer == 'Y') {
		
		cout << "Username:"; //ask user for user name
		cin >> userName; // save username
		
		for (int x = 0; x < empCensus.size(); x++) { //iterate through empCensus vector to see if username matches
			
			if (empCensus[x]->getUserName() == userName) {//call Employee class function to validate username and if true, ask for password
				cout << "Password:"; //ask for password
				cin >> password; //save password to variable
				
				if (empCensus[x]->getPassword() == password) {//call Employee class function to validate password. If correct, provide menu based on employee type
					cout << "--------------------------------------Menu---------------------------------" << endl;
					
					if (empCensus[x]->getEmployeeType() == "HumanResource"){ //if employee is human resources type, then display the human resource menu
						HumanResource().menu(); //function in human resource to display human resource menu
						*decisionPointer = 'N'; //change while loop pointer to 'N' so that the while loop stops
					}
					
					else if (empCensus[x]->getEmployeeType() == "Management") {//if employee is Management type, then display the human resource menu
						Management().menu();// function in Management class to display Management menu
						*decisionPointer = 'N'; //change while loop pointer to 'N' so that the while loop stops
					}
					
					else {
						GeneralEmployee().menu(); //function in General Employee class to display menu
						*decisionPointer = 'N'; //change while loop pointer to 'N' so that the while loop stops
					}
					
					*decisionPointer = 'N'; //change while loop pointer to 'N' so that the while loop stops
					break; 
				}
			}
			
			else if (x < empCensus.size()) { // continue iterating through the class
				continue;
			}
			
			else { // if the information is not correct after mutliple wrong entries, then the user will be asked if they want to continue or exit the program
				cout << "Either your usernam or password were incorrect. Please note that both are case sensetive." << endl;
				cout << "Please enter Y if you would like to proceed or anything else if you would like to exit:" << endl;
				string answer;
				cin >> answer;
				
				if (answer != "Y") // if anything other than Y is entered, then implement the block
				{
					exit(0); // exit function
				}
				
				else {
					break;
				}
			}
		}
	}
}