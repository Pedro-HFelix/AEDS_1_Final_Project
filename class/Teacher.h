//
// Created by Pedro Félix on 30/06/24.
//

#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"


using namespace std;
class Teacher: public Person{

private:
    string title;
    static int teacherCount;

public:
    Teacher();
    Teacher(string name, int day, int month, int year, string title);
    ~Teacher();

    void setTitle(string title);
    string getTitle();

    void writeData() override;
    void readData() override;

    static void registerTeacher(Teacher* Teachers[], int MAX_PEOPLE, Person* persons[]);
    static int getTeacherCount();
    static void listAllTeachers(Teacher* teachers[]);
};



#endif //TEACHER_H
