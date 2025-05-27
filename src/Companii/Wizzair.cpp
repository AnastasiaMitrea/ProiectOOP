#include "../includes/H_Companii/Wizz_Air.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

WizzAir::WizzAir() : Companie("WizzAir", "Ungaria") {}

float WizzAir::CalculPretCompanie(float pret_baza, const std::string& clasa) const {
    float p = pret_baza * 1.3f; // 30% taxa baza
    if (clasa == "business")
        return p * 1.65f;   //inca 65%
    return p;
}

std::string WizzAir::GetPoliticaBagaj(const std::string& clasa) const {
    if (clasa == "business")
        return "1 bagaj mic + bagaj de cabina + bagaj de cala. Prioritate si check-in rapid.";
    return "1 bagaj mic gratuit (max 40x30x20cm). Bagaj de cabina si cala contra cost.";
}


void WizzAir::AfiseazaZboruriOferite() const {
    cout << "=== WizzAir - Zboruri low-cost disponibile ===" << endl << endl;

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

std::string WizzAir::GetPrefixZbor() const { return "WZ"; }
