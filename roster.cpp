#include "roster.h"
#include "degree.h"
#include "student.h"
#include "networkstudent.h"
#include "securitystudent.h"
#include "softwarestudent.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Roster::Roster()
{

}


void Roster::add(string sID, string fName, string lName, string eADD, int age, int nDays0, int nDays1, int nDays2, Degree degreeProgram)
{
	int nDays[] = { nDays0, nDays1, nDays2 };

	for (int i = 0; i < 5; i++) 
	{
			switch (degreeProgram)
			{
			case Degree::SECURITY:
				classRosterArray[i] = new SecurityStudent(sID, fName, lName, eADD, age, nDays, degreeProgram);
				break;
			case Degree::NETWORK:
				classRosterArray[i] = new NetworkStudent(sID, fName, lName, eADD, age, nDays, degreeProgram);
				break;
			case Degree::SOFTWARE:
				classRosterArray[i] = new SecurityStudent(sID, fName, lName, eADD, age, nDays, degreeProgram);
				break;
			default:
				cout << "ERROR: Degree Progam was not found." << endl;
				break;
			}
			index++;
	}
}

void Roster::remove(string studentID)
{
	bool sidremoved = false;
	for (int i = 0; i < 5; i++) 
	{
		if (classRosterArray[i] != nullptr)
		{
			if (studentID == classRosterArray[i]->getStudentID()) 
			{
				classRosterArray[i] = nullptr; sidremoved = true;
				cout << "Student " << studentID << " has been removed." << endl;
				break;
			}
		}
	}
	if (sidremoved != true) 
	{
		cout << "ERROR: Student with ID: " << studentID << " was not found." << endl;
	}
}

void Roster::printAll()
{
	cout << "Class Roster: " << endl << endl;
	for (int i = 0; i < 5; i++) 
	{
		(*classRosterArray[i]).print();		
	}
}

void Roster::printAvgDays(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*classRosterArray[i]).getStudentID() == studentID) 
		{
			int avgDays = 0;
			avgDays = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "The average number of days Student " << studentID << " spent in the three courses: "
				<< avgDays << endl << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < 5; i++)
	{
		string email = (*classRosterArray[i]).getEmailADD();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) 
		{
			cout << email << " is not a valid email address." << endl << endl;
		}
	}
}

void Roster::printByDegreeProgram(string degreeProgram)
{
	Degree dProgram = Degree::SOFTWARE;

	if (degreeProgram == "SECURITY")
	{
		dProgram = Degree::SECURITY;
		cout << "Students in Security Degree Program: " << endl;
	}

	if (degreeProgram == "NETWORK")
	{
		dProgram = Degree::NETWORK;
		cout << "Students in Network Degree Program: " << endl;
	}

	if (degreeProgram == "SOFTWARE")
	{
		dProgram = Degree::SOFTWARE;
		cout << "Students in Software Degree Program: " << endl << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		if (dProgram == (*classRosterArray[i]).getDegreeProgram())
		{
			(*classRosterArray[i]).print();
		}
	}
}

int main() 
{
	cout << "\tC867 - Scripting and Programming - Applications" << endl;
	cout << "\t\tLanguage: C++" << endl;
	cout << "\t\tJessica Fleming" << endl;
	cout << "\t\tID#: 000616694" << endl << endl;

	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

	"A5,Jessica,Fleming,jflem28@wgu.edu,32,20,45,29, SOFTWARE"
	};

	Roster classRoster;
	Degree dProgram;

	for (int i = 0; i < 5; i++) 
	{
		stringstream ss(studentData[i]);

		vector<string> stData;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			stData.push_back(substr);
		}
		if (stData[8] == "SECURITY") {
			dProgram = Degree::SECURITY;
		}
		if (stData[8] == "SOFTWARE") {
			dProgram = Degree::SOFTWARE;
		}
		if (stData[8] == "NETWORK") {
			dProgram = Degree::NETWORK;
		}
		classRoster.add(stData[0], stData[1], stData[2], stData[3], stoi(stData[4]), stoi(stData[5]),
			stoi(stData[6]), stoi(stData[7]), dProgram);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAvgDays("A1");

	classRoster.printByDegreeProgram("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3");

	return 0;
}

Roster::~Roster() 
{

}
