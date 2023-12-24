#ifndef ROSTER_H

#pragma once
#include <iostream>
#include "student.h"


// Global variable
static const int numberOfStudents = 5;
static const int numberOfClasses = 3;


class Roster {

public:

	// Array of pointers holding studentData
	Student* classRosterArray[numberOfStudents];

	// Default constructor
	Roster();
	// Default destructor
	~Roster();


	// FUNCTIONS BEGIN HERE

	// Parse function - parse studentData table to create each student object
	void parse(std::string studentRow);
	// Add function - contains all the studentData parameters and adds them to the classRosterArray
	void add(std::string studentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int daysToCompletion1, int daysToCompletion2,
		int daysToCompletion3, DegreeProgram degreeProgram);
	static DegreeProgram degreeToString(std::string degreeProgram);

	// Remove function - remove any student by given studentID
	void remove(std::string studentID);
};


#endif // !ROSTER_H
