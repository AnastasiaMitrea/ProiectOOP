#include <iostream>
#include <algorithm>
#include "includes/Bilet.h"
#include "includes/Calendar.h"
#include "includes/Pasager.h"
#include "includes/Persoana.h"
#include "includes/Zbor.h"
#include "includes/Companie.h"
#include "includes/Pilot.h"
#include "includes/Retea_zboruri.h"

using namespace std;
using namespace Transport_Aerian;

std::vector<Pilot*> SelecteazaEchipaj(Companie* companie, Zbor* zbor, const Retea_Rute& retea);

int main() {

    return 0;
}


std::vector<Pilot*> SelecteazaEchipaj(Companie* companie, Zbor* zbor, const Retea_Rute& retea) {
    std::vector<Pilot*> echipaj; //vector cu pilotii alocati
    int distanta = retea.GetDistanta(zbor->GetPlecare(), zbor->GetDestinatie());

    const std::vector<Pilot*>& piloti = companie->GetPiloti(); //lista de piloti din compania respectiva

    for (Pilot* p : piloti) {
        if (!p) continue; // verificare daca pointerul e nul

        // conditie pt a pilota zboruri lungi
        if (distanta > 1000) {
            if (p->GetVarsta() >= 35 && p->GetExperientaAni() >= 5)
                echipaj.push_back(p); 
        } else {
            // zbor scurt
            echipaj.push_back(p);
        }

        // oprim cand am gasit 2 piloti
        if (echipaj.size() == 2) break;
    }

    return echipaj; // returnam cei 2 piloti selectati (sau mai putini daca nu avem destui)
}

std::vector<Pilot*> SelecteazaEchipaj(Companie* companie, Zbor* zbor, const Retea_Rute& retea) {
    Pilot* piloti_valizi[30]; // maxim 30 piloti valizi
    int n_valizi = 0;  //nr real de piloti valizi

    int distanta = retea.GetDistanta(zbor->GetPlecare(), zbor->GetDestinatie());

    for (Pilot* p : companie->GetPiloti()) {
        if (!p)
            continue;

        //adaug pilotii in array in functie de distanta zborului - pt zboruri mai lungi de 1000km este nevoie de piloti experimentati
        if (distanta > 1000) {      
            if (p->GetVarsta() >= 30 && p->GetExperientaAni() >= 5)
                piloti_valizi[n_valizi++] = p;
        } else {
            piloti_valizi[n_valizi++] = p;
        }
    }

    std::vector<Pilot*> echipaj;

    if (n_valizi < 2) {
        for (int i = 0; i < n_valizi; ++i)
            echipaj.push_back(piloti_valizi[i]);
        return echipaj;
    }

    // alegem 2 indici random diferiti pt piloti
    int i1 = rand() % n_valizi;
    int i2= rand() % n_valizi;
    while (i2 == i1) {  
        i2 = rand() % n_valizi;
    } 

    //cei 2 piloti alesi random
    echipaj.push_back(piloti_valizi[i1]); 
    echipaj.push_back(piloti_valizi[i2]);

    return echipaj;
}

