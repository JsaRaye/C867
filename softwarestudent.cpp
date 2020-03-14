#include "student.h"
#include "softwarestudent.h"
#include "degree.h"
#include <iostream>
using namespace std;


SoftwareStudent::SoftwareStudent()
{

}

SoftwareStudent::SoftwareStudent(string sID, string fName, string lName, string eADD, int sAge, int* nDays, Degree degreeProgram)
{
	degreeProgram = degreeProgram;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return degreeProgram;
}

void SoftwareStudent::print()
{
	cout << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge()
		 << "\tDays In Course: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "} "
	     << "Degree Program: Software" << '\n';
}
