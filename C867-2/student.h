#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include <array>
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
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);
		// Initialize destructor for Student object
		~Student();
		

		// Setters - for each variable established in student.h
		void setStudentID(std::string studentID);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setEmailAddress(std::string emailAddress);
		void setAge(int age);
		void setDaysToCompletion(int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3);
		void setDegreeProgram(DegreeProgram degreeProgram);

		// Getters - ^^
		std::string getStudentID();
		std::string getFirstName();
		std::string getLastName();
		std::string getEmailAddress();
		int getAge();
		//* = Pointer
		int* getDaysToCompletion();
		DegreeProgram getDegreeProgram();


		// Establish print function 
		void print();
		static void printHeader();


};


#endif // !STUDENT_H