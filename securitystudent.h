#pragma once
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	
	SecurityStudent(string sID, string fName, string lName, string eADD, int age, int* numDays, Degree degreeProgram);

	Degree getDegreeProgram() override;

	void print() override;

private:
	Degree degreeProgram; //Degree::SECURITY??
};
