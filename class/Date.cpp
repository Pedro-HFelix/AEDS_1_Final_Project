//
// Created by user on 22/06/2024.
//

#include "Date.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor that initializes the date to null (zero) values.
 */
Date::Date() : day(0), month(0), year(0) {}

/**
 * @brief Constructor that initializes the date with the given parameters.
 *
 * @param d Day of the month (integer).
 * @param m Month of the year (integer).
 * @param y Year (integer).
 */
Date::Date(const int d, const int m, const int y) : day(d), month(m), year(y) {}

/**
 * @brief Sets the day of the month.
 *
 * @param d Day of the month (integer).
 */
void Date::setDay(const int d) {
    this->day = d;
}

/**
 * @brief Sets the month of the year.
 *
 * @param m Month of the year (integer).
 */
void Date::setMonth(const int m) {
    this->month = m;
}

/**
 * @brief Sets the year.
 *
 * @param y Year (integer).
 */
void Date::setYear(const int y) {
    this->year = y;
}

/**
 * @brief Sets the complete date with day, month, and year.
 *
 * @param d Day of the month (integer).
 * @param m Month of the year (integer).
 * @param y Year (integer).
 */
void Date::setDate(const int d, const int m, const int y) {
    this->day = d;
    this->month = m;
    this->year = y;
}

/**
 * @brief Gets the day of the month.
 *
 * @return The day of the month (integer).
 */
int Date::getDay() const {
    return this->day;
}

/**
 * @brief Gets the month of the year.
 *
 * @return The month of the year (integer).
 */
int Date::getMonth() const {
    return this->month;
}

/**
 * @brief Gets the year.
 *
 * @return The year (integer).
 */
int Date::getYear() const {
    return this->year;
}

/**
 * @brief Reads the date from the console.
 *
 * Prompts the user to enter the day, month, and year, and stores them in the corresponding attributes.
 */
void Date::readDate() {
    cout << "Enter day: ";
    cin >> this->day;
    cout << "Enter month: ";
    cin >> this->month;
    cout << "Enter year: ";
    cin >> this->year;
}

/**
 * @brief Writes the complete date to the console.
 *
 * Displays the date in the format "dd/MM/yyyy".
 */
void Date::writeDate() const {
    cout << "Birth date: ";
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

/**
 * @brief Validates the current date.
 *
 * Checks if the stored date is valid considering the day, month, and year.
 * Takes leap years into account when validating February.
 *
 * @return true if the date is valid, false otherwise.
 */
bool Date::isValid() const {
    if (this->year < 1 || this->month < 1 || this->month > 12 || this->day < 1 || this->day > 31) return false;
    const int daysPerMonth[] = {
        31,
        (this->year % 4 == 0 && this->year % 100 != 0)
        || this->year % 400 == 0
            ? 29
            : 28,
        31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    return this->day <= daysPerMonth[this->month - 1];
}

/**
 * @brief Checks if the month of the date is the same as the given month.
 *
 * @param m Month to compare (integer).
 * @return true if the months are the same, false otherwise.
 */
bool Date::isSameMonth(const int m) const {
    return month == m;
}
