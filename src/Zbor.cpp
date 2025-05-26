#include "../includes/Zbor.h"

using namespace Transport_Aerian;
using namespace std;
using namespace Utilitati;

Zbor::Zbor(std::string id, std::string plecare, std::string destinatie,
           Date data_plecare, Ora ora_plecare,
           Date data_sosire, Ora ora_sosire,
           int durata, int pret)
    : m_id(id), m_plecare(plecare), m_destinatie(destinatie),
      m_data_plecare(data_plecare), m_ora_plecare(ora_plecare),
      m_data_sosire(data_sosire), m_ora_sosire(ora_sosire),
      m_durata(durata), m_pret_ruta(pret) {}


namespace Transport_Aerian {
    std::ostream& operator<<(std::ostream& os, const Zbor& zbor) {
        os <<"ID zbor: "<< zbor.m_id <<endl
        << "Ruta: " << zbor.m_plecare << " ---> " << zbor.m_destinatie <<endl<<endl
        << "Plecare: " << zbor.m_data_plecare << "  " << zbor.m_ora_plecare <<endl
        << "Sosire: " << zbor.m_data_sosire << "  " << zbor.m_ora_sosire<<endl<<endl
        << "Durata: " << zbor.m_durata << " minute | "
        << "Pret: " << zbor.m_pret_ruta << " EUR"<<endl<<endl;
        return os;
    }
}

std::string Zbor::GetId() const {
    return m_id;
}

std::string Zbor::GetPlecare() const {
    return m_plecare;
}

std::string Zbor::GetDestinatie() const {
    return m_destinatie;
}

int Zbor::GetPret() const {
    return m_pret_ruta;
}

Ora Zbor::GetOraPlecare() const {
    return m_ora_plecare;
}

Ora Zbor::GetOraSosire() const {
    return m_ora_sosire;
}

Date Zbor::GetDataPlecare() const {
    return m_data_plecare;
}

Date Zbor::GetDataSosire() const {
    return m_data_sosire;
}

std::string Zbor::DescriereText() const {
    return "Zbor " + m_id + " | " + m_plecare + " -> " + m_destinatie;
}

std::string Zbor::GetIdText() const {
    return m_id;
}

void Zbor::Afisare() const {
    std::cout << *this << std::endl;   //folosire suprascrierea << din zbor 
}


std::string Zbor::GenereazaIdBilet(const std::string& clasa) {
    int numar = ++m_contor_bilete_per_clasa[clasa]; // accesez nr de bilete deja generate pt clasa, il incrementez si salvez in "numar"
                                                    //de ex daca sunt deja 4 bilete pt economic, se va crea urmatorul : E005
    char prefix = toupper(clasa[0]); // clasa = "economic" sau  "business" si extrag initiala pe care o transform in litera mare => E si B

    std::ostringstream id; // construiesc stringul final - folosesc un ostream in care stochez direct continutul in loc sa concatenez mai multe string uri
    id << prefix << std::setw(3) << std::setfill('0') << numar; 

    return id.str();   //id este un stream in care am continutul final si il returnez tip string .str()  
    
}

    /*
        prefix = E / B
        setw(3) - urmatorul lucru scris trebuie sa ocupe 3 caractere
        setfill(0) - completeaza cu 0 care e un singur caracter - deci este fortat de setw(3) sa mai ocupe inca 2 caractere
        numar = nr biletului 
        
        id = E003 - al 3 lea bilet cumparat la clasa Economic
    */

