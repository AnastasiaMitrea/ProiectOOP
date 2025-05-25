#ifndef ZBOR_H
#define ZBOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Ora.h"
#include "I_Afisabil.h"

using Utilitati::Date;
using Utilitati::Ora;

namespace Transport_Aerian {

    class Zbor : public Interfete::IAfisabil {
    public:

        Zbor(const Zbor&) = default;
        Zbor(std::string id, std::string plecare, std::string destinatie,
            Date data_plecare, Ora ora_plecare,
            Date data_sosire, Ora ora_sosire,
            int durata, int pret);  
        ~Zbor() = default;

        std::string GetId() const;
        std::string GetPlecare() const;
        std::string GetDestinatie() const;
        int GetPret() const;
        Ora GetOraPlecare() const;
        Ora GetOraSosire() const;
        Date GetDataPlecare() const;
        Date GetDataSosire() const;

        std::string DescriereText() const override;
        std::string GetIdText() const override;
        void Afisare() const override;
        
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
    };

} 

#endif
