#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student()
{
	studentID = " ";
	firstName = " ";
	lastName = " ";
	emailADD = " ";
	age = 0;
	numDays[0] = 0;
	numDays[1] = 0;
	numDays[2] = 0;
}

Student::Student(string sID, string fName, string lName, string eADD, int age, int* numDays)
{
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailADD = eADD;
	age = age;
	numDays[0] = numDays[0];
	numDays[1] = numDays[1];
	numDays[2] = numDays[2];
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

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumDays(int nDays0, int nDays1, int nDays2)
{
	numDays[0] = nDays0;
	numDays[1] = nDays1;
	numDays[2] = nDays2;
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
