#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
	
	Student();
	Student(string sID, string fName, string lName, string eADD, int sAge, int* nDays);

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailADD(string emailADD);
	void setAge(int age);
	void setNumDays(int nday0, int nday1, int nday2);
	void setDegreeProgram(string degreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailADD();
	int    getAge();
	int   *getNumDays();
	

	virtual void print();

	virtual Degree getDegreeProgram();

	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailADD;
	int    age;
	int    numDays[3];

};
