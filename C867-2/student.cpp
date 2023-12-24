#include <iostream>
#include "student.h"

using namespace std;



Student::Student(
	std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age,
	int daysToCompletion[numberOfClasses],
	DegreeProgram degreeProgram) {

};

// Getters (Accessors)
string Student::getStudentID() {
	return this->studentID;
};

string Student::getFirstName() {
	return this->firstName;
};

string Student::getLastName() {
	return this->lastName;
};

string Student::getEmailAddress() {
	return this->emailAddress;
};

int Student::getAge() {
	return this->age;
};

int* Student::getDaysToCompletion() {
	return this->daysToCompletion;
};

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
};


// Setters (Mutators)
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
};

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
};

void Student::setLastName(string lastName) {
	this->lastName = lastName;
};

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};

void Student::setAge(int age) {
	this->age = age;
};

void Student::setDaysToCompletion(int daysToCompletion[]) {
	// For loop, loops through the daysToCompletion array and sets each member
	for (int i = 0; i < numberOfClasses; ++i) {
		this->daysToCompletion[i] = daysToCompletion[i];
	};
};

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}; 


// Converting enumerator members to strings
inline const char* Student::degreeToString(DegreeProgram degreeProgram) {
	switch (degreeProgram) {
	case SECURITY:		return "SECURITY";
	case NETWORK:		return "NETWORK";
	case SOFTWARE:		return "SOFTWARE";
	default:			return "NA";
	};
};



void Student::print() {
	cout << this->getStudentID() << "\t"
		<< this->getFirstName() << "\t"
		<< this->getLastName() << " "
		<< this->getEmailAddress() << "\t"
		<< this->getAge() << "\t"
		<< daysToCompletion[0] << ", "
		<< daysToCompletion[1] << ", " 
		<< daysToCompletion[2] << "\t"
		<< degreeToString(degreeProgram) << "\n";
}


