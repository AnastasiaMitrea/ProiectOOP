#include "../includes/rezervare.h"
#include <iostream>

using namespace std;
using namespace Transport_Aerian;

Rezervare::Rezervare(const Pasager& pasager, Zbor* zbor, const std::vector<Pilot*>& echipaj)
    : m_pasager(pasager), m_zbor(zbor), m_echipaj(echipaj) {}

Rezervare::~Rezervare() {}

void Rezervare::Afisare() const {
    cout << "=== REZERVARE ===" << endl;
    m_pasager.Afisare();   //pasagerul + biletul
    cout << endl;

    if (m_zbor)
        cout << *m_zbor << endl;        //detalii zbor rezervat

    cout << "Echipaj piloti:" << endl;   //afisez pilotii asignati zborului
    for (const auto& p : m_echipaj)
        if (p) p->Afisare();

    cout << "Va multumim pentru ca ati ales sa zburati cu noi. Calatorie placuta! --- " << m_zbor.GetCompanie() << endl;
    cout << "===================" << endl;
}

std::string Rezervare::DescriereText() const {
    std::string text = m_pasager.DescriereText() + "\n";
    text += m_pasager.GetBilet().DescriereText() + "\n";
    if (m_zbor)
        text += "Ruta: " + m_zbor->GetPlecare() + " → " + m_zbor->GetDestinatie() + "\n";

    text += "Echipaj:\n";
    for (const auto& p : m_echipaj)
        if (p)
            text += " - " + p->GetNume() + " " + p->GetPrenume() + "\n";

    return text;
}

const Pasager& Rezervare::GetPasager() const {
    return m_pasager;
}

Zbor* Rezervare::GetZbor() const {
    return m_zbor;
}

const std::vector<Pilot*>& Rezervare::GetEchipaj() const {
    return m_echipaj;
}
