#ifndef ORA_H
#define ORA_H

#include <iostream>
using namespace std;

struct Ora {
    int ora;
    int minut;

    Ora(int ora, int minut, int secunda) : ora(ora), minut(minut) {}
    //afisare ora in formatul HH:MM:SS
    friend ostream& operator<<(ostream& os, const Ora& ora) {
        os << ora.ora << ":" << ora.minut;
        return os;
    }
};

#endif