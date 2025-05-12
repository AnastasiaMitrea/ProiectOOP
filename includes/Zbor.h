#ifndef ZBOR_H
#define ZBOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Ora.h"

namespace Transport_Aerian {

    class Zbor {

    public:
        Zbor(std::string id, std::string plecare, std::string destinatie, Date dataPlecare, Ora oraPlecare, Date dataSosire, Ora oraSosire, int durata, int pret, int nrPasageri)
            : id(id), plecare(plecare), destinatie(destinatie), 
            dataPlecare(dataPlecare), oraPlecare(oraPlecare), 
            dataSosire(dataSosire), oraSosire(oraSosire), 
            durata(durata), pret(pret), nrPasageri(nrPasageri) {}

        //afisare zbor in formatul: ID | Plecare | Destinatie | DataPlecare | OraPlecare | DataSosire | OraSosire | Durata | Pret | NrPasageri
        friend std::ostream& operator<<(std::ostream& os, const Zbor& zbor) {

            os << zbor.id 
            << " | Plecare: " << zbor.plecare 
            << " | Destinatie: " << zbor.destinatie 
            << " | Data plecare: " << zbor.dataPlecare 
            << " | Ora plecare: " << zbor.oraPlecare 
            << " | Data sosire: " << zbor.dataSosire 
            << " | Ora sosire: " << zbor.oraSosire 
            << " | " << zbor.durata << " minute" 
            << " | " << zbor.pret << " lei" 
            << " | Numar pasageri la bord: " << zbor.nrPasageri;

            return os;
        }

    private:
        std::string id;
        std::string plecare;
        std::string destinatie;
        Date dataPlecare;
        Ora oraPlecare;
        Date dataSosire;
        Ora oraSosire;
        int durata; // in minute
        int pret; // in lei
        int nrPasageri;
    };

}

#endif