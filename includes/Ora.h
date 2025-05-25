#ifndef ORA_H
#define ORA_H

#include <iostream>

namespace Utilitati {

    struct Ora {
        int ora;
        int minut;

        Ora() : ora(0), minut(0){}
        Ora(int ora, int minut) : ora(ora), minut(minut) {}
        //afisare ora in formatul HH:MM
        friend std::ostream& operator<<(std::ostream& os, const Ora& ora) {
            os << ora.ora << ":" << ora.minut;
            return os;
        }
    };

}
#endif