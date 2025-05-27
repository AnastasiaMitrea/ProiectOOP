#ifndef ZBOR_H
#define ZBOR_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> //pt setw in GenereazaBilet
#include <sstream> //pt ostream de scriere directa in string in GenereazaBilet
#include <map>
#include "Date.h"
#include "Ora.h"
#include "Retea_zboruri.h"
#include "Calendar.h"

using Utilitati::Date;
using Utilitati::Ora;

namespace Transport_Aerian {

    class Zbor {
    public:

        Zbor(const Zbor&) = default;
        Zbor(std::string plecare, std::string destinatie, Date data_plecare, Ora ora_plecare, const Retea_Rute& retea);
        ~Zbor() = default;

        std::string GetId() const;
        std::string GetPlecare() const;
        std::string GetDestinatie() const;
        int GetPret() const;
        Ora GetOraPlecare() const;
        Ora GetOraSosire() const;
        Date GetDataPlecare() const;
        Date GetDataSosire() const;
        std::string Zbor::GenereazaIdBilet(const std::string& clasa);
        
        friend std::ostream& operator<<(std::ostream& os, const Zbor& zbor);

    private:
        std::string m_plecare;
        std::string m_destinatie;

        Date m_data_plecare;
        Ora m_ora_plecare;

        Date m_data_sosire;
        Ora m_ora_sosire;
        
        int m_durata;
        int m_pret_ruta;

        std::map<std::string, int> m_contor_bilete_per_clasa; 
        //dictionar cheie - valoare cu cheie = clasa ("economic", "business") si valoare = numarul biletului cu clasa respectiva
    };                                                        

} 

#endif
