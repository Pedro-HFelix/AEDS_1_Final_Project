//
// Created by user on 22/06/2024.
//

#ifndef FINALC___PERSON_H
#define FINALC___PERSON_H

#include "Date.h"
#include <string>

class Person {
private:
    std::string name;
    Date birthDate;
    static int count;

public:
    Person();
    Person(std::string& name, Date& birthDate);
    ~Person();

    void setName(std::string& name);
    std::string getName();
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
