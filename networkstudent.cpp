#include "student.h"
#include "networkstudent.h"
#include "degree.h"
#include <iostream>
using namespace std;


NetworkStudent::NetworkStudent()
{

}

NetworkStudent::NetworkStudent(string sID, string fName, string lName, string eADD, int sAge, int* numDays, Degree degreeProgram)
{
	degreeProgram = degreeProgram;
}

Degree NetworkStudent::getDegreeProgram()
{
	return degreeProgram;
}

void NetworkStudent::print()
{
	cout << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge()
		<< "\tDays In Course: {" << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "} "
		<< "Degree Program: Network" << endl;
}
