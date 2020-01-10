/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/

#ifndef SECURITY_HEADER
#define SECURITY_HEADER
#include "student.h"
#include "degree.h"

/*  3.  Create the three following classes as subclasses of Student, using the files created in part B:
•   SecurityStudent 
Each subclass should override the getDegreeProgram() function. Each subclass should have a data member to
hold the enumerated type for the degree program using the types defined in part C.
*/
class SecurityStudent : public Student {
public:
//	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int * numberOfDays, Degree degreeProgram);
	Degree getDegreeProgram() override;
	void print() override;
	//~SecurityStudent();

private:
	Degree degreeProgram;
};
#endif