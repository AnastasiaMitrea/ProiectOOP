#include "..\includes\Persoana.h"

using namespace Transport_Aerian;
using namespace std;
using namespace Utilitati;

//constructor default
Persoana::Persoana() : m_nume(""), m_prenume(""), m_cnp(""), m_varsta(0), m_data_nasterii(Date()) {}

//constructor cu parametri --- fara varsta si dataNasterii deoarece se seteaza automat din cnp
Persoana::Persoana(const string& nume, const string& prenume,
                   const string& cnp)
    : m_nume(nume), m_prenume(prenume), m_cnp(cnp) {
    if (!_ValidareCNP(m_cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    m_data_nasterii = Persoana::_ExtrageDataNasterii(m_cnp);
    m_varsta = Calendar::CalculeazaVarsta(m_data_nasterii);
}

//constructor de copiere
Persoana::Persoana(const Persoana& other)
    : m_nume(other.m_nume), m_prenume(other.m_prenume),
      m_cnp(other.m_cnp), m_varsta(other.m_varsta), m_data_nasterii(other.m_data_nasterii) {}

//destructor
Persoana::~Persoana() {}

//getteri
string Persoana::GetNume() const { return m_nume; }
string Persoana::GetPrenume() const { return m_prenume; }
string Persoana::GetCNP() const { return m_cnp; }
int Persoana::GetVarsta() const { return m_varsta; }
Date Persoana::GetDataNasterii() const { return m_data_nasterii; }

//setteri
void Persoana::SetNume(const string& nume) { m_nume = nume; }
void Persoana::SetPrenume(const string& prenume) { m_prenume = prenume; }
void Persoana::SetCNP(const string& cnp) {
    if (!_ValidareCNP(cnp)) {
        throw invalid_argument("CNP invalid!");
    }
    m_cnp = cnp;
    m_data_nasterii = Persoana::_ExtrageDataNasterii(m_cnp);
    m_varsta = Calendar::CalculeazaVarsta(m_data_nasterii);
}

Utilitati::Date Persoana::_ExtrageDataNasterii(const string& cnp) const {
    int sex = CharToInt(cnp[0]);
    int secol;

    if(sex == 1 || sex == 2)  //barbat/femeie intre 1900-1999
        secol = 1900;
    else if(sex == 5 || sex == 6)  //barbat/femeie intre 2000-2099
        secol = 2000;
    else
        return Utilitati::Date(0, 0, 0); // data invalida sau persoana nascuta inainte de 1900 - imposibil

    int an = secol + CharToInt(cnp[1]) * 10 + CharToInt(cnp[2]);
    int luna = CharToInt(cnp[3]) * 10 + CharToInt(cnp[4]);
    int zi = CharToInt(cnp[5]) * 10 + CharToInt(cnp[6]);

    // validare data optionala
    if(!Calendar::EsteDataValida(Utilitati::Date(zi, luna, an)))
        return Utilitati::Date(0, 0, 0); // data invalida

    return Utilitati::Date(zi, luna, an);
}

//metoda validare CNP
bool Persoana::_ValidareCNP(const string& cnp) const {
    if(cnp.length() != 13)  //un cnp are lungime de 13 caractere
        return false;

    char sex = cnp[0];
    if(sex < '1' || sex > '6') //prima cifra intr-un cnp are valori intre 1 si 6 
        return false;

    Utilitati::Date dataNasterii = _ExtrageDataNasterii(cnp);
    if (!Calendar::EsteDataValida(dataNasterii)) 
        return false;
    int varsta = Calendar::CalculeazaVarsta(dataNasterii);
    return varsta > 0 && varsta <= 120;  //am limitat varsta maxima posibila la 120 ani
}

