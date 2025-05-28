#ifndef FORMULAR_H
#define FORMULAR_H

#include <iostream>
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

    Formular() : nume(""), prenume(""), cnp(""), plecare(""), destinatie(""), data_zbor(0, 0, 0), clasa("") {}
};

Formular ColecteazaFormular() {
    Formular f;
    std::string tmp;
}

void AfiseazaFormular(const Formular& f) {
    system("cls");   //dau clear screen la fiecare camp completat pentru a crea senzatia de actualizare instanta in formular
    std::cout << "=========== FORMULAR DE REZERVARE ===========\n\n";
    std::cout << "Nume           > " << (f.nume.empty() ? "" : f.nume) << "\n";     //if nume == gol, pune "", else pune f.nume (la fel si mai jos)
    std::cout << "Prenume        > " << (f.prenume.empty() ? "" : f.prenume) << "\n";
    std::cout << "CNP            > " << (f.cnp.empty() ? "" : f.cnp) << "\n";
    std::cout << "Plecare din    > " << (f.plecare.empty() ? "" : f.plecare) << "\n";
    std::cout << "Destinatie     > " << (f.destinatie.empty() ? "" : f.destinatie) << "\n";
    std::cout << "Data zborului  > " << (f.data_zbor.empty() ? "" : f.data_zbor) << "\n";
    std::cout << "Clasa dorita   > " << (f.clasa.empty() ? "" : f.clasa) << "\n";
    std::cout << "\n=============================================\n";
}


    AfiseazaFormular(f);
    std::cout << "Completeaza campul: Nume > "; 
    std::getline(std::cin, f.nume);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: Prenume > "; 
    std::getline(std::cin, f.prenume);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: CNP > "; 
    std::getline(std::cin, f.cnp);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: Plecare din > "; 
    std::getline(std::cin, f.plecare);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: Destinatie > "; 
    std::getline(std::cin, f.destinatie);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: Data zborului (DD.MM.YYYY) > "; 
    std::getline(std::cin, f.data_zbor);

    AfiseazaFormular(f); 
    std::cout << "Completeaza campul: Clasa dorita (economic/business) > "; 
    std::getline(std::cin, f.clasa);



    AfiseazaFormular(f); //toate campurile sunt completate
    std::cout << "Formular complet. Apasa Enter pentru a continua..."; std::getline(std::cin, tmp);

    return f;
}



#endif