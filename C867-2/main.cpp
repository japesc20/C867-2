#include <iostream>

#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
    cout << "C867: Scripting and Programming - Applications \n";
    cout << "Language Used: C++ \n";
    cout << "Jacob Petrakovitz (Student ID: 010616446) \n";

    const string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Jacob,Petrakovitz,jpetrak@wgu.edu,34, 10,20,30 ,SOFTWARE"
    };

    // Declaring roster instance (object) of class Roster
    Roster roster;

    const static int numberOfStudents = 5;


    // For loop to parse through the studentData table
    for (int i = 0; i < numberOfStudents; i++) {
        roster.parseStudentData(studentData[i]);
    };

}






// Going through errors to get to build/compile - 12/10  4:00pm
// Finished the add and parsing functions in Roster files
// Currently at 3.B.
