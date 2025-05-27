#ifndef TAROM_H
#define TAROM_H

#include "Companie.h"

namespace Transport_Aerian {

    class Tarom : public Companie {
    public:
        Tarom();

        float CalculPretCompanie(float pret_baza, const std::string& clasa) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj(const std::string& clasa) const override;

        std::string GetPrefixZbor() const override;
    };

}

#endif
