//
// Created by user on 22/06/2024.
//

#include "Person.h"
#include <iostream>

using namespace std;

/**
 * @brief Static variable to keep track of the number of Person objects.
 */
int Person::count = 0;

/**
 * @brief Default constructor that increments the count of Person objects.
 */
Person::Person() { count++; }

/**
 * @brief Constructor that initializes the Person object with a name and birth date.
 *
 * @param name The name of the person (string).
 * @param birthDate The birth date of the person (Date object).
 */
Person::Person(string name, const Date birthDate)
    : name(move(name)), birthDate(birthDate) {
    count++;
}

/**
 * @brief Constructor that initializes the Person object with a name and a birth date from separate day, month, and year parameters.
 *
 * @param name The name of the person (string).
 * @param d Day of birth (integer).
 * @param m Month of birth (integer).
 * @param y Year of birth (integer).
 */
Person::Person(string name, const int d, const int m, const int y)
    : name(move(name)), birthDate(d, m, y) {
    count++;
}

/**
 * @brief Destructor that decrements the count of Person objects.
 */
Person::~Person() {
    if (count > 0) {
        count--;
    }
}

/**
 * @brief Sets the name of the person.
 *
 * @param name The new name of the person (string).
 */
void Person::setName(string name) {
    this->name = std::move(name);
}

/**
 * @brief Gets the name of the person.
 *
 * @return The name of the person (string).
 */
string Person::getName() {
    return this->name;
}

/**
 * @brief Reads the name of the person from the console input.
 *
 * Prompts the user to enter a name and sets it to the person object.
 */
void Person::readName() {
    cout << "Enter name: ";
    cin.ignore();

    string name;
    getline(cin, name);

    setName(name);
}

/**
 * @brief Writes the name of the person to the console.
 */
void Person::writeName() {
    cout << "Name: " << getName() << endl;
}

/**
 * @brief Reads the details of the person from the console input.
 *
 * This includes the name and birth date.
 */
void Person::readPerson() {
    readName();
    cout << "Enter birth date:" << endl;
    this->birthDate.readDate();
}

/**
 * @brief Writes the details of the person to the console.
 *
 * This includes the name and birth date.
 */
void Person::writePerson() {
    writeName();
    this->birthDate.writeDate();
}

/**
 * @brief Gets the birth date of the person.
 *
 * @return The birth date of the person (Date object).
 */
Date Person::getBirthDate() const {
    return this->birthDate;
}

/**
 * @brief Gets the current count of Person objects.
 *
 * @return The count of Person objects (integer).
 */
int Person::getCount() {
    return count;
}

/**
 * @brief Lists all registered people.
 *
 * @param peoples An array of pointers to Person objects.
 *
 * This method prints the details of each registered person to the console.
 */
void Person::listAllPersons(Person* peoples[]) {
    if (count == 0) {
        cout << "No people registered." << endl;
        return;
    }

    cout << "List of registered people:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "Person " << i + 1 << ":" << endl;
        peoples[i]->writePerson();
    }
}

/**
 * @brief Shows the people with birthdays in the specified month.
 *
 * @param peoples An array of pointers to Person objects.
 * @param month The month to check for birthdays (integer).
 *
 * This method prints the details of people who have birthdays in the specified month.
 */
void Person::showBirthdaysForMonth(Person* peoples[], const int month) {
    bool found = false;

    cout << "People with birthdays in month " << month << ":" << endl;

    for (int i = 0; i < getCount(); ++i) {
        if (peoples[i]->birthDate.isSameMonth(month)) {
            cout << "Person " << i + 1 << ":" << endl;
            peoples[i]->writePerson();
            cout << "\n" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No birthdays found in month " << month << "." << endl;
    }
}
