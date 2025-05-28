#ifndef FORMULAR_H
#define FORMULAR_H

#include <string>
#include "Date.h"

namespace Utilitati {

    struct Formular {
        std::string nume;
        std::string prenume;
        std::string cnp;
        std::string plecare;
        std::string destinatie;
        Date data_zbor;
        std::string clasa;

        Formular();

        
    };

    Formular Utilitati::ColecteazaFormular();
    void Utilitati::AfiseazaFormular(const Formular& f);

}

#endif
