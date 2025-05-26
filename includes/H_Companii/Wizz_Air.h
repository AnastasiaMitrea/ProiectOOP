#ifndef WIZZAIR_H
#define WIZZAIR_H

#include "Companie.h"

namespace Transport_Aerian {

    class WizzAir : public Companie {
    public:
        WizzAir();

        float CalculPretFinal(float pret_baza) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj() const override;
    };

}

#endif
