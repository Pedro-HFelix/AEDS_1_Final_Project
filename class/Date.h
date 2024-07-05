//
// Created by user on 22/06/2024.
//

#ifndef FINALC_DATE_H
#define FINALC_DATE_H

class Date {
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

    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getYear() const;

    void readDate();
    void writeDate() const;

    [[nodiscard]] bool isValidDate() const;
    [[nodiscard]] bool isSameMonth(int m) const;
};


#endif //FINALC_DATE_H
