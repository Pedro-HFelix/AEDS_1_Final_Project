//
// Created by user on 29/06/2024.
//

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

    ~Student() override;

    void setEnrolment  (string enrolment);

    string getEnrolment();


    void writeData() override;
    void readData() override;

    static int getStudentCount();
    static void registerStudent(Student* students[], int MAX_PEOPLE, Person* persons[]);
    static void listAllStudents(Student* students[]);
};


#endif //FINALC_STUDENT_H
