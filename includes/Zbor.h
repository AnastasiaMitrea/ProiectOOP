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
    Zbor(std::string id, std::string plecare, std::string destinatie,
         Date data_plecare, Ora ora_plecare,
         Date data_sosire, Ora ora_sosire,
         int durata, int pret, int nr_pasageri);

    friend std::ostream& operator<<(std::ostream& os, const Zbor& zbor);

private:
    std::string m_id;
    std::string m_plecare;
    std::string m_destinatie;
    Date m_data_plecare;
    Ora m_ora_plecare;
    Date m_data_sosire;
    Ora m_ora_sosire;
    int m_durata;
    int m_pret;
    int m_nr_pasageri;
};

} 

#endif
