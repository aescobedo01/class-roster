#include <iostream>
#include "roster.h"

using namespace std;

// constructor
Roster::Roster()
{
    for (int i = 0; i < 5; i++)
    {
        // each item in classrosterarray to be assigned with a new student object
        classRosterArray[i] = new Student();
    }
}

// destructor
// delete each classrosterarray object
Roster::~Roster()
{
    for (int i = 0; i < 5; ++i)
    {
        delete classRosterArray[i];
    }
}

// get each id from CRA
string Roster::GetId(int index)
{
    string studentId = classRosterArray[index]->getId();
    return studentId;
}

// parse through each string in student data
void Roster::parse(string studentDataString)
{
    string studentId, firstName, lastName, emailAddress;
    int yearsOld, daysCourse1, daysCourse2, daysCourse3;

    if (lastIndex < 5)
    {
        lastIndex++;
        // initialize variables once
        int rhs = studentDataString.find(",");
        int lhs = rhs + 1;

        // id
        string id = studentDataString.substr(0, rhs);
        classRosterArray[lastIndex]->setId(id);
        cout << id << endl;

        // fname
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        string fname = studentDataString.substr(lhs, rhs - lhs);
        classRosterArray[lastIndex]->setFName(fname);
        cout << fname << endl;

        // lname
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        string lname = studentDataString.substr(lhs, rhs - lhs);
        classRosterArray[lastIndex]->setLName(lname);
        cout << lname << endl;

        // email
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        string email = studentDataString.substr(lhs, rhs - lhs);
        classRosterArray[lastIndex]->setEmail(email);
        cout << email << endl;

        // age
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        int age = stoi(studentDataString.substr(lhs, rhs - lhs));
        classRosterArray[lastIndex]->setAge(age);
        cout << age << endl;

        // days in each course
        // day 1
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        daysCourse1 = stoi(studentDataString.substr(lhs, rhs - lhs));

        // day 2
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        daysCourse2 = stoi(studentDataString.substr(lhs, rhs - lhs));

        // day3
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        daysCourse3 = stoi(studentDataString.substr(lhs, rhs - lhs));

        // set days in eahc course
        classRosterArray[lastIndex]->setDays(daysCourse1, daysCourse2, daysCourse3);
        cout << daysCourse1 << ", " << daysCourse2 << ", " << daysCourse3 << endl;

        // degree
        lhs = rhs + 1;
        rhs = studentDataString.find(",", lhs);
        string type = studentDataString.substr(lhs, rhs - lhs);
        if (type == "SOFTWARE")
        {
            classRosterArray[lastIndex]->setDegree(SOFTWARE);
            cout << "SOFTWARE" << endl;
        }
        else if (type == "SECURITY")
        {
            classRosterArray[lastIndex]->setDegree(SECURITY);
            cout << "SECURITY" << endl;
        }
        else if (type == "NETWORK")
        {
            classRosterArray[lastIndex]->setDegree(NETWORK);
            cout << "NETWORK" << endl;
        }
        else
        {
            cout << "Degree does not exist" << endl;
        }
        cout << endl;
    }
}

// remove method
bool Roster::remove(string studentId)
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i]->getId() == studentId)
        {
            // find eahc student by id then dleete student object
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--; // roster down one element
            return true;
        }
    }
    cout << "Student not found: " << studentId << endl;
    return false;
}

// populate cra w/student obj array
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int yearsOld, int daysCourse1, int daysCourse2, int daysCourse3, Degree degreeProgram)
{
    int days[] = {daysCourse1, daysCourse2, daysCourse3};
    classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, yearsOld, days, degreeProgram);
};

// print cra values w/pointers
void Roster::printAll() const {
    cout << endl;
    // parse student array and call print method for each one
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
    cout << endl;
}

//print avg num of days in each course
void Roster::printAverageDaysInCourse(string studentId) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getId() == studentId) {
            int day1 = classRosterArray[i]->getDays(0);
            int day2 = classRosterArray[i]->getDays(1);
            int day3 = classRosterArray[i]->getDays(2);
            cout << "Average days in a course for " << studentId << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

// inv email addresses
void Roster::printInvalidEmails() const {
    cout << "Invalid emails: " << endl;
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmail();
        //ensure emails meet requirements
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << email << endl;
        }
    }
    cout << endl;
}

// degreeeee
void Roster::printByDegreeProgram(Degree degreeProgram) const {
    cout << endl;
    if (degreeProgram == SECURITY) {
        cout << "Degree program: Security " << endl;
    }
    else if (degreeProgram == NETWORK) {
            cout << "Degree program: Network " << endl;
    }
    else if (degreeProgram == SOFTWARE) {
            cout << "Degree program: Software " << endl;
    }
    else {
    cout << "Degree not found." << endl;
    }

    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}