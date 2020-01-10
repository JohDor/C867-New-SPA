/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/

#ifndef ROSTER_HEADER
#define ROSTER_HEADER
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
public:
	Roster();
	void add(string studentID, string firstName, string lastName, string email, int age, int Day1, int Day2, int Day3, Degree degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	~Roster();
	Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	Degree degree = Degree::SECURITY;
};
#endif

// 5.  Call the destructor to release the Roster memory.
// E. 1.  Create an array of pointers, classRosterArray, to hold the data provided in the studentData table.

