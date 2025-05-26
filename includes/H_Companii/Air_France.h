#ifndef AIR_FRANCE_H
#define AIR_FRANCE_H

#include "Companie.h"

namespace Transport_Aerian {

    class AirFrance : public Companie {
    public:
        AirFrance();

        float CalculPretFinal(float pret_baza) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj() const override;
    };

}

#endif
