#include "..\includes\Persoana.h"
using namespace std;

//constructor default
Persoana::Persoana() : nume(""), prenume(""), cnp(""), varsta(0) {}

//constructor cu parametri
Persoana::Persoana(const string& nume, const string& prenume,
                   const string& cnp, int varsta)
    : nume(nume), prenume(prenume), cnp(cnp), varsta(varsta) {
    if (!validareCNP(cnp)) {
        throw invalid_argument("CNP invalid!");
    }
}

//constructor de copiere
Persoana::Persoana(const Persoana& other)
    : nume(other.nume), prenume(other.prenume),
      cnp(other.cnp), varsta(other.varsta) {}

//destructor
Persoana::~Persoana() {}

//getteri
string Persoana::getNume() const { return nume; }
string Persoana::getPrenume() const { return prenume; }
string Persoana::getCNP() const { return cnp; }
int Persoana::getVarsta() const { return varsta; }

//setteri
void Persoana::setNume(const string& nume) { this->nume = nume; }
void Persoana::setPrenume(const string& prenume) { this->prenume = prenume; }
void Persoana::setCNP(const string& cnp) {
    if (!validareCNP(cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    this->cnp = cnp;
}
void Persoana::setVarsta(int varsta) { this->varsta = varsta; }

//metoda validare CNP
bool Persoana::validareCNP(const string& cnp) const {
    return cnp.length() == 13;
}

//supraincarcare operator <<
ostream& operator<<(ostream& out, const Persoana& p) {
    p.afisareDate();
    return out;
}
