#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student 
{
public:
	
	Student();
	Student(string sID, string fName, string lName, string eADD, int age, int* numDays);

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailADD(string emailADD);
	void setAge(int age);
	void setNumDays(int nDays0, int nDays1, int nDays2);
	void setDegreeProgram(string degreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailADD();
	int    getAge();
	int*   getNumDays();
	

	virtual void print() = 0;
	virtual Degree getDegreeProgram() = 0;

	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailADD;
	int    age;
	int    numDays[3];
};
