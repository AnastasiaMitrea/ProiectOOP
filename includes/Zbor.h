#ifndef ZBOR_H
#define ZBOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Ora.h"

using namespace std;

class Zbor {
    private:
        string id;
        string plecare;
        string destinatie;
        Date dataPlecare;
        Ora oraPlecare;
        Date dataSosire;
        Ora oraSosire;
        int durata; // in minute
        int pret; // in lei
        int nrPasageri;
    
    public:
        Zbor(string id, string plecare, string destinatie, Date dataPlecare, Ora oraPlecare, Date dataSosire, Ora oraSosire, int durata, int pret, int nrPasageri)
            : id(id), plecare(plecare), destinatie(destinatie), dataPlecare(dataPlecare), oraPlecare(oraPlecare), dataSosire(dataSosire), oraSosire(oraSosire), durata(durata), pret(pret), nrPasageri(nrPasageri) {}

        //afisare zbor in formatul: ID | Plecare | Destinatie | DataPlecare | OraPlecare | DataSosire | OraSosire | Durata | Pret | NrPasageri
        friend ostream& operator<<(ostream& os, const Zbor& zbor) {
            os << zbor.id << " | Plecare: " << zbor.plecare << " | Destinatie: " << zbor.destinatie << " | Data plecare: " << zbor.dataPlecare << " | Ora plecare: " << zbor.oraPlecare << " | Data sosire: " << zbor.dataSosire << " | Ora sosire: " << zbor.oraSosire << " | " << zbor.durata << " minute" << " | " << zbor.pret << " lei" << " | Numarr pasageri la bord: " << zbor.nrPasageri;
            return os;
        }
};

#endif