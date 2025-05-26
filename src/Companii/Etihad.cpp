#include "../includes/H_Companii/Etihad.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

Etihad::Etihad() : Companie("Etihad Airways", "Emiratele Arabe Unite") {}

float Etihad::CalculPretFinal(float pret_baza) const {
    return pret_baza * 2.8f; // 180% taxa pentru servicii premium
}

std::string Etihad::GetPoliticaBagaj() const {
    return "2 bagaje de cala (23kg fiecare) + bagaj de mana 12kg + catering fine-dining inclus.";
}

void Etihad::AfiseazaZboruriOferite() const {
    cout << "~~~ Etihad Airways - Lux si Confort la Altitudine ~~~" << endl;
    cout << "Politica de bagaj: " << GetPoliticaBagaj() << endl << endl;

    for(const auto& zbor : GetZboruriOferite()) {
        if(zbor)
            cout << *zbor
                 << "Pret final (servicii premium incluse): "
                 << CalculPretFinal(zbor->GetPret()) << " EUR"
                 << endl << endl;
    }
}
