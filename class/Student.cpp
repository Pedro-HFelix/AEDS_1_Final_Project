//
// Created by user on 29/06/2024.
//

#include <iostream>
#include "Student.h"
#include "Person.h"

using namespace std;

/**
 * @brief Static variable to keep track of the number of Student objects.
 */
int Student::studentCount = 0;

/**
 * @brief Parameterized constructor that initializes the Student object.
 *
 * @param name The name of the student (string).
 * @param d Day of birth (integer).
 * @param m Month of birth (integer).
 * @param y Year of birth (integer).
 * @param enrolment The enrolment number of the student (string).
 *
 * This constructor increments the student count.
 */
Student::Student(string name, const int d, const int m, const int y, string enrolment)
 : Person(move(name), d, m, y), enrolment(move(enrolment)) {
    ++studentCount;
}

/**
 * @brief Default constructor that increments the student count.
 */
Student::Student() {
    ++studentCount;
}

/**
 * @brief Destructor that decrements the student count.
 */
Student::~Student() {
    --studentCount;
}

/**
 * @brief Sets the enrolment number of the student.
 *
 * @param enrolment The new enrolment number (string).
 */
void Student::setEnrolment(string enrolment) {
    this->enrolment = move(enrolment);
}

/**
 * @brief Gets the enrolment number of the student.
 *
 * @return The enrolment number (string).
 */
string Student::getEnrolment() {
    return this->enrolment;
}

/**
 * @brief Gets the current count of Student objects.
 *
 * @return The count of Student objects (integer).
 */
int Student::getStudentCount() {
    return studentCount;
}

/**
 * @brief Writes the details of the student to the console.
 *
 * This includes the person's details and the enrolment number.
 */
void Student::writeData() {
    writePerson();
    cout << "Enrollment Number: " << enrolment << endl;
}

/**
 * @brief Reads the details of the student from the console input.
 *
 * This includes the person's details and the enrolment number.
 */
void Student::readData() {
    readPerson();
    cout << "Enter the enrollment number: ";
    cin.ignore();  // Ignore the newline left by previous input
    getline(cin, enrolment);
}

/**
 * @brief Registers a new student.
 *
 * @param students An array of pointers to Student objects.
 * @param MAX_PEOPLE The maximum number of people that can be registered (integer).
 * @param persons An array of pointers to Person objects.
 *
 * This function reads the student details from input and registers the student if the maximum capacity is not reached.
 */
void Student::registerStudent(Student *students[], const int MAX_PEOPLE, Person* persons[]) {
    if (getCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    auto* student = new Student();
    student->readData();
    students[studentCount - 1] = student;
    persons[getCount() - 1] = student;
}

/**
 * @brief Lists all registered students.
 *
 * @param students An array of pointers to Student objects.
 *
 * This function prints the details of each registered student to the console.
 */
void Student::listAllStudents(Student* students[]) {
    if (studentCount == 0) {
        cout << "No student registered." << endl;
        return;
    }

    cout << "List of registered students:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << "Student " << i + 1 << ":" << endl;
        students[i]->writeData();
    }
}
