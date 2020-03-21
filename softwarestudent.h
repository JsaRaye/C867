#pragma once
#include "student.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();

	SoftwareStudent(string sID, string fName, string lName, string eADD, int age, int* numDays, Degree degreeProgram);

	Degree getDegreeProgram() override;

	void print() override;

private:
	 Degree degreeProgram; //Degree::SOFTWARE??
};
