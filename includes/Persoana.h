#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
#include <stdexcept> // pt throw invalid_argument

using namespace std;

class Persoana{
    
    private:
        string nume;
        string prenume;
        string cnp;
        int varsta;

        bool validareCNP(const string& cnp) const;

    public:
        Persoana(); //constructor defautl
        Persoana(const string& nume, const string& prenume, const string& cnp, int varsta); //constructor cu parametri si validare cnp
        Persoana(const Persoana& other); //constructor de copiere
        virtual ~Persoana(); //destructor virtual

        //getteri
        string getNume() const;
        string getPrenume() const;
        string getCNP() const;
        int getVarsta() const;

        //setteri
        void setNume(const string& nume);
        void setPrenume(const string& prenume);
        void setCNP(const string& cnp);
        void setVarsta(int varsta);

        //metoda virtuala pura care va fi suprascrisa de clasele derivate
        virtual void afisareDate() const=0;

        //supraincarcare operator <<
        friend ostream& operator<<(ostream& out, const Persoana& p);
};

#endif