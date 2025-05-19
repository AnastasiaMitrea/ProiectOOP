#include "../includes/Zbor.h"

using namespace Transport_Aerian;
using namespace std;

Zbor::Zbor(std::string id, std::string plecare, std::string destinatie,
           Date data_plecare, Ora ora_plecare,
           Date data_sosire, Ora ora_sosire,
           int durata, int pret, int nr_pasageri)
    : m_id(id), m_plecare(plecare), m_destinatie(destinatie),
      m_data_plecare(data_plecare), m_ora_plecare(ora_plecare),
      m_data_sosire(data_sosire), m_ora_sosire(ora_sosire),
      m_durata(durata), m_pret(pret), m_nr_pasageri(nr_pasageri) {}


namespace Transport_Aerian {
    std::ostream& operator<<(std::ostream& os, const Zbor& zbor) {
        os <<"ID zbor: "<< zbor.m_id <<endl
        << "Ruta: " << zbor.m_plecare << " ---> " << zbor.m_destinatie <<endl<<endl
        << "Plecare: " << zbor.m_data_plecare << "  " << zbor.m_ora_plecare <<endl
        << "Sosire: " << zbor.m_data_sosire << "  " << zbor.m_ora_sosire<<endl<<endl
        << "Durata: " << zbor.m_durata << " minute | "
        << "Pret: " << zbor.m_pret << " EUR"<<endl<<endl
        << "Numar pasageri la bord: " << zbor.m_nr_pasageri;
        return os;
    }
}
