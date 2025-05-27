#include "../includes/H_Companii/Etihad.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

Etihad::Etihad() : Companie("Etihad Airways", "Emiratele Arabe Unite") {}

float Etihad::CalculPretCompanie(float pret_baza, const std::string& clasa) const {
    float p = pret_baza * 2.8f; // 180% taxa baza
    if (clasa == "business")
        return p * 1.95f;   //inca 95%
    return p;
}

std::string Etihad::GetPoliticaBagaj(const std::string& clasa) const {
    if (clasa == "business")
        return "2 bagaje de cala (32kg fiecare) + 2 bagaje de mana + fast track + scaun flatbed.";
    return "2 bagaje de cala (23kg fiecare) + bagaj de mana 12kg + catering fine-dining inclus.";
}


void Etihad::AfiseazaZboruriOferite() const {
    cout << "~~~ Etihad Airways - Lux si Confort la Altitudine ~~~" << endl << endl;

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


std::string Etihad::GetPrefixZbor() const { return "EY"; }