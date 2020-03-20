#pragma once
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();

	SoftwareStudent(string sID, string fName, string lName, string eADD, int sAge, int* numDays, Degree degreeProgram);

	Degree getDegreeProgram() override;

	void print() override;

private:
	Degree degreeProgram;
};

