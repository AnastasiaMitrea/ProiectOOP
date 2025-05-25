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
        ~Companie();

        // metode
        void AdaugaZbor(Zbor* zbor);
        void AfiseazaZboruriOferite() const;

        // getteri
        std::string GetNume() const;
        std::string GetTaraOrigine() const;
        const std::vector<Zbor*>& GetZboruriOferite() const;

    private:
        std::string m_nume;
        std::string m_tara_origine;
        std::vector<Zbor*> m_zboruri_oferite;
    };

}

#endif
