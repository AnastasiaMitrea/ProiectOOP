#ifndef FORMULAR_H
#define FORMULAR_H

#include "utils.h"
#include <iostream>
#include <sstream>
#include <string>
#include "date.h"

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

    Formular ColecteazaFormular();
    void AfiseazaFormular(const Formular& f);
}

#endif
