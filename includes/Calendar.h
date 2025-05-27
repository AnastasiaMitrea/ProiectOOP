#ifndef CALENDAR_H
#define CALENDAR_H

#include <ctime>
#include "Date.h"
#include "Ora.h"

namespace Utilitati{

class Calendar {
    public:
        static void Initializare();
        static bool EsteDataValida(Date data); //pt nu a avea o data gen 31 februarie
        static int CalculeazaVarsta(Date data);  //calcul automat din cnp
        static bool EsteAnBisect(int an);

        static Date GetDataInitializare();
        static Ora GetOraInitializare();
        static int GetAnCurent();
        static int GetLunaCurenta();
        static int GetZiCurenta();
        static Date GetDataCurenta();    
        static std::pair<Ora, int> AdaugaMinuteLaOra(const Ora& ora_initiala, int minute_de_adaugat);


    private:
        static Date m_data_initializare; //momentul deschiderii aplicatiei
        static Ora m_ora_initializare;
    };
}

#endif 
