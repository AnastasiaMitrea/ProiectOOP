#include "../includes/H_Companii/Air_France.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

AirFrance::AirFrance() : Companie("Air France", "Franta") {}

float AirFrance::CalculPretFinal(float pret_baza) const {
    return pret_baza * 1.7f; // 70% taxa 
}

std::string AirFrance::GetPoliticaBagaj() const {
    return "1 bagaj de mana (12kg) + 1 bagaj de cala (23kg). Masa calda si bauturi incluse.";
}

void AirFrance::AfiseazaZboruriOferite() const {
    cout << "*** Air France - Eleganta in zbor ***" << endl;
    cout << "Politica de bagaj: " << GetPoliticaBagaj() << endl << endl;

    for(const auto& zbor : GetZboruriOferite()) {
        if(zbor)
            cout << *zbor
                 << "Pret final (cu servicii incluse): "
                 << CalculPretFinal(zbor->GetPret()) << " EUR"
                 << endl << endl;
    }
}

std::string AirFrance::GetPrefixZbor() const { return "AF"; }