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
    string getName();
    void readName();
    void writeName();
    void readPerson();
    void writePerson();
    Date getBirthDate();

    static int getCount();
    static void registerPerson(Person* people[], int MAX_PEOPLE);
    static void listAllPersons(Person* people[], int qtdPersons);
    static void showBirthdaysForMonth(Person* people[], int qtdPersons ,int month);

};


#endif //FINALC___PERSON_H
