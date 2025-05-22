#include "student.h"

using namespace std;

//default student constructor
Student::Student() {
//initialize member variables
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->yearsOld = 0;
    for (int i = 0; i < 3; ++i){
        this->daysCourse[i] = -1;
    }
    //default degree
    this->degreeProgram = SOFTWARE;
}

//student constructor with parameters
    Student::Student(string studentid, string firstname, string lastname, string email, int age, int days[], Degree degree) {
        //assign parameter values to member variables
        this->studentId = studentid;
        this->firstName = firstname;
        this->lastName = lastname;
        this->emailAddress = email;
        this->yearsOld = age;
        for (int i = 0; i < 3; ++i){
        this->daysCourse[i] = days[i];
    }
        this->degreeProgram = degree;
    }

//destroy
    Student::~Student() {};

    //mutators or setters
    void Student::setId(string studentId){
        this->studentId = studentId;
    }
    void Student::setFName(string firstName){
        this->firstName = firstName;
    }

    void Student::setLName(string lastName){
        this->lastName = lastName;
    }
    void Student::setEmail(string emailAddress){
        this->emailAddress = emailAddress;
    }
    void Student::setAge(int yearsOld){
        this->yearsOld = yearsOld;
    }

    void Student::setDays(int daysCourse1, int daysCourse2, int daysCourse3) {
        for (int i = 0; i < 3; i++){
            this->daysCourse[0] = daysCourse1;
            this->daysCourse[1] = daysCourse2;
            this->daysCourse[2] = daysCourse3;
        }
    }

    void Student::setDegree(Degree degreeProgram) {
        this->degreeProgram = degreeProgram;
    }

//accessors or getters
    string Student::getId() const {
        return studentId;
    }

    string Student::getFName() const {
        return firstName;
    }
    
    string Student::getLName() const {
        return lastName;
    }

    string Student::getEmail() const {
        return emailAddress;
    }

    int Student::getAge() const {
        return yearsOld;
    }

    int Student::getDays(int i) const {
        return daysCourse[i];
    }

    Degree Student::getDegree() const {
        return degreeProgram;
    }

//print everything
void Student::print() const {
    string myDegree;
    if (this->degreeProgram == SECURITY) {
        myDegree = "Security";
    }
      else if (this->degreeProgram == SOFTWARE) {
        myDegree = "Software";
    }
      else if (this->degreeProgram == NETWORK) {
        myDegree = "Network";
    }
    else {
        myDegree = "Error";
    }

//PRINT EVERYTHING
    cout << "ID: " << getId()
    << "\tFirst Name: " << getFName()
    << "\tLast Name: " << getLName()
    << "\tE-mail: " << getEmail()
    << "\tAge: " << getAge()
    << "\tDays in Course: {" << daysCourse[0] << ", " << daysCourse[1] << ", " << daysCourse[2] << "}"
    << "\tDegree: " << myDegree
    << endl;

    return;
}