#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;


// Establishing classRosterArray = array of student pointers
Student* classRosterArray[numberOfStudents];


// Default constructor, initiates each student row as nullptr initially
Roster::Roster() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
		classRosterArray[i] = nullptr;
	}
}


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

	bool studentFound = false;

	/* Loop through studentData - if studentID matches remove 
		of studentID not found - error message */ 
	for (int i = 0; i < numberOfStudents; ++i) {
		if ((classRosterArray[i] != nullptr) &&
			(classRosterArray[i]->getStudentID() == studentID)) {

			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			studentFound = true;

			cout << "STUDENT REMOVED: " << studentID << "\n" << endl;
		};
	};
	if (!studentFound) {
		cout << "ERROR: COULD NOT FIND STUDENT ID - " << studentID << endl;
	};
};


// Function prints all student data
void Roster::printAll() {
	cout << "Displaying all students: \n" << endl;
	for (int i = 0; i < numberOfStudents; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		};
	};
	cout << endl;
};


// Function prints the average days a student is in a class
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numberOfStudents; ++i) {
		if ((classRosterArray[i] != nullptr) && 
			(classRosterArray[i]->getStudentID() == studentID)) {

			int averageDaysInCourse;

			// Finding the average days for each student 
			averageDaysInCourse = (
				classRosterArray[i]->getDaysToCompletion()[0] +
				classRosterArray[i]->getDaysToCompletion()[1] +
				classRosterArray[i]->getDaysToCompletion()[2]) / 3;

			cout << "Student ID: " << studentID
				<< ", average days in course is: " << averageDaysInCourse << "\n";
		};
	};
};


// Prints invalid emails from the student data table
void Roster::printInvalidEmails() {

	cout << "Displaying invalid emails: \n" << endl;

	// Loops student table
	for (int i = 0; i < numberOfStudents; ++i) {
		string studentEmail = classRosterArray[i]->getEmailAddress();

		/* npos = is not found
			' ' != is double negative, if space found, invalid
			'.' if period is missing, invalid 
			'@' if @ is missing, invalid */

		if ((studentEmail.find(' ') != string::npos) ||
			(studentEmail.find('.') == string::npos) ||
			(studentEmail.find('@') == string::npos)) {
			cout << studentEmail << " - is invalid\n";

		};
	};

	cout << endl;
};


// Prints all students by degree given in argument
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	// Finding which degreeProgram was given in argument
	string degree;

	if (degreeProgram == SECURITY) {
		degree = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degree = "NETWORK";
	}
	else {
		degree = "SOFTWARE";
	};

	cout << "Displaying all students in degree program: " << degree << "\n" << endl;

	// If [i] is not a nullptr and it equals the degreeProgram given - print() student
	for (int i = 0; i < numberOfStudents; ++i) {
		if ((classRosterArray[i] != nullptr) &&
			(classRosterArray[i]->getDegreeProgram() == degreeProgram)) {

			classRosterArray[i]->print();
		};
	};

	cout << endl;
};


// Default destructor - sets all rows in classRosterArray back to nullptr
Roster::~Roster() {
	for (int i = 0; i < numberOfStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};



