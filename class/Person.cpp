//
// Created by user on 22/06/2024.
//

#include "Person.h"
#include <iostream>
#include <utility>

using namespace std;

int Person::count = 0;

Person::Person() { count++; }

Person::Person(string name, Date birthDate)
    : name(name), birthDate(birthDate) {
    count++;
}

Person::Person(string name, int d, int m, int y)
    : name(name), birthDate(d, m, y) {
    count++;
}

Person::~Person() {
    if (count > 0) {
        count--;
    }
}

void Person::setName(string name) {
    this->name = std::move(name);
}

string Person::getName() {
    return this->name;
}

void Person::readName() {
    cout << "Enter name: ";
    cin.ignore();

    string name;
    getline(cin, name);

    setName(name);

}

void Person::writeName() {
    cout << "Name: " << getName() << endl;
}

void Person::readPerson() {
    readName();
    cout << "Enter birth date:" << endl;
    this->birthDate.readDate();
}

void Person::writePerson() {
    cout << "Name: " << getName() << endl;
    cout << "Birth date: ";
    this->birthDate.writeDate();
}

Date Person::getBirthDate() {
    return this->birthDate;
}

int Person::getCount() {
    return count;
}

void Person::registerPerson(Person* people[], int MAX_PEOPLE) {
    if (getCount() > MAX_PEOPLE) {
        cout << "Cannot register more people. Maximum capacity reached." << std::endl;
        return;
    }

    Person* newPerson = new Person();
    newPerson->readPerson();
    people[getCount() - 1] = newPerson;
}

void Person::listAllPersons(Person* people[], int qtdPersons) {
    if (qtdPersons == 0) {
        cout << "No people registered." << endl;
        return;
    }

    cout << "List of registered people:" << endl;
    for (int i = 0; i < qtdPersons; ++i) {
        cout << "Person " << (i + 1) << ":" << endl;
        people[i]->writePerson();
    }
}

void Person::showBirthdaysForMonth(Person* people[], int qtdPersons, int month) {
    bool found = false;
    cout << "People with birthdays in month " << month << ":" << endl;

    for (int i = 0; i < count; ++i) {
        if (people[i]->getBirthDate().getMonth() == month) {
            people[i]->writePerson();
            found = true;
        }
    }

    if (!found) {
        cout << "No birthdays found in month " << month << "." << endl;
    }
}
