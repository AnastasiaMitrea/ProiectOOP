#ifndef AIR_FRANCE_H
#define AIR_FRANCE_H

#include "Companie.h"

namespace Transport_Aerian {

    class AirFrance : public Companie {
    public:
        AirFrance();

        float CalculPretCompanie(float pret_baza, const std::string& clasa) const override;
        void AfiseazaZboruriOferite() const override;
        std::string GetPoliticaBagaj(const std::string& clasa) const override;

        std::string GetPrefixZbor() const override;
    };

}

#endif
