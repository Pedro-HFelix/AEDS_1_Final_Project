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
Student::Student(   string name, const int d, const int m, const int y, string enrolment)
 : Person(move(name), d, m, y), enrolment(move(enrolment)) {
    ++studentCount;
}


Student::~Student() {
    if(studentCount > 0) --studentCount;
}

/**
 * @brief Default constructor that increments the student count.
 */
Student::Student() {
    ++studentCount;
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
int Student::getCount() {
    return studentCount;
}

/**
 * @brief Writes the details of the student to the console.
 *
 * This includes the person's details and the enrolment number.
 */
void Student::writeData() {
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
    cin.ignore();

    string enrolment;
    bool continueLoop = true;

    while(continueLoop) {
        getline(cin, enrolment);

        if(enrolment.empty()) {
            cout << "Title cannot be empty. Please enter a valid title." << endl;
            continue;
        }
        continueLoop = false;
    }

    setEnrolment(enrolment);
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
    const int countPeople = getPersonCount();

    if (countPeople > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    auto* student = new Student();
    student->readData();
    students[studentCount - 1] = student;
    persons[countPeople - 1] = student;
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
        students[i]->writePerson();
    }
}

/**
 * @brief Deletes a student at a specified position.
 *
 * @param students An array of pointers to Student objects.
 *
 * This method deletes the person at the specified position and shifts the remaining elements.
 */
void Student::deleteStudent(Student* students[]) {
    if (studentCount == 0) {
        cout << "No students available to delete." << endl;
        return;
    }

    int position;
    bool continueLoop = true;

    while (continueLoop) {
        cout << "Enter the position of the person to delete (1 to " << studentCount << "): ";
        cin >> position;

        if (cin.fail() || position < 1 || position > studentCount) {
            cout << "Invalid position. Please enter a number between 1 and " << studentCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continueLoop = false;
        }
    }

    const int index = position - 1;

    delete students[index];

    for (int i = index; i < studentCount; ++i) {
        students[i] = students[i + 1];
    }

    students[studentCount] = nullptr;
    cout << "Student at position " << position << " deleted successfully." << endl;
}

/**
 * @brief Edits the details of a `Student` object at a user-specified position.
 *
 * This method prompts the user to enter the position of the `Student` object to edit,
 * validates the position, and then calls `readPerson` on the selected object to allow
 * editing of its details.
 *
 * @param students An array of pointers to `Student` objects.
 */
void Student::editStudentAtUserInputPosition(Student* students[]) {
    if (studentCount == 0) {
        cout << "No students available to edit." << endl;
        return;
    }

    int position;
    bool continueLoop = true;

    while (continueLoop) {
        cout << "Enter the position of the student to edit (1 to " << studentCount << "): ";
        cin >> position;

        if (cin.fail() || position < 1 || position > studentCount) {
            cout << "Invalid position. Please enter a number between 1 and " << studentCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continueLoop = false;
        }
    }

    const int index = position - 1;

    cout << "Editing student at position " << position << ":" << endl;
    students[index]->readData();
    cout << "Student details updated successfully." << endl;
}

int Student::getStudentsCount() {
    return studentCount;
}

/**
 * @brief Shows the students with birthdays in the specified month.
 *
 * @param students An array of pointers to Student objects.
 * @param month The month to check for birthdays (integer).
 *
 * This method prints the details of people who have birthdays in the specified month.
 */
void Student::showBirthdaysForMonth(Student* students[], const int month) {
    bool found = false;

    cout << "Teacher with birthdays in month " << month << ":" << endl;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i]->getBirthDate().isSameMonth(month)) {
            cout << "student " << i + 1 << ":" << endl;
            students[i]->writePerson();
            cout << "\n" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No birthdays found in month " << month << "to students." << endl;
    }
}