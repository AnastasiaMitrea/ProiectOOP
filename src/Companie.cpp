#include "../includes/Companie.h"

using namespace Transport_Aerian;
using namespace std;

// constructor default
Companie::Companie() : m_nume("NECUNOSCUT"), m_tara_origine("NECUNOSCUTA") {}

// constructor cu parametri
Companie::Companie(const std::string& nume, const std::string& tara_origine)
    : m_nume(nume), m_tara_origine(tara_origine) {}

// adauga zbor in lista companiei
void Companie::AdaugaZbor(Zbor* zbor) {
    if(zbor)
        m_zboruri_oferite.push_back(zbor);
}

// afiseaza toate zborurile companiei
void Companie::AfiseazaZboruriOferite() const {
    cout << "Zborurile oferite de " << m_nume << " (" << m_tara_origine << "):" << endl << endl;
    for(const auto& z : m_zboruri_oferite) {
        if(z)
            cout << *z  << endl << endl;
    }
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
