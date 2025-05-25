#include "..\includes\Persoana.h"

using namespace Transport_Aerian;
using namespace std;

//constructor default
Persoana::Persoana() : m_nume(""), m_prenume(""), m_cnp(""), m_varsta(0) {}

/*
//constructor cu parametri
Persoana::Persoana(const string& nume, const string& prenume,
                   const string& cnp, int varsta)
    : m_nume(nume), m_prenume(prenume), m_cnp(cnp), m_varsta(varsta) {
    if (!_ValidareCNP(m_cnp)) {
        throw invalid_argument("CNP invalid!");
    }
}*/

//constructor cu parametri
Persoana::Persoana(const string& nume, const string& prenume,
                   const string& cnp)
    : m_nume(nume), m_prenume(prenume), m_cnp(cnp) {
    if (!_ValidareCNP(m_cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    m_varsta=_ExtrageVarstaCnp(cnp);
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
    if (!_ValidareCNP(cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    m_cnp = cnp;
}
void Persoana::SetVarsta(int varsta) { m_varsta = varsta; }

//metoda validare CNP
bool Persoana::_ValidareCNP(const string& cnp) const {
    bool lungime = (cnp.length() == 13);
    bool dataValida = cnp[1];
}

int Persoana::_CharToInt(char c){
    int dif=(int)'0';
    return c-dif;
}

int Persoana::_ExtrageVarstaCnp(string cnp){
    time_t t = time(nullptr); // obtine timpul curent cu <ctime>
    tm* timp_local = localtime(&t);  //conversie la timp local

    int ziCurenta = timp_local->tm_mday;
    int lunaCurenta = timp_local->tm_mon + 1; // (ianuarie=0 in ctime)
    int anCurent = timp_local->tm_year + 1900; //anii sunt numarati de la 1 incepand cu 1901
     
    int zeci = _CharToInt(cnp[1])*10; //extragere zeci din cnp
    int unitati = _CharToInt(cnp[2]); //extragere unitati din cnp
    int anNastere = zeci + unitati; //ultimele 2 cifre din anul nasterii
    if(_CharToInt(cnp[1]) > 2){  //daca cifra zecilor e mai mare ca 2 => secolul 20
        anNastere += 1900;
    }
    else{  //daca cifra zecilor e mai mare ca 2 => secolul 21
        anNastere += 2000; 
    } 
    return anCurent-anNastere;
}

//supraincarcare operator <<
ostream& operator<<(ostream& out, const Persoana& p) {
    p.AfisareDate();
    return out;
}
