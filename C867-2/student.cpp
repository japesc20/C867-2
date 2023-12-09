using namespace std; 
#include <iostream>

#include "student.h"



// Default Constructor - Setting variables to empty strings or 0
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToCompletion[0] = 0;
	this->daysToCompletion[1] = 0;
	this->daysToCompletion[2] = 0;
	this->degreeProgram;

}


// Getters - logic
string Student::getStudentID() {
	return studentID;
};

string Student::getFirstName() {
	return firstName;
};

string Student::getLastName() {
	return lastName;
};

string Student::getEmailAddress() {
	return emailAddress;
};

int Student::getAge() {
	return age;
};

int* Student::getDaysToCompletion() {
	return daysToCompletion;
};

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
};


// Setters - logic

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

void Student::setDaysToCompletion(int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3) {
	// For loop to iterate through daysToCompletion array to set members
	for (int i = 0; i < 3; i++) {
		this->daysToCompletion[0] = daysToCompleteCourse1;
		this->daysToCompletion[1] = daysToCompleteCourse2;
		this->daysToCompletion[2] = daysToCompleteCourse3;
	};
};

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
};