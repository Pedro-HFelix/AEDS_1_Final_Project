//
// Created by Pedro Félix on 30/06/24.
//

#include "Teacher.h"

#include <iostream>
using namespace std;

int Teacher::teacherCount = 0;

Teacher::Teacher() {
    ++teacherCount;
}

Teacher::Teacher(string name, int day, int month, int year, string title)
    : Person(name, day, month, year), title(title) {
    ++teacherCount;
}

Teacher::~Teacher() {
    --teacherCount;
}

void Teacher::setTitle(string title) {
    this->title = title;
}

string Teacher::getTitle() {
    return title;
}

void Teacher::readTeacher() {
    readPerson();

    cout << "Enter the title (Specialist, Master, Doctor): ";
    string title;
    getline(cin, title);

    setTitle(title);
}

void Teacher::writeTeacher() {
    writePerson();
    cout << "Title: " << title << endl;
}

int Teacher::getTeacherCount() {
    return teacherCount;
}