/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/
#pragma once
#include "securityStudent.h"

//SecurityStudent::SecurityStudent(){}
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degreeProgram)
	:Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeProgram)
{
	this->degreeProgram = Degree::SECURITY;
}
Degree SecurityStudent::getDegreeProgram() { return degreeProgram; }
void SecurityStudent::print()
{
	this->Student::print();
	cout << "Degree:  Security" << endl;
};
//SecurityStudent::~SecurityStudent(){}
