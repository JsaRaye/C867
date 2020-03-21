#pragma once
#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	
	NetworkStudent(string sID, string fName, string lName, string eADD, int age, int* numDays, Degree degreeProgram);

	Degree getDegreeProgram() override;

	void print() override;

private:
	Degree degreeProgram; // Degree::NETWORK??
};
