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


	// Calling Roster and Student class
	Roster roster;
	Student student;

	// Loop and parse through all studentData
	for (string student : studentData) {
		roster.parse(student);
	}


	// --- FUNCTION CALLS --- \\
	
	// Prints all students
	roster.printAll();

	// Prints invalid emails in data table
	roster.printInvalidEmails();

	// Average days in course
	for (int i = 0; i < numberOfStudents; ++i) {
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
	};
	cout << endl;

	// Print by degree 'Software'
	roster.printByDegreeProgram(SOFTWARE);
	// Removes student A3
	roster.remove("A3");
};