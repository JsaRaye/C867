#pragma once
#include "degree.h"
#include "student.h"

class Roster 
{
private:
	Student *classRosterArray[5];


public:
	Roster();

	virtual ~Roster();

	void add(string studentID, string firstName, string lastName, string emailADD, int age, int nDays0, int nDays1, int nDays2, Degree degreeProgram);

	void remove(string studentID);

	void printAll();

	void printAvgDays(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(string degreeProgram);

	int  index = 0;
};
