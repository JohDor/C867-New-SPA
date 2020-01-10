/*C867 - Scripting and Programming Applications
Ryl Johann Lolor Dorado
Student ID:  001231016
C++*/

#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Roster::Roster(){}

//E.3.a. add
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int Day1, int Day2, int Day3, Degree degreeProgram)
{
	int numDays[] = { Day1, Day2, Day3 };
	Student* student = nullptr;
		if (degreeProgram == Degree::SECURITY) { student = new SecurityStudent(studentID, firstName, lastName, email, age, numDays, degreeProgram); }
		else if (degreeProgram == Degree::NETWORK) { student = new NetworkStudent(studentID, firstName, lastName, email, age, numDays, degreeProgram); }
		else { student = new SoftwareStudent(studentID, firstName, lastName, email, age, numDays, degreeProgram); }
		for (int i = 0; i < 5; i++) 
		{
			if (classRosterArray[i] == nullptr) 
			{
				classRosterArray[i] = student;
				break;
			}
		}
}

//E.3.c. printAll()
void Roster::printAll()
{
	for (unsigned int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}
	}
}

// E.3.e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user
void Roster::printInvalidEmails()
{
	cout << "\n" << "Invalid emails:" << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		string email = classRosterArray[i]->getEmailAddress();
		if ((email.find("@")) == -1 || (email.find(".")) == -1 || (email.find(" ")) == 1)
		{
			cout << email << "\n";
		}
		//break;	
	}
	cout << endl;
}

// E.3.d.  public void printDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) 
{  
	for (unsigned int i = 0; i < 5; i++) 
	{ 
		if (studentID == classRosterArray[i]->getStudentID()) 
		{ 
			int total = ((classRosterArray[i]->getNumberOfDays()[0]) + (classRosterArray[i]->getNumberOfDays()[1]) + (classRosterArray[i]->getNumberOfDays()[2]));
			cout << "Average number of days for " << classRosterArray[i]->getStudentID() << " is " << (total / 3) << " days." << "\n" << endl; 
			break; 
		} 
	} 
}

// E.3.F. public void printByDegreeProgram(int degreeProgram) that prints out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(Degree degreeProgram) 
{ 
	for (unsigned int i = 0; i < 5; i++)
	{ 
			if (degreeProgram == classRosterArray[i]->getDegreeProgram())
			{
				cout << "Printing by degree program:  " << endl;
				classRosterArray[i]->print();
			}
	} 
	cout << endl;
}

//E.3.b. remove
// { bool rem = false; for (int i = 0; i <= 5; i++) { if (classRosterArray[i]) { if (studentID == classRosterArray[i]->getStudentID()) { classRosterArray[i] = nullptr; rem = true; }}break; } if (!rem) { cout << "Student does not exist." << endl; } }
void Roster::remove(string studentID)
{
	bool remove = false;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (studentID == classRosterArray[i]->getStudentID())
			{
				remove = true;
				if (remove == true)
				{
					classRosterArray[i] = nullptr;
					cout << "Student ID " << studentID << " removed." << endl;
				}
			}
		}
		//break; 
	}
	if (!remove)
	{
		cout << "Student with ID was not found." << "\n" << endl;
	}
}

Roster::~Roster(){}

int main() {
	cout << "\n" << "C867 - Scripting and Programming Applications" << "\n" << "C++\n" << "#001231016\n" << "Ryl Johann Dorado\n" << endl;

	// 3.  Add each student to classRoster.
	// a.  Apply pointer operations when parsing each  set of data identified in the studentData table.
	// b.  Add each student object to classRosterArray.
	const string studentData[5] = 
	{
	"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ryl Johann,Dorado,rdorad5@wgu.edu,24,6,6,1,SOFTWARE" 
	};

	Roster classRoster;
	string output;
	string section[9];
	Degree theirDegree{};
	for (int i = 0; i < 5; i++)
	{
		istringstream input(studentData[i]);
		for (int j = 0; j < 9; j++)
		{
			getline(input, output, ',');
			section[j] = output;
			//use switch or if statements to set degree program to correct value using the section array 
			if (section[8] == "SECURITY")
			{
				theirDegree = Degree::SECURITY;
			}
			else if (section[8] == "NETWORK")
			{
				theirDegree = Degree::NETWORK;
			}
			else if (section[8] == "SOFTWARE")
			{
				theirDegree = Degree::SOFTWARE;
			}
			//cout << section[j] << "\t";
		}
		classRoster.add(section[0], section[1], section[2], section[3], stoi(section[4]), stoi(section[5]), stoi(section[6]), stoi(section[7]), theirDegree);
	}

	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printAverageDaysInCourse("A1");			
	classRoster.printByDegreeProgram(Degree::SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.
	system("PAUSE");
	return 0;
};

/* unused outside int main
	#include <regex>
	
	//Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ').
	//		if (email.find("@")) { bool valid = true; if (email.find(".")) { bool valid = true; if (email.find(" ")) { bool valid = false; cout << classRosterArray[i]->getEmailAddress(); } break; } } 
	//This regex should have the required ones, hopefully it works since I didn't include any spaces " "
	/*const std::regex valid ("[a-zA-Z0-9-_*]+@+[a-zA-Z0-9*]+[\.]+[a-zA-Z0-9]"); bool invalid(const std::string &email);{ std::smatch match; while (regex_search(email, match, valid)) { while (bool invalid = false) { classRosterArray[i]->print(); }; }} break;}}

	//void Roster::printByDegreeProgram(int degreeProgram) { for (int degreeProgram = 0; degreeProgram < 5; degreeProgram++) { classRosterArray[degreeProgram]->getDegreeProgram(); classRosterArray[degreeProgram]->print(); break;}}

	//F.4.g.
	//Roster::~Roster() {} - F.4.f. says in "int main"
	//3.
*/	