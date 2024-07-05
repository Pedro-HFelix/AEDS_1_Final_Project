#include <iostream>
#include "class/Person.h"
#include "class/Student.h"
#include "class/Teacher.h"

#define MAX_PEOPLE 1000

using namespace std;

void writeTeacherFile(Teacher* teachers[]) {
    FILE* teachersFile = fopen("teachers.dat", "wb");
    for (int i = 0; i < Teacher::getTeacherCount(); ++i) {
        fwrite(teachers[i], sizeof(Teacher), 1, teachersFile);
    }
    fclose(teachersFile);
}

void writeStudentFile(Student* students[]) {
    FILE* studentsFile = fopen("students.dat", "wb");
    for (int i = 0; i < Student::getStudentsCount(); ++i) {
        fwrite(students[i], sizeof(Student), 1, studentsFile);
    }
    fclose(studentsFile);
}

void appendTeacherFile(Teacher* teacher) {
    FILE* teachersFile = fopen("teachers.dat", "ab");
    fwrite(teacher, sizeof(Teacher), 1, teachersFile);
    fclose(teachersFile);
}

void appendStudentFile(Student* student) {
    FILE* studentsFile = fopen("students.dat", "ab");
    fwrite(student, sizeof(Student), 1, studentsFile);
    fclose(studentsFile);
}

int basicChoices() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Register (S/T)" << endl;
    cout << "2 - List (S/T)" << endl;
    cout << "3 - Edit (S/T)" << endl;
    cout << "4 - Delete (S/T)" << endl;
    cout << "5 - List birthdays for the month" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 0 || choice > 5) {
        cout << "\nInvalid option. Please try again: ";
        cin >> choice;
    }

    return choice;
}

string selectTypePerson() {
    int choice;
    cout << "Select an option" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Student" << endl;
    cout << "2 - Teacher" << endl;

    cin >> choice;

    while (choice < 0 || choice > 2) {
        cout << "\nInvalid option. Please try again: ";
        cin >> choice;
    }

    return to_string(choice);
}

int menu() {
    bool repeatChoice;
    string choice;

    do {
        repeatChoice = false;
        const int mainChoice = basicChoices();
        choice = to_string(mainChoice);

        if (mainChoice > 0 && mainChoice < 5) {
            choice += selectTypePerson();

            if (!choice.empty() && choice.back() == '0') {
                repeatChoice = true;
            }
        }
    } while (repeatChoice);

    return stoi(choice);
}

int main() {
    try {
        FILE* studentsFile = fopen("students.dat", "rb+");
        FILE* teachersFile = fopen("teachers.dat", "rb+");

        if (!studentsFile || !teachersFile) {
            throw runtime_error("Error to read file");
        }

        Student* students[MAX_PEOPLE] = { nullptr };
        Teacher* teachers[MAX_PEOPLE] = { nullptr };
        Person* persons[MAX_PEOPLE] = { nullptr };

        int studentIndex = 0;
        while (studentIndex < MAX_PEOPLE) {
            students[studentIndex] = new Student;
            if (fread(students[studentIndex], sizeof(Student), 1, studentsFile) != 1) {
                students[studentIndex]->writePerson();
                if (feof(studentsFile)) break;
                else throw runtime_error("Error reading students.dat");
            }
            studentIndex++;
        }

        int teacherIndex = 0;
        while (teacherIndex < MAX_PEOPLE) {
            teachers[teacherIndex] = new Teacher;
            if (fread(teachers[teacherIndex], sizeof(Teacher), 1, teachersFile) != 1) {
                if (feof(teachersFile)) break;
                else throw runtime_error("Error reading teachers.dat");
            }
            teacherIndex++;
        }

        fclose(studentsFile);
        fclose(teachersFile);

        int choice;
        int month;

        do {
            choice = menu();

            switch (choice) {
                case 0:
                    cout << "Exiting..." << endl;
                    break;
                case 11:
                    Student::registerStudent(students, MAX_PEOPLE, persons);
                    appendStudentFile(students[Student::getStudentsCount() - 1]);
                    break;
                case 12:
                    Teacher::registerTeacher(teachers, MAX_PEOPLE, persons);
                    appendTeacherFile(teachers[Teacher::getTeacherCount() - 1]);
                    break;
                case 21:
                    Student::listAllStudents(students);
                    break;
                case 22:
                    Teacher::listAllTeachers(teachers);
                    break;
                case 31:
                    Student::editStudentAtUserInputPosition(students);
                    writeStudentFile(students); // Atualiza o arquivo de estudantes
                    break;
                case 32:
                    Teacher::editTeacherAtUserInputPosition(teachers);
                    writeTeacherFile(teachers);
                    break;
                case 41:
                    Student::deleteStudent(students);
                    writeStudentFile(students);
                    break;
                case 42:
                    Teacher::deleteTeacher(teachers);
                    writeTeacherFile(teachers);
                    break;
                case 5:
                    cout << "Enter the month to list birthdays: ";
                    cin >> month;
                    if (month >= 1 && month <= 12) {
                        cout << "Students: " << endl;
                        Student::listAllStudents(students);
                        cout << "Teachers: " << endl;
                        Teacher::listAllTeachers(teachers);
                    } else {
                        cout << "Invalid month. Please enter a number between 1 and 12." << endl;
                    }
                    break;
                default:
                    cout << "Invalid option." << endl;
                    break;
            }
        } while (choice != 0);
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed" << endl;
    } catch (const runtime_error& e) {
        cerr << "An error occurred: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
