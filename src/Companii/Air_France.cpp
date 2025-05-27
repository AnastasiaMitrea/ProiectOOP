#include "../includes/H_Companii/Air_France.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

AirFrance::AirFrance() : Companie("Air France", "Franta") {}

float AirFrance::CalculPretCompanie(float pret_baza, const std::string& clasa) const {
    float p = pret_baza * 1.7f; // 70% taxa baza
    if (clasa == "business")
        return p * 1.75f;   //inca 75%
    return p;
}

std::string AirFrance::GetPoliticaBagaj(const std::string& clasa) const {
    if (clasa == "business")
        return "2 bagaje de mana + 2 bagaje de cala (32kg fiecare). Acces la business lounge, masa premium.";
    return "1 bagaj de mana (12kg) + 1 bagaj de cala (23kg). Masa calda si bauturi incluse.";
}


void AirFrance::AfiseazaZboruriOferite() const {  
    cout << "*** Air France - Eleganta in zbor ***" << endl << endl;
    
    for (const auto& zbor : GetZboruriOferite()) {   //afisez lista de zboruri oferite de companie
        if (!zbor) 
            continue;
        cout << *zbor;

        // pentru fiecare clasa, afisez politica + pret
        for (const string& clasa : {"economic", "business"}) {
            cout << "Clasa: " << clasa << endl;
            cout << "Politica bagaj: " << GetPoliticaBagaj(clasa) << endl;
            cout << "Pret final: " << CalculPretCompanie(zbor->GetPret(), clasa) << " EUR" << endl << endl;
        }

        cout << "----------------------------------------------------" << endl << endl;
    }
}


std::string AirFrance::GetPrefixZbor() const { return "AF"; }