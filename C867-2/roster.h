#ifndef ROSTER_H
#define ROSTER_H
#pragma once

#include "student.h"


class Roster {

	public:

		int rosterSize;
		int index;

		// Initialize Roster constructor
		Roster(int rosterSize);
		Roster();
		// Initialize Roster destructor
		~Roster();

		Student* classRosterArray[5];

		void add(
			std::string studentID,
			std::string firstName,
			std::string lastName,
			std::string emailAddress,
			int age,
			int daysToCompleteCourse1,
			int daysToCompleteCourse2,
			int daysToCompleteCourse3,
			DegreeProgram degreeprogram);



	// Pointer to studentData table
	Student** getAllStudents();

	void parseStudentData(std::string student);

};



#endif // !ROSTER_H