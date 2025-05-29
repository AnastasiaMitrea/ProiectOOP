#include "Formular.h"
#include "Date.h"
#include "Persoana.h"
#include "Utils.h"
#include <iostream>
#include <sstream>  //pt sscanf

using namespace std;
using namespace Utilitati;
using namespace Transport_Aerian;

namespace Utilitati {

    Formular::Formular()
        : nume(""), prenume(""), cnp(""), plecare(""), destinatie(""), data_zbor(0, 0, 0), clasa("") {}

    void AfiseazaFormular(const Formular& f) {
        system("cls");  //sterg ecranul la fiecare pas pt a crea iluzia de actualizare instanta dupa completarea fiecarui camp
        cout << "=========== FORMULAR DE REZERVARE ===========\n\n";
        cout << "Nume           > " << f.nume << "\n";
        cout << "Prenume        > " << f.prenume << "\n";
        cout << "CNP            > " << f.cnp << "\n";
        cout << "Plecare din    > " << f.plecare << "\n";
        cout << "Destinatie     > " << f.destinatie << "\n";
        if (f.data_zbor.GetZi() != 0)  //daca a fost completata data zborului 
            cout << "Data zborului  > " << f.data_zbor << "\n";
        else
            cout << "Data zborului  > \n";
        cout << "Clasa dorita   > " << f.clasa << "\n";
        cout << "\n=============================================\n";
    }

    Formular ColecteazaFormular() {
        Formular f;
        string tmp;

        do{
            Utilitati::AfiseazaFormular(f); cout << "Completeaza campul: Nume > "; 
            getline(cin, f.nume);
            if (ContineCifre(f.nume))
                std::cout << "Numele nu poate contine cifre. Incearca din nou.\n";
        } while (f.nume.empty());
        do{
            Utilitati::AfiseazaFormular(f); cout << "Completeaza campul: Prenume > "; 
            getline(cin, f.prenume);
            if (ContineCifre(f.prenume))
            std::cout << "Prenumele nu poate contine cifre. Incearca din nou.\n";
        } while (f.prenume.empty());
        do{
            Utilitati::AfiseazaFormular(f); cout << "Completeaza campul: CNP > "; 
            getline(cin, f.cnp);
            if (!Persoana::ValidareCNP(f.cnp)) {
                cout << "CNP invalid! Asigura-te ca are 13 cifre si este complet numeric.\n";
            }
        } while (f.cnp.empty() || !Persoana::ValidareCNP(f.cnp));
        do{
            Utilitati::AfiseazaFormular(f); cout << "Completeaza campul: Plecare din > "; 
            getline(cin, f.plecare);
            if (ContineCifre(f.plecare))
                std::cout << "Numele orasului nu poate contine cifre. Incearca din nou.\n";
        } while (f.plecare.empty());
        do{
            Utilitati::AfiseazaFormular(f); cout << "Completeaza campul: Destinatie > "; 
            getline(cin, f.destinatie);
            if (ContineCifre(f.destinatie))
                std::cout << "Numele orasului nu poate contine cifre. Incearca din nou.\n";
        } while (f.destinatie.empty());

        bool data_valida = false;
        while (!data_valida) {  
            Utilitati::AfiseazaFormular(f);
            std::cout << "Completeaza campul: Data zborului (DD.MM.YYYY) > ";
            std::string data_str;
            std::getline(std::cin, data_str);
            int zi, luna, an;
            if (sscanf(data_str.c_str(), "%d.%d.%d", &zi, &luna, &an) == 3) {
                f.data_zbor = Date(zi, luna, an);
                data_valida = true;
            }
        }

        do {
            Utilitati::AfiseazaFormular(f);
            std::cout << "Completeaza campul: Clasa dorita (economic/business) > ";
            std::getline(std::cin, f.clasa);
            if(f.clasa != "economic" && f.clasa != "business")
                cout << "Clasa dorita trebuie sa fie 'economic' sau 'business' > ";
        } while (f.clasa.empty() && (f.clasa != "economic" && f.clasa != "business"));

        Utilitati::AfiseazaFormular(f);
        std::cout << "Formular complet. Apasa Enter pentru a continua...";  //merge orice tasta apasata
        std::getline(std::cin, tmp);

        return f;
    }

}