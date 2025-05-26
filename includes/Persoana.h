#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
#include <stdexcept> // pt throw invalid_argument
#include "Calendar.h"
#include "Date.h"
#include "Utils.h"
#include "I_Afisabil.h"

namespace Transport_Aerian {

    class Persoana : public Interfete::IAfisabil {
    public:
        Persoana(); //constructor defautl
        //Persoana(const std::string& nume, const std::string& prenume, const std::string& cnp, int varsta); //constructor cu parametri si validare cnp
        Persoana(const std::string& nume, const std::string& prenume, const std::string& cnp); ////constructor cu parametri si validare cnp fara varsta
        Persoana(const Persoana& other); //constructor de copiere
        virtual ~Persoana(); //destructor virtual

        //getteri
        std::string GetNume() const;
        std::string GetPrenume() const;
        std::string GetCNP() const;
        int GetVarsta() const;
        Date Persoana::GetDataNasterii() const {}

        //setteri
        void SetNume(const std::string& nume);
        void SetPrenume(const std::string& prenume);
        void SetCNP(const std::string& cnp);
        void SetVarsta(int varsta);

        //supraincarcare operator <<
        friend std::ostream& operator<<(std::ostream& out, const Persoana& p);

        //metodele mostenite din interfata - le-am adaugat pt claritate
        virtual std::string DescriereText() const = 0;
        virtual std::string GetIdText() const = 0;
        virtual void Afisare() const override = 0;

    private:
        std::string m_nume;
        std::string m_prenume;
        std::string m_cnp;
        int m_varsta;
        Utilitati::Date m_data_nasterii;
        
        Utilitati::Date _ExtrageDataNasterii(const std::string& cnp) const;
        bool _ValidareCNP(const std::string& cnp) const;
    };

}

#endif 