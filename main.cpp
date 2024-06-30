#include <iostream>
#include "class/Person.h"
#include "class/Student.h"

//#define MAX_PEOPLE 1000
#define MAX_PEOPLE 1000

using namespace std;

int menu() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Register a person" << endl;
    cout << "2 - List registered people" << endl;
    cout << "3 - List birthdays for the month" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 0 || choice > 3) {
        cout << "Invalid option. Please try again: ";
        cin >> choice;
    }
    return choice;
}

int main() {

    Person* peoples[MAX_PEOPLE];
    int choice;
    int month;

    do {
        choice = menu();

        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1:
                Person::registerPerson(peoples, MAX_PEOPLE);
                break;
            case 2:
                Person::listAllPersons(peoples, Person::getCount());
                break;
            case 3:
                cout << "Enter the month to list birthdays: ";
                cin >> month;
                if (month >= 1 && month <= 12) {
                    Person::showBirthdaysForMonth(peoples, Person::getCount(), month);
                } else {
                    cout << "Invalid month. Please enter a number between 1 and 12." << endl;
                }
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (choice != 0);

    for (int i = 0; i < Person::getCount(); ++i) {
        delete peoples[i];
    }

    return 0;
}
