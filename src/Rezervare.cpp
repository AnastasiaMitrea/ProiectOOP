#include "../includes/Rezervare.h"
#include <iostream>

using namespace std;
using namespace Transport_Aerian;

Rezervare::Rezervare(const Pasager& pasager, Zbor* zbor, const std::vector<Pilot*>& echipaj, Companie* companie)
    : m_pasager(pasager), m_zbor(zbor), m_echipaj(echipaj), m_companie(companie) {}

Rezervare::~Rezervare() {}

void Rezervare::Afisare() const {
    cout << "=== REZERVARE ===" << endl;
    m_pasager.Afisare();   //pasagerul + biletul
    cout << endl;

    if (m_zbor)
        cout << *m_zbor << endl;        //detalii zbor rezervat

    cout << "Echipaj piloti:" << endl;   //afisez pilotii asignati zborului
    for (const auto& p : m_echipaj)
        if (p) 
            p->Afisare();

    if (m_companie)
        cout << endl << "Va multumim pentru ca ati ales sa zburati cu noi. " << m_companie->GetNume() << " va doreste o calatorie placuta!" << endl;
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

    if (m_companie)
        text += "Companie: " + m_companie->GetNume() + "\n";

    return text;
}

std::string Rezervare::GetIdText() const {
    return m_pasager.GetBilet().GetId(); 
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
Companie* Rezervare::GetCompanie() const { 
    return m_companie; 
}

void Rezervare::ScriePeStream(std::ostream& os) const {
    os << "Pasager: " << m_pasager.GetNume() << " " << m_pasager.GetPrenume() 
       << " (CNP: " << m_pasager.GetCNP() << ")\n";

    os << "Zbor: " << m_zbor->GetId() 
       << " | Ruta: " << m_zbor->GetPlecare() 
       << " -> " << m_zbor->GetDestinatie() << "\n";

    os << "Data: " << m_zbor->GetDataPlecare()
       << ", Ora: " << std::setw(2) << std::setfill('0') << m_zbor->GetOraPlecare().ora
       << ":" << std::setw(2) << std::setfill('0') << m_zbor->GetOraPlecare().minut << "\n";

    os << "Clasa: " << m_pasager.GetBilet().GetClasa() << "\n";
    os << "Pret: " << m_pasager.GetBilet().GetPret() << " EUR\n";

    os << "Echipaj: ";
    for (size_t i = 0; i < m_echipaj.size(); ++i) {
        os << m_echipaj[i]->GetNume() << " " << m_echipaj[i]->GetPrenume();
        if (i != m_echipaj.size() - 1)
            os << ", ";
    }
    os << "\n";

    os << "Companie: " << m_companie->GetNume() << "\n";
}