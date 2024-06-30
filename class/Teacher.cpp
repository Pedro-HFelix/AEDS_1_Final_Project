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

void Teacher::readData() {
    readPerson();

    cout << "Enter the title (Specialist, Master, Doctor): ";
    string title;

    cin.ignore();
    getline(cin, title);

    setTitle(title);
}

void Teacher::writeData() {
    writePerson();
    cout << "Title: " << title << endl;
}

int Teacher::getTeacherCount() {
    return teacherCount;
}

void Teacher::registerTeacher(Teacher* Teachers[], int MAX_PEOPLE, Person* persons[]) {
    if (Person::getCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    Teacher* teacher = new Teacher();
    teacher->readData();
    Teachers[teacherCount-1] = teacher;
    persons[Person::getCount() - 1] = teacher;
}

void Teacher::listAllTeachers(Teacher* teachers[]) {
    if(teacherCount == 0) {
        cout << "No teacher registered." << endl;
        return;
    }

    cout << "List of registered teachers:" << endl;
    for (int i = 0; i < teacherCount; ++i) {
        cout << "Teacher " << (i + 1) << ":" << endl;
        teachers[i]->writeData();
    }
}
