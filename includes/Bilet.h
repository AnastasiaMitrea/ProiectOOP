#ifndef BILET_H
#define BILET_H

#include <string>
#include <iostream>
#include "I_Afisabil.h"

namespace Transport_Aerian {

    class Bilet : public Interfete::IAfisabil  {
    public:
        Bilet(); //constructor default
        Bilet(const std::string& id, const std::string& clasa, int pret); //constructor cu parametri

        std::string GetId() const;
        std::string GetClasa() const;
        int GetPret() const;
        void SetId(const std::string& id);
        void SetClasa(const std::string& clasa);
        void SetPret(int pret);

        friend std::ostream& operator<<(std::ostream& out, const Bilet& bilet); //supraincarcare << - afisare

        std::string DescriereText() const override;
        std::string GetIdText() const override;
        void Afisare() const override;

    private:
        std::string m_id;
        std::string m_clasa;
        int m_pret_final;
    };

}

#endif
