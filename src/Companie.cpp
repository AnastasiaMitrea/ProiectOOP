#include "../includes/Companie.h"

using namespace Transport_Aerian;
using namespace std;

// constructor default
Companie::Companie() : m_nume("NECUNOSCUT"), m_tara_origine("NECUNOSCUTA") {}

// constructor cu parametri
Companie::Companie(const std::string& nume, const std::string& tara_origine)
    : m_nume(nume), m_tara_origine(tara_origine) {}

Companie::~Companie() {}

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
