#include "../includes/Retea_zboruri.h"
#include <algorithm>

using namespace Transport_Aerian;

Retea_Rute::Retea_Rute() {}

void Retea_Rute::AdaugaDistanta(const std::string& oras1, const std::string& oras2, int distanta_km) {
    auto key = _NormalizareCheie(oras1, oras2);  //tipul variabilei va fi fdedus automat de catre compilator la initializare
    m_distante[key] = distanta_km;  //adaug distanta in dictionar cu cheia ordonata
}

std::pair<std::string, std::string> Retea_Rute::_NormalizareCheie(const std::string& oras1, const std::string& oras2) const {
    if(oras1 < oras2)   //compar alfabetic pt a decide care oras vine primul in pereche
        return {oras1, oras2};
    return {oras2, oras1}; 
}

int Retea_Rute::GetDistanta(const std::string& oras1, const std::string& oras2) const { 
    auto key = _NormalizareCheie(oras1, oras2); 
    auto it = m_distante.find(key); //caut cheia key (pereche de 2 orase) in dictionar cu iterator
    //.find() returneaza un iterator catre cheia gasita in dictionar iar daca iteratorul este .end() inseamna ca nu a fost gasita cheia
    if(it != m_distante.end())   
        return it->second;   //second = distanta si first=(oras1, oras2) din dictionar
    return -1; // nu exista ruta in dictionar => distanta = -1
}

int Retea_Rute::CalculeazaPretBaza(const std::string& oras1, const std::string& oras2) const {
    int distanta = GetDistanta(oras1, oras2);
    if(distanta == -1) 
        return -1;
    return distanta / 10; // ex: 1800 km = 180 EUR (1 EUR = 10 km)
}

int Retea_Rute::CalculeazaDurata(const std::string& oras1, const std::string& oras2) const {
    int distanta = GetDistanta(oras1, oras2);
    if(distanta == -1)
        return -1;

    // viteza medie a unui avion comercial este 800 km/h - deci durata = distanta / 800 (ore) * 60 = rezultat in minute
    return (distanta * 60) / 800;    //ex durata pt 1800km : 1800/800*60 = 135 minute
}

