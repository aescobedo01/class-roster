#pragma once

#include <iostream>
#include "degree.h"

using namespace std;
//student class
class Student{
    
private:
//declare private varibales
    string studentId;
    string lastName;
    string firstName;
    string emailAddress;
    int yearsOld;
    //3 days for the days in course
    int daysCourse[3];
    Degree degreeProgram;

public: 
//default student constructor
    Student();

//student constructor
    Student(string studentid, string firstname, string lastname, string email, int age, int days[], Degree degree);

//destructor
    ~Student();

//declare setters
void setId(string studentID);
void setFName(string firstName);
void setLName(string lastName);
void setEmail(string emailAddress);
void setAge(int yearsOld);
void setDays(int daysCourse1, int daysCourse2, int daysCourse3);
void setDegree(Degree degreeProgram);

//declare getters and data types to get info
string getId() const;
string getFName() const;
string getLName() const;
string getEmail() const;
int getAge() const;
int getDays(int i) const;
Degree getDegree() const;

//print
void print() const;
    
};