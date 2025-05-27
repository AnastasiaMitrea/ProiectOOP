#ifndef ETIHAD_H
#define ETIHAD_H

#include "Companie.h"

namespace Transport_Aerian {

    class Etihad : public Companie {
    public:
        Etihad();

        float CalculPretCompanie(float pret_baza, const std::string& clasa) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj(const std::string& clasa) const override;

        std::string GetPrefixZbor() const override;
    };

}

#endif
