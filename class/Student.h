//
// Created by user on 29/06/2024.
//

#ifndef FINALC___STUDENT_H
#define FINALC___STUDENT_H


#include "Person.h"

using namespace std;

class Student : public Person{
private:
    string enrolment;
    static int studentCount;

public:
    Student();
    Student( string& name, int& d, int& m, int& y, string& enrolment);
    ~Student();

    void setEnrolment  (string& enrolment);
    string getEnrolment();
    void readStudent();
    void writeStudent();

    static int getStudentCount();
};


#endif //FINALC___STUDENT_H