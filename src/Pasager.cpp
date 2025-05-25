#include <iostream>
#include "../includes/Pasager.h"

using namespace std;
using namespace Transport_Aerian;

int Pasager::m_numar_pasageri = 0; //initializare contor pasageri

//constructorul default
Pasager::Pasager() : Persoana(), m_bilet(Bilet()){}    //m_bilet(Bilet()) - initializeaza m_bilet cu un obiect de tip Bilet temporar
                                                    //m_bilet = Bilet() ar fi o initializare gresita pt ca ar apela constructorul de copiere

//constructor parametrizat
Pasager::Pasager(const string& nume, const string& prenume, const string& cnp, int varsta, const Bilet& bilet)
    : Persoana(nume, prenume, cnp), m_bilet(bilet) {}

//copy constructor
Pasager::Pasager(const Pasager& other)
    : Persoana(other), m_bilet(other.m_bilet), m_zboruri(other.m_zboruri){}

//destructtor
Pasager::~Pasager() {} //vectorul de zboruri se va goli automat la distrugerea obiectului Pasager

std::string Pasager::DescriereText() const {
    return "Pasager " + GetNume() + " " + GetPrenume() + " (CNP: " + GetCNP() + ")";  //concatenare de string uri cu + din c++
}

std::string Pasager::GetIdText() const {
    return GetCNP();            //id ul specific pasagerului
}

void Pasager::Afisare() const {
    std::cout << DescriereText() << std::endl;
    std::cout << "Varsta: " << GetVarsta() << std::endl;
    std::cout << "Bilet: " << GetBilet() << std::endl;

    std::cout << "Zboruri asociate:\n";
    for(const auto& zbor : m_zboruri) {
        if(zbor)
            std::cout << *zbor << std::endl;
    }
}

//metoda care adauga un zbor in lista de zboruri a pasagerului
void Pasager::AdaugaZborIstoric(Zbor* zbor) {
    if(zbor != nullptr) {          //verific daca pointerul este valid
        m_zboruri.push_back(zbor); 
    }
}

//metoda statica care returneaza nr pasageri 
int Pasager::GetNumarPasageri(){
    return m_numar_pasageri; 
}

const Bilet& Pasager::GetBilet() const {
    return m_bilet; //returnez biletul asociat pasagerului
}

//getter pt vectorul de zboruri
const vector<Zbor*>& Pasager::GetZboruri() const {
    return m_zboruri; 
}

//supraincarcare operator + pt a adauga un zbor
Pasager Pasager::operator+(Zbor* zbor) const {
    Pasager nou(*this);         //creez un nou pasager care este o copie a obiectului curent
    if(zbor!=nullptr) {        //verific daca pointerul este valid
        nou.AdaugaZborIstoric(zbor);  
    }
    return nou; 
}

