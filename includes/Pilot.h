#ifndef PILOT_H
#define PILOT_H

#include "Persoana.h"
#include "../includes/calendar.h" 

namespace Transport_Aerian {

    class Pilot : public Persoana {
    public:
        Pilot();
        Pilot(const std::string& nume, const std::string& prenume, const std::string& cnp, int an_incepere, const std::string& companie);


        void Afisare() const override;
        int GetExperientaAni() const;
        int GetAnIncepere() const;
        std::string GetCompanie() const;

    private:
        int m_an_incepere;
        int m_experienta_ani;
        std::string m_companie;

        void _CalculeazaExperienta(); // metoda privata de actualizare
    };

} // namespace Transport_Aerian

#endif // PILOT_H
