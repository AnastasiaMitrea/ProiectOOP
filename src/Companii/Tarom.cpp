#include "../includes/H_Companii/Tarom.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

Tarom::Tarom() : Companie("TAROM", "Romania") {}

float Tarom::CalculPretFinal(float pret_baza) const {
    return pret_baza * 1.3f; // 30% taxa
}

std::string Tarom::GetPoliticaBagaj() const {
    return "1 bagaj de mana (max 10kg) + 1 bagaj de cala gratuit (23kg).";
}

void Tarom::AfiseazaZboruriOferite() const {
    cout << "--- TAROM - Uniti, oriunde am fi ---" << endl;
    cout << "Politica de bagaj: " << GetPoliticaBagaj() << endl << endl;

    for(const auto& zbor : GetZboruriOferite()) {
        if(zbor)
            cout << *zbor
                 << "Pret final (cu taxa): "
                 << CalculPretFinal(zbor->GetPret()) << " EUR"
                 << endl << endl;
    }
}
