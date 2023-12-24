#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main() {

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jacob,Petrakovitz,jpetrak@wgu.edu,34,30,60,90,SOFTWARE" };

	cout << "C867 - Scripting and Programming - Applications\n";
	cout << "Language Used: C++\n";
	cout << "Student ID: 010616446\n";
	cout << "Jacob Petrakovitz\n" << endl;


	// Creating an instance for classRoster and student
	Roster classRoster;
	Student student;

	// Loop and parse through all studentData
	for (string student : studentData) {
		classRoster.parse(student);
	}


	// --- FUNCTION CALLS --- \\
	
	// Prints all students
	classRoster.printAll();

	// Prints invalid emails in data table
	classRoster.printInvalidEmails();

	// Prints average days in course for each student
	for (int i = 0; i < numberOfStudents; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	};
	cout << endl;

	// Prints by degree 'Software'
	classRoster.printByDegreeProgram(SOFTWARE);

	// Removes student A3
	classRoster.remove("A3");

	// Print all student after removing A3
	classRoster.printAll();

	// Attempting to remove student A3 again
	classRoster.remove("A3");
};
