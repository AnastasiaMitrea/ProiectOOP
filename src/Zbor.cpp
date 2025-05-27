#include "../includes/Zbor.h"

using namespace Transport_Aerian;
using namespace std;
using namespace Utilitati;

Zbor::Zbor(std::string plecare, std::string destinatie, Date data_plecare, Ora ora_plecare, const Retea_Rute& retea)
    : m_plecare(plecare), m_destinatie(destinatie), m_data_plecare(data_plecare), m_ora_plecare(ora_plecare) {

        m_durata = retea.CalculeazaDurata(m_plecare, m_destinatie);
        m_pret_ruta = retea.CalculeazaPretBaza(m_plecare, m_destinatie);

        auto rezultat = Calendar::AdaugaMinuteLaOra(m_ora_plecare, m_durata);
        m_ora_sosire = rezultat.first; //first este Ora 

        m_data_sosire = m_data_plecare;
        m_data_sosire.zi += rezultat.second; //second este zile_in_plus
 
        while (!Utilitati::Calendar::EsteDataValida(m_data_sosire)) {  //in caz ca data sosirii calculata este invalida: ex 30 februarie
            m_data_sosire.zi = 1;            //daca intra in while inseamna ca data este invalida, deci s-a trecut la luna urmatoare (ex 31 aprilie => 1 mai)
            m_data_sosire.luna++;
            if (m_data_sosire.luna > 12) {      //in cazul 32 decembrie
                m_data_sosire.luna = 1;
                m_data_sosire.an++;
            }
        }
    }

namespace Transport_Aerian {
    std::ostream& operator<<(std::ostream& os, const Zbor& zbor) {
        os << "ID Zbor: " << zbor.m_id << endl
        << "Ruta: " << zbor.m_plecare << " ---> " << zbor.m_destinatie <<endl<<endl
        << "Plecare: " << zbor.m_data_plecare << "  " << zbor.m_ora_plecare <<endl
        << "Sosire: " << zbor.m_data_sosire << "  " << zbor.m_ora_sosire<<endl<<endl
        << "Durata: " << zbor.m_durata << " minute | "
        << "Pret: " << zbor.m_pret_ruta << " EUR"<<endl<<endl;
        return os;
    }
}

void Zbor::SetId(const std::string& id) {
    m_id = id;
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

std::string Zbor::GenereazaIdBilet(const std::string& clasa) {
    int numar = ++m_contor_bilete_per_clasa[clasa]; // accesez nr de bilete deja generate pt clasa, il incrementez si salvez in "numar"
                                                    //de ex daca sunt deja 4 bilete pt economic, se va crea urmatorul : E005
    char prefix = toupper(clasa[0]); // clasa = "economic" sau  "business" si extrag initiala pe care o transform in litera mare => E si B

    std::ostringstream id; // construiesc stringul final - folosesc un ostream in care stochez direct continutul in loc sa concatenez mai multe string uri
    id << prefix << std::setw(3) << std::setfill('0') << numar; 

    return id.str();   //id este un stream in care am continutul final si il returnez tip string .str()  
}
