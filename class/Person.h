//
// Created by user on 22/06/2024.
//

#ifndef FINALC_PERSON_H
#define FINALC_PERSON_H

#include <string>
#include "Date.h"

using namespace std;

class Person {
    string name;
    Date birthDate;
    static int count;

public:
    Person();
    Person(string name, int d, int m, int y);

    virtual ~Person();

    void setName(string name);

    string getName();
    [[nodiscard]] Date getBirthDate() const;

    void readName();
    void readPerson();

    void writeName();
    void writePerson();

    static void listAllPersons(Person* peoples[]);
    static void showBirthdaysForMonth(Person* peoples[], int month);
    static void deletePersonAtPosition(Person *peoples[]);
    static void editPersonAtUserInputPosition(Person* peoples[]);
    static int getPersonCount();

    virtual int getCount() = 0;
    virtual void writeData() = 0;
    virtual void readData() = 0;
};


#endif //FINALC_PERSON_H
