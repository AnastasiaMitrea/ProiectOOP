#include "../includes/pilot.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace Transport_Aerian;
using namespace Utilitati;

Pilot::Pilot() : Persoana(), m_an_incepere(0), m_experienta_ani(0) {}

Pilot::Pilot(const std::string& nume, const std::string& prenume, const std::string& cnp, int an_incepere)
    : Persoana(nume, prenume, cnp), m_an_incepere(an_incepere){
        _CalculeazaExperienta();
}

void Pilot::_CalculeazaExperienta() {
    int an_curent = Calendar::GetAnCurent();
    m_experienta_ani = an_curent - m_an_incepere;
    if (m_experienta_ani < 0) 
        m_experienta_ani = 0;
}

int Pilot::GetExperientaAni() const {
    return m_experienta_ani;
}

int Pilot::GetAnIncepere() const {
    return m_an_incepere;
}

void Pilot::Afisare() const {
    std::cout << "Pilot: " << GetNume() << " " << GetPrenume() << ", CNP: " << GetCNP()
              << ", Varsta: " << GetVarsta() << ", Experienta: " << GetExperientaAni() << " ani\n";
}

std::string Pilot::DescriereText() const {
    std::ostringstream os;
    os << "Pilot: " << GetNume() << " " << GetPrenume()
       << ", Varsta: " << GetVarsta()
       << ", Experienta: " << GetExperientaAni() << " ani";
    return os.str();
}

std::string Pilot::GetIdText() const {
    return GetCNP();  // sau orice identificator consideri relevant
}
