#ifndef STUDENT_H

#pragma once
#include <iostream>
#include "degree.h"


class Student {

	static const int numberOfClasses = 3;

private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysToCompletion[numberOfClasses];
	DegreeProgram degreeProgram;


public:

	// Constructor with all parameters from student table
	Student(
		std::string studentID, 
		std::string firstName, 
		std::string lastName, 
		std::string emailAddress, 
		int age,
		int daysToCompletion[numberOfClasses],
		DegreeProgram degreeProgram
		);

	// Default student constructor
	Student();
	// Default student Destructor
	~Student();


	// Initialzing Getters (Accessors)
	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int *getDaysToCompletion();
	DegreeProgram getDegreeProgram();

	// Initializing Setters (Mutators)
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysToCompletion(int daysToCompletion[numberOfClasses]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	// Initializing functions
	inline const char *degreeToString(DegreeProgram degreeProgram);
	void print();

	
};

#endif // !"STUDENT_H" 