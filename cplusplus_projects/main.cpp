#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

// Print out to the screen, via your application, the course title, 
//the programming language used, your WGU student ID, and your name.
cout << "C867: Scripting & Programming - Applications" << endl;
cout << "C++" << endl;
cout << "012203109" << endl;
cout << "Ana Escobedo" << endl;

//array for each student
const std::string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
"A5,Ana,Escobedo,myemailaddress@gmail.com,23,20,21,22,SOFTWARE"
};

//classRoster is an instance of the roster class
//using pointer to access members of a class
Roster* classRoster = new Roster();

//for loop to parse through studentdata
for (int i = 0; i < 5; i++) {
    classRoster->parse(studentData[i]);
}

//print everything
classRoster->printAll();

//print all invalid email addresses
classRoster->printInvalidEmails();

//loop through classRosterArray to find avg days in each course
for (int i = 0; i < 5; i++){
classRoster->printAverageDaysInCourse(classRoster->GetId(i));
}
//seperate each student by degree type
classRoster->printByDegreeProgram(SECURITY);
classRoster->printByDegreeProgram(NETWORK);
classRoster->printByDegreeProgram(SOFTWARE);

//REMOVE STUDENT A3
classRoster->remove("A3");

//now print every student except a3
classRoster->printAll();

//parse again, student not found
classRoster->remove("A3");

delete classRoster;

system("pause>0");

return 0;
}
