//
// Created by user on 29/06/2024.
//

#include <iostream>
#include <utility>
#include "Student.h"
#include "Person.h"

using namespace std;

int Student::studentCount = 0;


Student::Student(string name, int d, int m, int y, string enrolment)
 : Person(name, d, m, y), enrolment(enrolment) {
    ++studentCount;
}


Student::Student() {
    ++studentCount;
}

Student::~Student() {
    --studentCount;
}

void Student::setEnrolment(string enrolment) {
    this->enrolment = std::move(enrolment);
}

string Student::getEnrolment() {
    return this->enrolment;
}

void Student::readStudent() {
    readPerson();
    cout << "Enter the enrollment number: ";
    getline(cin, enrolment);
}

void Student::writeStudent() {
    writePerson();
    cout << "Enrollment Number: " << enrolment << endl;

}

int Student::getStudentCount() {
    return studentCount;
}
