//
// Created by user on 29/06/2024.
//

// ReSharper disable CppPolymorphicClassWithNonVirtualPublicDestructor
#ifndef FINALC_STUDENT_H
#define FINALC_STUDENT_H


#include "Person.h"

using namespace std;

class Student final : public Person{
    string enrolment;
    static int studentCount;

public:
    Student();
    Student(string name, int d, int m, int y, string enrolment);

    void setEnrolment  (string enrolment);

    string getEnrolment();


    void writeData() override;
    void readData() override;
    int getCount() override;

    static void registerStudent(Student* students[], int MAX_PEOPLE, Person* persons[]);
    static void listAllStudents(Student* students[]);
    static void deleteStudent(Student* students[]);
    static void editStudentAtUserInputPosition(Student* students[]);
    static int getStudentsCount();
};


#endif //FINALC_STUDENT_H
