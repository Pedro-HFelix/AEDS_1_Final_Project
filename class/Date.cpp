//
// Created by user on 22/06/2024.
//

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(){}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::setDay(int d) {
    this->day = d;
}

void Date::setMonth(int m) {
    this->month = m;
}

void Date::setYear(int y) {
    this->year = y;
}

int Date::getDay() {
    return this->day;
}
int Date::getMonth() {
    return this->month;
}

int Date::getYear() {
    return this->year;
}

void Date::setDate(int d, int m, int y) {
    this->day = d;
    this->month = m;
    this->year = y;
}

bool Date::isValid() {
    if (this->year < 1 || this->month < 1 || this->month > 12 || this->day < 1 || this->day > 31) return false;
    int daysPerMonth[] = { 31, (this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return this->day <= daysPerMonth[this->month - 1];
}

void Date::readDate() {
    cout << "Enter day: ";
    cin >> this->day;
    cout << "Enter month: ";
    cin >> this->month;
    cout << "Enter year: ";
    cin >> this->year;
}

void Date::writeDate() {
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

bool Date::isSameMonth(int m) {

}
