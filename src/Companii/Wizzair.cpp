#include "../includes/H_Companii/Wizz_Air.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

WizzAir::WizzAir() : Companie("WizzAir", "Ungaria") {}

float WizzAir::CalculPretFinal(float pret_baza) const {
    return pret_baza * 1.2f; // 20% taxa 
}

string WizzAir::GetPoliticaBagaj() const {
    return "1 bagaj mic gratuit (max 40x30x20cm). Bagaj de cabina si cala contra cost.";
}

void WizzAir::AfiseazaZboruriOferite() const {
    cout << "=== WizzAir - Zboruri low-cost disponibile ===" << endl;
    cout << "Politica de bagaj: " << GetPoliticaBagaj() << endl << endl;

    for(const auto& zbor : GetZboruriOferite()) {
        if(zbor)
            cout << *zbor 
                 << "Pret final (cu taxa): " 
                 << CalculPretFinal(zbor->GetPret()) << " EUR"  << endl << endl;
    }
}
