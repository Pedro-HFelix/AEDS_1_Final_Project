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
    this->enrolment = enrolment;
}

string Student::getEnrolment() {
    return this->enrolment;
}

int Student::getStudentCount() {
    return studentCount;
}

void Student::writeData() {
    writePerson();
    cout << "Enrollment Number: " << enrolment << endl;
}

void Student::readData() {
    readPerson();
    cout << "Enter the enrollment number: ";
    cin.ignore();
    getline(cin, enrolment);
}

void Student::registerStudent(Student *students[], int MAX_PEOPLE, Person* persons[]) {
    if (Person::getCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    Student* student = new Student();
    student->readData();
    students[studentCount-1] = student;
    persons[Person::getCount() - 1] = student;
}

void Student::listAllStudents(Student* students[]) {
    if(studentCount == 0) {
        cout << "No student registered." << endl;
        return;
    }

    cout << "List of registered students:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << "Student " << (i + 1) << ":" << endl;
        students[i]->writeData();
    }
}