//
// Created by user on 22/06/2024.
//

#ifndef FINALC___PERSON_H
#define FINALC___PERSON_H

#include <string>

#include "Date.h"

using namespace std;

class Person {
private:
    string name;
    Date birthDate;
    static int count;

public:
    Person();
    Person(string name, Date birthDate);
    Person(string name, int d, int m, int y);

    ~Person();

    void setName(string name);
    void readName();
    void readPerson();

    string getName();
    Date getBirthDate();
    void writeName();
    void writePerson();

    static int getCount();
    static void listAllPersons(Person* people[]);
    static void showBirthdaysForMonth(Person* people[], int month);

    static void showBirthdaysForMonthAllTypes(Person* people[], int month);

    virtual void writeData() = 0;
    virtual void readData() = 0;
};


#endif //FINALC___PERSON_H
