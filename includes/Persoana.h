#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
#include <stdexcept> // pt throw invalid_argument

namespace Transport_Aerian {

    class Persoana{
    public:
        Persoana(); //constructor defautl
        Persoana(const std::string& nume, const std::string& prenume, const std::string& cnp, int varsta); //constructor cu parametri si validare cnp
        Persoana(const Persoana& other); //constructor de copiere
        virtual ~Persoana(); //destructor virtual

        //getteri
        std::string GetNume() const;
        std::string GetPrenume() const;
        std::string GetCNP() const;
        int GetVarsta() const;

        //setteri
        void SetNume(const std::string& nume);
        void SetPrenume(const std::string& prenume);
        void SetCNP(const std::string& cnp);
        void SetVarsta(int varsta);

        //metoda virtuala pura care va fi suprascrisa de clasele derivate
        virtual void AfisareDate() const=0;

        //supraincarcare operator <<
        friend std::ostream& operator<<(std::ostream& out, const Persoana& p);

    private:
        std::string m_nume;
        std::string m_prenume;
        std::string m_cnp;
        int m_varsta;
        bool _ValidareCNP(const std::string& cnp) const;        
    };

}

#endif PERSOANA_H