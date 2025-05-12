#include "..\includes\Persoana.h"

using namespace Transport_Aerian;
using namespace std;

//constructor default
Persoana::Persoana() : m_nume(""), m_prenume(""), m_cnp(""), m_varsta(0) {}

//constructor cu parametri
Persoana::Persoana(const string& nume, const string& prenume,
                   const string& cnp, int varsta)
    : m_nume(nume), m_prenume(prenume), m_cnp(cnp), m_varsta(varsta) {
    if (!ValidareCNP(m_cnp)) {
        throw invalid_argument("CNP invalid!");
    }
}

//constructor de copiere
Persoana::Persoana(const Persoana& other)
    : m_nume(other.m_nume), m_prenume(other.m_prenume),
      m_cnp(other.m_cnp), m_varsta(other.m_varsta) {}

//destructor
Persoana::~Persoana() {}

//getteri
string Persoana::GetNume() const { return m_nume; }
string Persoana::GetPrenume() const { return m_prenume; }
string Persoana::GetCNP() const { return m_cnp; }
int Persoana::GetVarsta() const { return m_varsta; }

//setteri
void Persoana::SetNume(const string& nume) { m_nume = nume; }
void Persoana::SetPrenume(const string& prenume) { m_prenume = prenume; }
void Persoana::SetCNP(const string& cnp) {
    if (!ValidareCNP(cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    m_cnp = cnp;
}
void Persoana::SetVarsta(int varsta) { m_varsta = varsta; }

//metoda validare CNP
bool Persoana::ValidareCNP(const string& cnp) const {
    return cnp.length() == 13;
}

//supraincarcare operator <<
ostream& operator<<(ostream& out, const Persoana& p) {
    p.AfisareDate();
    return out;
}
