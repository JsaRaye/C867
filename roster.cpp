#include "roster.h"
#include "degree.h"
#include "student.h"
#include "softwarestudent.h"
#include "securitystudent.h"
#include "networkstudent.h"
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
	int numDays[3] = {nDays0, nDays1, nDays2};

	for (int i = 0; i < 5; i++) 
	{
			switch (degreeProgram)
			{
			case Degree::SECURITY:
				classRosterArray[i] = new SecurityStudent(sID, fName, lName, eADD, age, numDays, degreeProgram);
				break;
			case Degree::NETWORK:
				classRosterArray[i] = new NetworkStudent(sID, fName, lName, eADD, age, numDays, degreeProgram);
				break;
			case Degree::SOFTWARE:
				classRosterArray[i] = new SecurityStudent(sID, fName, lName, eADD, age, numDays, degreeProgram);
				break;
			default:
				cout << "ERROR: Entered Degree Progam was not found." << endl;
				break;
			}
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
	cout << "Student Roster: " << endl << endl;
	for (int i = 0; i < 5; i++) 
	{	
		(*classRosterArray[i]).print();	
	}

	cout << endl;
}

void Roster::printAvgDays(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*classRosterArray[i]).getStudentID() == studentID) 
		{
			int avg = 0;
			avg = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "The average number of days Student " << studentID << " spent in the three courses: "
				<< avg << endl << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < 5; i++)
	{
		string email = "";
		email = (*classRosterArray[i]).getEmailADD();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) 
		{
			cout << "Invalid email address(es) include the following: " << email << endl << endl;
		}
	}
}

void Roster::printByDegreeProgram(string degreeProgram)
{
	Degree tempDegree = Degree::SOFTWARE;
	if (degreeProgram == "SECURITY") 
	{
		tempDegree = Degree::SECURITY;
		cout << "Students in Security Degree Program: " << endl;
	}
	if (degreeProgram == "NETWORK")
	{
		tempDegree = Degree::NETWORK;
		cout << "Students in Network Degree Program: " << endl;
	}
	if (degreeProgram == "SOFTWARE")
	{
		tempDegree = Degree::SOFTWARE;
		cout << "Students in Software Degree Program: " << endl << endl;
	}

	for (int i = 0; i < 5; i++) 
	{
		if (tempDegree == (*classRosterArray[i]).getDegreeProgram()) 
		{
			(*classRosterArray[i]).print();
		}
	}
	cout << endl;
}

Roster::~Roster()
{
}

int main() 
{
	cout << "\tC867 - Scripting and Programming - Applications" << endl;
	cout << "\t\tLanguage: C++" << endl;
	cout << "\t\t  Jessica Fleming" << endl;
	cout << "\t\t  ID#: 000616694" << endl << endl;


	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

	"A5,Jessica,Fleming,jflem28@wgu.edu,32,20,45,29, SOFTWARE"
	};

	Roster classRoster;

	Degree degreeProgram;

	for (int i = 0; i < 5; i++) 
	{
		stringstream ss(studentData[i]);

		vector<string> stdata(9);

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			stdata.push_back(substr);
		}
		if (stdata[8] == "SECURITY") {
			degreeProgram = Degree::SECURITY;
		}
		if (stdata[8] == "SOFTWARE") {
			degreeProgram = Degree::SOFTWARE;
		}
		if (stdata[8] == "NETWORK") {
			degreeProgram = Degree::NETWORK;
		}
		classRoster.add(stdata[0], stdata[1], stdata[2], stdata[3], stoi(stdata[4]), stoi(stdata[5]),
			stoi(stdata[6]), stoi(stdata[7]), degreeProgram);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAvgDays("A1");

	classRoster.printByDegreeProgram("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3");

	return 0;
}
