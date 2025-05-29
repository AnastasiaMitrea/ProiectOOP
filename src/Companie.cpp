#include "../includes/Companie.h"

using namespace Transport_Aerian;
using namespace std;

// constructor default
Companie::Companie() : m_nume("NECUNOSCUT"), m_tara_origine("NECUNOSCUTA") {}

// constructor cu parametri
Companie::Companie(const std::string& nume, const std::string& tara_origine)
    : m_nume(nume), m_tara_origine(tara_origine) {}

Companie::~Companie() {
    for (Pilot* p : m_piloti)
        delete p;

    for (Zbor* z : m_zboruri_oferite)
        delete z;
}


string Companie::GenereazaIdZbor() {
    string prefix = GetPrefixZbor();

    int numar = ++m_contor_zboruri_pe_companie[m_nume]; // incrementam contorul per companie

    std::ostringstream id;
    id << prefix << std::setw(3) << std::setfill('0') << numar; // ex: WZ001, RO012 etc.

    return id.str();
}
/*
    prefix = primele 2 litere din numele companiei
    setw(3) - urmatorul lucru scris trebuie sa ocupe 3 caractere
    setfill(0) - completeaza cu 0 care e un singur caracter - deci este fortat de setw(3) sa mai ocupe inca 2 caractere
    numar = contorul 
    
    id = WZ003 - al 3 lea bilet cumparat la Wizz air
*/

// adauga zbor in lista companiei
void Companie::AdaugaZbor(Zbor* zbor) {
    if(zbor)
        m_zboruri_oferite.push_back(zbor);
}

// getteri
std::string Companie::GetNume() const {
    return m_nume;
}

std::string Companie::GetTaraOrigine() const {
    return m_tara_origine;
}

const std::vector<Zbor*>& Companie::GetZboruriOferite() const {
    return m_zboruri_oferite;
}

void Companie::AdaugaPilot(Pilot* pilot) {
    if (pilot)
        m_piloti.push_back(pilot);
}

const std::vector<Pilot*>& Companie::GetPiloti() const {
    return m_piloti;
}
