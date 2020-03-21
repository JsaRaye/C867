#include "securitystudent.h"
#include <iostream>
using namespace std;


SecurityStudent::SecurityStudent()
{

}

SecurityStudent::SecurityStudent(string sID, string fName, string lName, string eADD, int age, int* numDays, Degree degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

Degree SecurityStudent::getDegreeProgram()
{
	return degreeProgram; //Degree::SECURITY??
}

void SecurityStudent::print()
{
	cout << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge()
		<< "\tDays In Course: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "} "
		<< "Degree Program: Software" << '\n';
}
