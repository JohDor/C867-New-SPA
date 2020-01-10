/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/
#pragma once
#include "networkstudent.h"


//NetworkStudent::NetworkStudent(){}
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degreeProgram)
	:Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeProgram)
{
	this->degreeProgram = Degree::NETWORK;
}
Degree NetworkStudent::getDegreeProgram() { return degreeProgram; }
void NetworkStudent::print()
{
	this->Student::print();
	cout << "Degree:  Network" << endl;
};
	//NetworkStudent::~NetworkStudent(){}
