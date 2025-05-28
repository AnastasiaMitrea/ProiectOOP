#ifndef RETEA_H
#define RETEA_H

#include <string>
#include <map>

namespace Transport_Aerian {

    class Retea_Rute {
    public:
        static Retea_Rute& GetInstanta();

        void AdaugaDistanta(const std::string& oras1, const std::string& oras2, int distanta_km);  //distanta dintre 2 orase
        int GetDistanta(const std::string& oras1, const std::string& oras2) const;
        int CalculeazaPretBaza(const std::string& oras1, const std::string& oras2) const;  //pret in functie de distanta
        int CalculeazaDurata(const std::string& oras1, const std::string& oras2) const; //durata in functie de distanta

    private:
        Retea_Rute();  //pt a fi singleton

        std::map<std::pair<std::string, std::string>, int> m_distante;
        //dictionar cheie - valoare cu cheie = pereche string uri ("oras1" , "oras2") si valoare = distanta (oras1, oras2)
        // ex: ("Bucuresti", "Paris"), 1800

        std::pair<std::string, std::string> _NormalizareCheie(const std::string& oras1, const std::string& oras2) const;
        //Normalizare = ordonez cheile din dictionar astfel incat ("Bucuresti", "Paris") sa fie acelasi cu ( "Paris", "Bucuresti")
        //este folosita intern in Retea, nu va afecta m_plecare si m_sosire la znboruri
    };

}

#endif
