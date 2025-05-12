#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

struct Date{
    int zi;
    int luna;
    int an;

    Date(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

    //afisare data in formatul DD/MM/YYYY
    friend ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.zi << "/" << date.luna << "/" << date.an;
        return os;
    }
};

#endif