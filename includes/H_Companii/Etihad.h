#ifndef ETIHAD_H
#define ETIHAD_H

#include "Companie.h"

namespace Transport_Aerian {

    class Etihad : public Companie {
    public:
        Etihad();

        float CalculPretFinal(float pret_baza) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj() const override;
    };

}

#endif
