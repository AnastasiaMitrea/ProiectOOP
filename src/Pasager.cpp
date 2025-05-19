#include <iostream>
#include "../includes/Pasager.h"

using namespace std;
using namespace Transport_Aerian;

int Pasager::m_numar_pasageri = 0; //initializare contor pasageri

//constructorul default
Pasager::Pasager() : Persoana(), m_bilet(Bilet()){
    _IncrementareContor();      //m_bilet(Bilet()) - initializeaza m_bilet cu un obiect de tip Bilet temporar
                                //m_bilet = Bilet() ar fi o initializare gresita pt ca ar apela constructorul de copiere
}

//constructor parametrizat
Pasager::Pasager(const string& nume, const string& prenume, const string& cnp, int varsta, const Bilet& bilet)
    : Persoana(nume, prenume, cnp, varsta), m_bilet(bilet) {
    _IncrementareContor();  //creste contorul de pasageri cand un nou obiect este creat
}

//copy constructor
Pasager::Pasager(const Pasager& other)
    : Persoana(other), m_bilet(other.m_bilet), m_zboruri(other.m_zboruri){
    _IncrementareContor();  //creste contorul de pasageri cand un nou obiect este creat
}

//destructtor
Pasager::~Pasager() {} //vectorul de zboruri se va goli automat la distrugerea obiectului Pasager

//metoda suprascrisa din clasa de baza care afiseaza datele pasagerului
void Pasager::AfisareDate() const {
    cout<<"Pasager: "<<GetNume()<<" "<<GetPrenume()<<endl;
    cout<<"CNP: "<<GetCNP()<<endl;
    cout<<"Varsta: "<<GetVarsta()<<endl;
    cout<<"Bilet: "<<m_bilet<<endl<<endl;
    cout<<"Zboruri asociate pasagerului: "<<endl<<endl;

    for(const auto& zbor : m_zboruri) { //parcurg vectorul de zboruri
        if(zbor != nullptr) {  //verific daca pointerul este valid
            cout<<*zbor<<endl; //apelam operatorul << supraincarcat in clasa zbor
        }  //afisez fiecare zbor
    }
}

//metoda care adauga un zbor in lista de zboruri a pasagerului
void Pasager::AdaugaZbor(Zbor* zbor) {
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
        nou.AdaugaZbor(zbor);  
    }
    return nou; 
}

namespace Transport_Aerian{
    //supraincare operator << pt a afisa pasagerul
    ostream& operator<<(ostream& out, const Pasager& pasager) {
        pasager.AfisareDate(); //apelez metoda de afisare a datelor
        return out;
    }
}

//metoda privata care creste contorul de pasageri
void Pasager::_IncrementareContor() {
    m_numar_pasageri++; 
}