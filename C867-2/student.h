#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include "degree.h"


class Student{
	
	// Setting private variables - encapsulation
	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int age;
		int daysToCompletion[3];
		DegreeProgram degreeProgram;

	public:

		// Initialize default constructor
		Student();
		// Initalize parameter constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);

		// Setters - for each variable established in student.h
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysToCompletion(int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3);
		void setDegreeProgram(DegreeProgram degreeProgram);

		// Getters - ^^
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		//* = Pointer
		int* getDaysToCompletion();
		DegreeProgram getDegreeProgram();


		// Establish print function 
		void print();
};


#endif // !STUDENT_H