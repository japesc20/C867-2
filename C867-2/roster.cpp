using namespace std;

#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"


// Calling Roster constructor
Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->index = 0;

	// For loop through each object (student) then creating a new student object
	for (int i = 0; i < rosterSize; i++) {
		this->classRosterArray[i] = new Student;
	}
	return;
}


// Pointer of pointers returning student data
Student** Roster::getAllStudents()
{
	return Roster::classRosterArray;
}



//Calling parsing method - setting setters from StudentData
void Roster::parseStudentData(string studentData) {

	string studentID, firstName, lastName, emailAddress;
	int age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3;

	if (index < rosterSize) {

		classRosterArray[index] = new Student();

		int i = studentData.find(",");
		studentID = studentData.substr(0, i);
		classRosterArray[index]->setStudentID(studentID);

		int j = i + 1;
		i = studentData.find(",", j);
		firstName = studentData.substr(j, i - j);
		classRosterArray[index]->setFirstName(firstName);

		j = i + 1;
		i = studentData.find(",", j);
		lastName = studentData.substr(j, i - j);
		classRosterArray[index]->setLastName(lastName);

		j = i + 1;
		i = studentData.find(",", j);
		emailAddress = studentData.substr(j, i - j);
		classRosterArray[index]->setEmailAddress(emailAddress);

		j = i + 1;
		i = studentData.find(",", j);
		age = stoi(studentData.substr(j, i - j));
		classRosterArray[index]->setAge(age);

		j = i + 1;
		i = studentData.find(",", j);
		daysToCompleteCourse1 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		daysToCompleteCourse2 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		daysToCompleteCourse3 = stoi(studentData.substr(j, i - j));

		classRosterArray[index]->setDaysToCompletion(daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3);

		j = i + 1;
		i = studentData.find(",", j);
		string type = studentData.substr(j, i - j);
		if (type == "SOFTWARE") {
			classRosterArray[index]->setDegreeProgram(SOFTWARE);
		}
		else if (type == "SECURITY") {
			classRosterArray[index]->setDegreeProgram(SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[index]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not set" << endl;
		}
		index++;
	}
	return;
}


// Adding student object function
void Roster::add(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age,
	int daysToCompleteCourse1,
	int daysToCompleteCourse2,
	int daysToCompleteCourse3,
	DegreeProgram degreeProgram) {

	// Establishing each member inside array
	int daysToCompletion[3] = { daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3 };

	// Creating the new student object with parameters given
	classRosterArray[rosterSize] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3, degreeProgram);
};




// Calling Roster destructor
Roster::~Roster() {};