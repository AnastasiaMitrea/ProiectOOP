#ifndef COMPANIE_H
#define COMPANIE_H

#include <string>
#include <vector>
#include <iostream>
#include "Zbor.h"

namespace Transport_Aerian {

    class Companie {
    public:
        // constructori
        Companie();
        Companie(const std::string& nume, const std::string& tara_origine);
        virtual ~Companie();

        // getteri
        std::string GetNume() const;
        std::string GetTaraOrigine() const;
        const std::vector<Zbor*>& GetZboruriOferite() const;

        std::string GenereazaIdZbor(); // genereaza un id unic pt fiecare zbor
        void AdaugaZbor(Zbor* zbor);        
        virtual void AfiseazaZboruriOferite() const = 0; //va fi un mesaj afisat diferit in functie de companie
        virtual float CalculPretCompanie(float pret_baza, const std::string& clasa) const = 0;   //preturile difera in functie de companii
        virtual std::string GetPoliticaBagaj(const std::string& clasa) const = 0; //fiecare companie are o politica      
        virtual std::string GetPrefixZbor() const = 0; // prefix ul fiecarei companii

    private:
        std::string m_nume;
        std::string m_tara_origine;
        std::vector<Zbor*> m_zboruri_oferite;
        std::map<std::string, int> m_contor_zboruri_pe_companie;
    };

}

#endif
