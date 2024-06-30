//
// Created by user on 22/06/2024.
//

#ifndef FINALC___DATE_H
#define FINALC___DATE_H

class Date {
public:
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void setDate(int d, int m, int y);

    int getDay();
    int getMonth();
    int getYear();

    void readDate();
    void writeDate();

    bool isValid();
    bool isSameMonth(int m);
};


#endif //FINALC___DATE_H
