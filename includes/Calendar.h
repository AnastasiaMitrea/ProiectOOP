#ifndef CALENDAR_H
#define CALENDAR_H

#include <ctime>
#include "Date.h"

namespace Utilitati{
class Calendar {
    public:
        // anul curent
        static int GetAnCurent() {
            time_t t = time(nullptr);
            return localtime(&t)->tm_year + 1900;
        }

        // luna curenta (1-12)
        static int GetLunaCurenta() {
            time_t t = time(nullptr);
            return localtime(&t)->tm_mon + 1;
        }

        // ziua curenta (1-31)
        static int GetZiCurenta() {
            time_t t = time(nullptr);
            return localtime(&t)->tm_mday; 
        }

        static Date GetDataCurenta() {
            time_t t = time(nullptr);
            tm* timp = localtime(&t); 
            return Utilitati::Date(
            timp->tm_mday,
            timp->tm_mon + 1,
            timp->tm_year + 1900);
        }

        // verificare an  bisect
        static bool EsteAnBisect(int an) {
            return (an % 4 == 0 && an % 100 != 0) || (an % 400 == 0);
        }

        // verificare data valida
        static bool EsteDataValida(Date data) {
            if(data.luna < 1 || data.luna > 12 || data.zi < 1) //true daca luna este intre 1 si 12 si ziua este minim 1
                return false;

            int zile_luna[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //nr zile pe luni in ordine , februarie are minim 28 zile
            if(data.luna == 2 && EsteAnBisect(data.an))  //luna este februarie si e an bisect
                return data.zi <= 29;  //true daca ziua este maxim 29

            return (data.zi <= zile_luna[data.luna - 1]) ; //true daca nr zilei este <= cu nr maxim de zile al lunii respective
        }

        // calculeaza varsta folosind data nasterii si data curenta
        static int CalculeazaVarsta(Date data) {
            int zi = GetZiCurenta();
            int luna = GetLunaCurenta();
            int an = GetAnCurent();

            int varsta = an - data.an;
            if(data.luna > luna || (data.luna == luna && data.zi > zi))
                varsta--;

            return varsta;
        }
    };

}

#endif 
