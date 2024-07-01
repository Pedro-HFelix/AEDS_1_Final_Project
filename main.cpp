#include <iostream>
#include "class/Person.h"
#include "class/Student.h"
#include "class/Teacher.h"

#define MAX_PEOPLE 1000

using namespace std;

int menu() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Register student" << endl;
    cout << "2 - Register teacher" << endl;
    cout << "3 - List registered student " << endl;
    cout << "4 - List registered teacher" << endl;
    cout << "5 - List birthdays for the month" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 0 || choice > 5) {
        cout << "Invalid option. Please try again: ";
        cin >> choice;
    }
    return choice;
}

int main() {
    // ReSharper disable once CppTooWideScope
    Student* students[MAX_PEOPLE];
    // ReSharper disable once CppTooWideScope
    Teacher* teachers[MAX_PEOPLE];
    // ReSharper disable once CppTooWideScope
    Person* persons[MAX_PEOPLE];

    int choice;
    int month;

    do {
        choice = menu();

        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1:
                Student::registerStudent(students, MAX_PEOPLE, persons);
                break;
            case 2:
                Teacher::registerTeacher(teachers, MAX_PEOPLE, persons);
                break;
            case 3:
                Student::listAllStudents(students);
                break;
            case 4:
                Teacher::listAllTeachers(teachers);
                break;
            case 5:
                cout << "Enter the month to list birthdays: ";
                cin >> month;
                if (month >= 1 && month <= 12) {
                    Person::showBirthdaysForMonth(persons, month);
                } else {
                    cout << "Invalid month. Please enter a number between 1 and 12." << endl;
                }
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (choice != 0);


    return 0;
}
