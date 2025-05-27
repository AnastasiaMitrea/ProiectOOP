#include "../includes/H_Companii/Tarom.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

Tarom::Tarom() : Companie("TAROM", "Romania") {}

float Tarom::CalculPretCompanie(float pret_baza, const std::string& clasa) const {
    float p = pret_baza * 1.8f; // 80% taxa baza
    if (clasa == "business")
        return p * 1.85f;   //inca 85%
    return p;
}

std::string Tarom::GetPoliticaBagaj(const std::string& clasa) const {
    if (clasa == "business")
        return "2 bagaje de cala (23kg fiecare) + bagaj de mana + acces lounge.";
    return "1 bagaj de mana (max 10kg) + 1 bagaj de cala gratuit (23kg).";
}


void Tarom::AfiseazaZboruriOferite() const {
    cout << "--- TAROM - Uniti, oriunde am fi ---" << endl << endl;

    for (const auto& zbor : GetZboruriOferite()) { //afisez lista de zboruri oferite de companie
        if (!zbor)
            continue;
        cout << *zbor;

        for (const string& clasa : {"economic", "business"}) {
            cout << "Clasa: " << clasa << endl;
            cout << "Politica bagaj: " << GetPoliticaBagaj(clasa) << endl;
            cout << "Pret final: " << CalculPretCompanie(zbor->GetPret(), clasa) << " EUR" << endl << endl;
        }

        cout << "----------------------------------------------------" << endl << endl;
    }
}


std::string Tarom::GetPrefixZbor() const { return "RO"; }