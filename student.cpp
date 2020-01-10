/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/

#include <iostream>
#include<string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree)
{
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	numberOfDays[0] = numDays[0];
	numberOfDays[1] = numDays[1];
	numberOfDays[2] = numDays[2];
}

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getNumberOfDays() { return this->numberOfDays; }
//Degree Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDegrees(Degree degree) { Degree degreeProgram = degree; }
void Student::setNumDays(int* numberOfDays) { for (int i = 0; i < 3; i++) this->numberOfDays[i] = 0; }
void Student::print()
{
	cout << "Student ID:  " << getStudentID() << "\t" << "First Name:  " << getFirstName() << "\t" << "Last Name:  " << getLastName() << "\t" << "Email:  " << getEmailAddress() << endl;
	cout << "Age:  " << getAge() << "\t" << "Days in course:  " << getNumberOfDays()[0] << " " << getNumberOfDays()[1] << " " << getNumberOfDays()[2] << " " << "\t";
	//cout << "Degree:  ";
	/*switch (getDegreeProgram()) 
	{
		case Degree::SECURITY: cout << "SECURITY" << endl; break;
		case Degree::NETWORK: cout << "NETWORK" << endl; break;
		case Degree::SOFTWARE:  cout << "SOFTWARE" << endl; break;
	}*/
}

Student::~Student() {}