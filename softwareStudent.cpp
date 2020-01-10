/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/
#pragma once
#include "softwareStudent.h"

//SoftwareStudent::SoftwareStudent(){}
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degreeProgram)
	:Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeProgram)
{
	this->degreeProgram = Degree::SOFTWARE;
}
Degree SoftwareStudent::getDegreeProgram() { return degreeProgram; }
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "Degree:  Software" << endl;
};
//SoftwareStudent::~SoftwareStudent(){}
