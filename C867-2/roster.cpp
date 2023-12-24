#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


// Establishing classRosterArray = array of student pointers
Student* classRosterArray[numberOfStudents];


// Parse function - 
void Roster::parse(string studentRow) {
	string studentID, firstName, lastName, emailAddress,
		ageString, daysToCompletion1String, daysToCompletion2String, daysToCompletion3String,
		degreeProgram;

	// Stringstream allows us to parse through and manipulate the data table of strings
	stringstream student(studentRow);

	// getline parameters read as follows (read input, write input to variable name, '' stop reading where)
	getline(student, studentID, ',');
	getline(student, firstName, ',');
	getline(student, lastName, ',');
	getline(student, emailAddress, ',');
	getline(student, ageString, ',');
	getline(student, daysToCompletion1String, ',');
	getline(student, daysToCompletion2String, ',');
	getline(student, daysToCompletion3String, ',');
	getline(student, degreeProgram, ',');
	
	// Calling degreeToString function to parse through degree enumerator
	DegreeProgram degreeString = degreeToString(degreeProgram);

	int age = stoi(ageString);
	// Pulling from daysToCompletionStrings "stoi" converts string into an int
	int daysToCompletion1 = stoi(daysToCompletion1String);
	int daysToCompletion2 = stoi(daysToCompletion2String);
	int daysToCompletion3 = stoi(daysToCompletion3String);

	// Adds all student data from parsing to the add function
	add(studentID, firstName, lastName, emailAddress, age, daysToCompletion1, daysToCompletion2, daysToCompletion3, degreeString);
};

// Setting degreeProgram enumerator members to its corresponding string literal
DegreeProgram Roster::degreeToString(string degreeProgram) {

	if (degreeProgram == "SECURITY") return SECURITY;
	if (degreeProgram == "SOFTWARE") return SOFTWARE;
	if (degreeProgram == "NETWORK") return NETWORK;
};


// Adding all student data to the classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysToCompletion1, int daysToCompletion2, int daysToCompletion3, DegreeProgram degreeProgram) {

	// Setting and adding daysToCompletion members to days array
	int courseDays[numberOfClasses] = { daysToCompletion1, daysToCompletion2, daysToCompletion3 };

	/* For loop, loops through the classRosterArray, if member is defined as nullptr (memory address is absent from member)
		it adds in the student row with its corresponding data*/
	for (int i = 0; i < numberOfStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName,
				emailAddress, age, courseDays, degreeProgram);
			return;
		};
	};
};

// Removing a student from classRosterArray by given studentID
void Roster::remove(string studentID) {

	bool studentRemoved = false;

	for (int i = 0; i < numberOfStudents; ++i) {
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			studentRemoved = true;

			cout << "STUDENT REMOVED: " << studentID;
		} else {
			cout << "ERROR: COULD NOT FIND STUDENT ID - " << studentID;
		}
	};
};
