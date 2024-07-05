//
// Created by Pedro Félix on 30/06/24.
//

#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

using namespace std;

class Teacher final : public Person{
    string title;
    static int teacherCount;

public:
    Teacher();
    Teacher(string name, int day, int month, int year, string title);
    ~Teacher() override;

    void setTitle(string title);

    string getTitle();

    void writeData() override;
    void readData() override;
    int getCount() override;

    static void registerTeacher(Teacher* teachers[], int MAX_PEOPLE, Person* persons[]);
    static void listAllTeachers(Teacher* teachers[]);
    static void deleteTeacher(Teacher* teachers[]);
    static void editTeacherAtUserInputPosition(Teacher* teachers[]);
    static int getTeacherCount();
    static void showBirthdaysForMonth(Teacher* teachers[], int month);
};

#endif //TEACHER_H
