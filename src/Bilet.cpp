#include "../includes/Bilet.h"
#include <iostream>

using namespace Transport_Aerian;
using namespace std;

//constructor default
Bilet::Bilet() : m_id("NECUNOSCUT"), m_clasa("economic"), m_pret(0) {}

//constructor cu parametri
Bilet::Bilet(const string& id, const string& clasa, int pret)
    : m_id(id), m_clasa(clasa), m_pret(pret) {}

//getteri si setteri
string Bilet::GetId() const{
    return m_id;
}

string Bilet::GetClasa() const{
    return m_clasa;
}

int Bilet::GetPret() const{
    return m_pret;
}

void Bilet::SetId(const string& id){
    m_id = id;
}

void Bilet::SetClasa(const string& clasa){
    m_clasa = clasa;
}

void Bilet::SetPret(int pret){
    m_pret = pret;
}

// afisare cu operator << supraincarcat
namespace Transport_Aerian {
    ostream& operator<<(ostream& out, const Bilet& bilet) {
    out << "[Bilet ID: " << bilet.m_id
        << ", Clasa: " << bilet.m_clasa
        << ", Pret: " << bilet.m_pret << " lei]";
    return out;
    }
}

