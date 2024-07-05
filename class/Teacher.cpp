//
// Created by Pedro Félix on 30/06/24.
//

#include "Teacher.h"

#include <cstdbool>
#include <iostream>
#include <thread>

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

Teacher::~Teacher() {
    if(teacherCount > 0) --teacherCount;
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
 * This includes the person's details and the title. The title must be one of the
 * following: "Specialist", "Master", or "Doctor". It cannot be empty.
 */
void Teacher::readData() {
    readPerson();

    string title;

    bool continueLoop = true;


    while (continueLoop) {
        cout << "Enter the title (Specialist, Master, Doctor): ";

        getline(cin, title);

        title.erase(0, title.find_first_not_of(" \t"));
        title.erase(title.find_last_not_of(" \t") + 1);

        if (title.empty()) {
            cout << "Title cannot be empty. Please enter a valid title." << endl;
            continue;
        }

        string lowerTitle;
        for(auto letter : title) lowerTitle += tolower(letter, locale());

        if (lowerTitle == "specialist" || lowerTitle == "master" || lowerTitle == "doctor") {
            title = lowerTitle;
            title[0] = toupper(lowerTitle[0]);

            setTitle(title);
            continueLoop = false;
        } else {
            cout << "Invalid title. Please enter one of the following: Specialist, Master, Doctor." << endl;
        }
    }
}


/**
 * @brief Gets the current count of Teacher objects.
 *
 * @return The count of Teacher objects (integer).
 */
int Teacher::getCount() {
    return teacherCount;
}

/**
 * @brief Writes the teacher's data to the console.
 *
 * This includes the person's details and the title.
 */
void Teacher::writeData() {
    cout << "Title: " << title << endl;
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
    if (getPersonCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << endl;
        return;
    }

    auto *teacher = new Teacher();
    teacher->readData();
    teachers[teacherCount - 1] = teacher;
    persons[getPersonCount() - 1] = teacher;
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
        teachers[i]->writePerson();
    }
}

/**
 * @brief Deletes a teacher at a specified position.
 *
 * @param teachers An array of pointers to Student objects.
 *
 * This method deletes the person at the specified position and shifts the remaining elements.
 */
void Teacher::deleteTeacher(Teacher *teachers[]) {
    if (teacherCount == 0) {
        cout << "No teachers available to delete." << endl;
        return;
    }

    int position;
    bool continueLoop = true;

    while (continueLoop) {
        cout << "Enter the position of the person to delete (1 to " << teacherCount << "): ";
        cin >> position;

        if (cin.fail() || position < 1 || position > teacherCount) {
            cout << "Invalid position. Please enter a number between 1 and " << teacherCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continueLoop = false;
        }
    }

    const int index = position - 1;

    delete teachers[index];

    for (int i = index; i < teacherCount; ++i) {
        teachers[i] = teachers[i + 1];
    }

    teachers[teacherCount] = nullptr;
    cout << "Teacher at position " << position << " deleted successfully." << endl;
}

/**
 * @brief Edits the details of a `Teacher` object at a user-specified position.
 *
 * This method prompts the user to enter the position of the `Teacher` object to edit,
 * validates the position, and then calls `readPerson` on the selected object to allow
 * editing of its details.
 *
 * @param teachers An array of pointers to `Teacher` objects.
 */
void Teacher::editTeacherAtUserInputPosition(Teacher* teachers[]) {
    if (teacherCount == 0) {
        cout << "No teachers available to edit." << endl;
        return;
    }

    int position;
    bool continueLoop = true;

    while (continueLoop) {
        cout << "Enter the position of the teacher to edit (1 to " << teacherCount << "): ";
        cin >> position;

        if (cin.fail() || position < 1 || position > teacherCount) {
            cout << "Invalid position. Please enter a number between 1 and " << teacherCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continueLoop = false;
        }
    }

    const int index = position - 1;

    cout << "Editing teacher at position " << position << ":" << endl;
    teachers[index]->readData();
    cout << "Teacher details updated successfully." << endl;
}

int Teacher::getTeacherCount() {
   return teacherCount;
}

/**
 * @brief Shows the teachers with birthdays in the specified month.
 *
 * @param teachers An array of pointers to Teacher objects.
 * @param month The month to check for birthdays (integer).
 *
 * This method prints the details of people who have birthdays in the specified month.
 */
void Teacher::showBirthdaysForMonth(Teacher* teachers[], const int month) {
    bool found = false;

    cout << "Teacher with birthdays in month " << month << ":" << endl;

    for (int i = 0; i < teacherCount; ++i) {
        if (teachers[i]->getBirthDate().isSameMonth(month)) {
            cout << "Teacher " << i + 1 << ":" << endl;
            teachers[i]->writePerson();
            cout << "\n" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No birthdays found in month " << month << "to teachers." << endl;
    }
}
