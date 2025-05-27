#ifndef TAROM_H
#define TAROM_H

#include "Companie.h"

namespace Transport_Aerian {

    class Tarom : public Companie {
    public:
        Tarom();

        float CalculPretFinal(float pret_baza) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj() const override;

        std::string GetPrefixZbor() const override;
    };

}

#endif
