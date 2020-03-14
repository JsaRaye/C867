#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster 
{
private:
	Student *classRosterArray[5];

public:
	Roster();

	void add(string studentID, string firstName, string lastName, string emailADD, int age, int nday0, int nday1, int nday2, Degree degreeProgram);

	void remove(string studentID);

	void printAll();

	void printAvgDays(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(string degreeProgram);

	int  index = 0;

	~Roster();

};

