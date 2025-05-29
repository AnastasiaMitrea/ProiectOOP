#ifndef DATE_H
#define DATE_H

#include <iostream>

namespace Utilitati {

    struct Date{
        int zi;
        int luna;
        int an;

        Date() : zi(0), luna(0), an(0) {} //constructor default
        Date(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}  //constructor cu lista de initializare

        int GetZi() const { return zi;}

        bool operator==(const Date& other) const {
            return zi == other.zi &&
                luna == other.luna &&
                an == other.an;
        }

  
        bool operator<(const Date& other) const {
            if (an != other.an) return an < other.an;
            if (luna != other.luna) return luna < other.luna;
            return zi < other.zi;
        }


        //afisare data in formatul DD/MM/YYYY
        friend std::ostream& operator<<(std::ostream& os, const Date& date) {
            os << date.zi << "/" << date.luna << "/" << date.an;
            return os;
        }
    };

};

#endif