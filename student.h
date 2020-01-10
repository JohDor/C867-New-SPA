/*
C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++
*/


#ifndef STUDENT_HEADER
#define STUDENT_HEADER
#include"degree.h"
#include<iostream>
#include<string>
using namespace std;


class Student {    
public:
	// 2.c.  constructor using all  of the input parameters provided in the table
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* numberOfDays, Degree degree);

	// Note : All accessand changes to the instance variables of the Student class should be done through the accessorand mutator functions.
    //accessor(i.e., getter) 2.a.  an accessor (i.e., getter) for each  instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int *getNumberOfDays();
	// 2.f.  virtual getDegreeProgram()
	// Note: Leave the implementation of the getDegreeProgram() function empty.
	virtual Degree getDegreeProgram() = 0;

    
    //2.b.  a mutator (i.e., setter) for each instance variable from part D1
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
	void setNumDays(int *numberOfDays);
    void setDegrees(Degree degree);
    
    // 2.d.  virtual print() to print specific student data
    virtual void print() = 0;
    
    // 2.e.  destructor
    ~Student();

	/*1.  Create the base class Student in the files student.h and student.cpp, which includes each  of the following variables :
•   student ID
•   first name
•   last name
•   email address
•   age
•   array of number of days to complete each course
•   degree types
*/
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age = -1;
	int numberOfDays[3] = {0, 0, 0};
	Degree degreeProgram;
};
#endif