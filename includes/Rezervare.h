#ifndef REZERVARE_H
#define REZERVARE_H

#include "Pasager.h"
#include "Zbor.h"
#include "Pilot.h"
#include "I_Afisabil.h"
#include "Companie.h"

namespace Transport_Aerian {

    class Rezervare : public Interfete::IAfisabil {
    public:
        Rezervare(const Pasager& pasager, Zbor* zbor, const std::vector<Pilot*>& echipaj, Companie* companie); 
        virtual ~Rezervare();

        void Afisare() const;
        std::string DescriereText() const;
        std::string GetIdText() const override;

        const Pasager& GetPasager() const;
        Zbor* GetZbor() const;
        const std::vector<Pilot*>& GetEchipaj() const;
        Companie* GetCompanie() const;


    private:
        Pasager m_pasager;
        Zbor* m_zbor;
        std::vector<Pilot*> m_echipaj;
        Companie* m_companie;
    };

}

#endif 
