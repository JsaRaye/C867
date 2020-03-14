#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student()
{
	
}

Student::Student(string sID, string fName, string lName, string eADD, int sAge, int* nDays)
{
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailADD = eADD;
	age = sAge;
	numDays[0] = nDays[0];
	numDays[1] = nDays[1];
	numDays[2] = nDays[2];
}

void Student::setStudentID(string sID)
{
	studentID = sID;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
}

void Student::setLastName(string lName)
{
	lastName = lName;
}

void Student::setEmailADD(string eADD)
{
	emailADD = eADD;
}

void Student::setAge(int sAge)
{
	age = sAge;
}

void Student::setNumDays(int nday0, int nday1, int nday2)
{
	numDays[0] = nday0;
	numDays[1] = nday1;
	numDays[2] = nday2;
}

void Student::setDegreeProgram(string degreeProgram)
{
	degreeProgram = degreeProgram;
}


string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailADD()
{
	return emailADD;
}

int Student::getAge()
{
	return age;
}

int *Student::getNumDays()
{
	return numDays;
}


Degree Student::getDegreeProgram()
{
	return Degree::SOFTWARE;
}

void Student::print()
{
}


Student::~Student()
{
}
