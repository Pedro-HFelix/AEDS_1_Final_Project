//
// Created by Pedro Félix on 30/06/24.
//

#include "Teacher.h"
#include <iostream>

using namespace std;

/**
 * @brief Static variable to keep track of the number of Teacher objects.
 */
int Teacher::teacherCount = 0;

/**
 * @brief Default constructor that increments the teacher count.
 */
Teacher::Teacher() {
    ++teacherCount;
}

/**
 * @brief Parameterized constructor that initializes a Teacher object.
 *
 * @param name The name of the teacher (string).
 * @param day Day of birth (integer).
 * @param month Month of birth (integer).
 * @param year Year of birth (integer).
 * @param title The title of the teacher (e.g., Specialist, Master, Doctor) (string).
 *
 * This constructor also increments the teacher count.
 */
Teacher::Teacher(string name, const int day, const int month, const int year, string title)
    : Person(move(name), day, month, year),
      title(move(title)) {
    ++teacherCount;
}

/**
 * @brief Destructor that decrements the teacher count.
 */
Teacher::~Teacher() {
    --teacherCount;
}

/**
 * @brief Sets the title of the teacher.
 *
 * @param title The new title (string).
 */
void Teacher::setTitle(string title) {
    this->title = move(title);
}

/**
 * @brief Gets the title of the teacher.
 *
 * @return The title of the teacher (string).
 */
string Teacher::getTitle() {
    return title;
}

/**
 * @brief Reads the teacher's data from the console input.
 *
 * This includes the person's details and the title.
 */
void Teacher::readData() {
    readPerson();

    cout << "Enter the title (Specialist, Master, Doctor): ";
    string title;

    cin.ignore();  // Ignore the newline left by previous input
    getline(cin, title);

    setTitle(title);
}

/**
 * @brief Writes the teacher's data to the console.
 *
 * This includes the person's details and the title.
 */
void Teacher::writeData() {
    writePerson();
    cout << "Title: " << title << endl;
}

/**
 * @brief Gets the current count of Teacher objects.
 *
 * @return The count of Teacher objects (integer).
 */
int Teacher::getTeacherCount() {
    return teacherCount;
}

/**
 * @brief Registers a new teacher.
 *
 * @param teachers An array of pointers to Teacher objects.
 * @param MAX_PEOPLE The maximum number of people that can be registered (integer).
 * @param persons An array of pointers to Person objects.
 *
 * This function reads the teacher's data from input and registers the teacher if the maximum capacity is not reached.
 */
void Teacher::registerTeacher(Teacher *teachers[], const int MAX_PEOPLE, Person *persons[]) {
    if (getCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    auto *teacher = new Teacher();
    teacher->readData();
    teachers[teacherCount - 1] = teacher;
    persons[getCount() - 1] = teacher;
}

/**
 * @brief Lists all registered teachers.
 *
 * @param teachers An array of pointers to Teacher objects.
 *
 * This function prints the details of each registered teacher to the console.
 */
void Teacher::listAllTeachers(Teacher *teachers[]) {
    if (teacherCount == 0) {
        cout << "No teacher registered." << endl;
        return;
    }

    cout << "List of registered teachers:" << endl;
    for (int i = 0; i < teacherCount; ++i) {
        cout << "Teacher " << i + 1 << ":" << endl;
        teachers[i]->writeData();
    }
}
