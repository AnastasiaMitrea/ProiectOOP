#include "../includes/Bilet.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

//constructor default
Bilet::Bilet() : m_id("NECUNOSCUT"), m_clasa("Economic"), m_pret_final(0) {}

//constructor cu parametri
Bilet::Bilet(const string& id, const string& clasa, int pret)
    : m_id(id), m_clasa(clasa), m_pret_final(pret) {}

//getteri si setteri
string Bilet::GetId() const{
    return m_id;
}

string Bilet::GetClasa() const{
    return m_clasa;
}

int Bilet::GetPret() const{
    return m_pret_final;
}

void Bilet::SetId(const string& id){
    m_id = id;
}

void Bilet::SetClasa(const string& clasa){
    m_clasa = clasa;
}

void Bilet::SetPret(int pret){
    m_pret_final = pret;
}

// afisare cu operator << supraincarcat
namespace Transport_Aerian {
    ostream& operator<<(ostream& out, const Bilet& bilet) {
        out<< "=== Bilet ===" << endl
        << "ID: " << bilet.m_id << endl
        << "Clasa: " << bilet.m_clasa << endl
        << "Pret: " << bilet.m_pret_final << " EURO" << endl;
    return out;
    }
}

std::string Bilet::DescriereText() const {
    return "Bilet ID: " + m_id + ", Clasa: " + m_clasa + ", Pret: " + std::to_string(m_pret_final) + " EURO";  //aici este returnat un string - il voi folosi ihn Rezervare
}

std::string Bilet::GetIdText() const {
    return m_id;
}

void Bilet::Afisare() const {                       //aici este un simplu cout in consola care se foloseste de operator<<
    cout << *this;
}

