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
        : m_id(id), m_plecare(plecare), m_destinatie(destinatie), 
        m_data_plecare(dataPlecare), m_ora_plecare(oraPlecare), 
        m_data_sosire(dataSosire), m_ora_sosire(oraSosire), 
        m_durata(durata), m_pret(pret), m_nr_pasageri(nrPasageri) {}

    //afisare zbor in formatul: ID | Plecare | Destinatie | DataPlecare | OraPlecare | DataSosire | OraSosire | Durata | Pret | NrPasageri
    friend std::ostream& operator<<(std::ostream& os, const Zbor& zbor) {

        os << zbor.m_id 
        << " | Plecare: " << zbor.m_plecare 
        << " | Destinatie: " << zbor.m_destinatie 
        << " | Data plecare: " << zbor.m_data_plecare 
        << " | Ora plecare: " << zbor.m_ora_plecare 
        << " | Data sosire: " << zbor.m_data_sosire 
        << " | Ora sosire: " << zbor.m_ora_sosire 
        << " | " << zbor.m_durata << " minute" 
        << " | " << zbor.m_pret << " lei" 
        << " | Numar pasageri la bord: " << zbor.m_nr_pasageri;

        return os;
    }

private:
    std::string m_id;
    std::string m_plecare;
    std::string m_destinatie;
    Date m_data_plecare;
    Ora m_ora_plecare;
    Date m_data_sosire;
    Ora m_ora_sosire;
    int m_durata; // in minute
    int m_pret; // in lei
    int m_nr_pasageri;
};

}

#endif