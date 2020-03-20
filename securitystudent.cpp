#include "student.h"
#include "securitystudent.h"
#include "degree.h"
#include <iostream>
using namespace std;


SecurityStudent::SecurityStudent()
{

}

SecurityStudent::SecurityStudent(string sID, string fName, string lName, string eADD, int sAge, int* numDays, Degree degreeProgram)
{
	degreeProgram = degreeProgram;
}

Degree SecurityStudent::getDegreeProgram()
{
	return degreeProgram;
}

void SecurityStudent::print()
{
	cout << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge()
		<< "\tDays In Course: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "} "
		<< "Degree Program: Security" << endl;
}
