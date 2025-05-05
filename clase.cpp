#ifndef PERSOANA_H
#define PERSOANA_H
#include <iostream>
#include <string>
#include <stdexcept> // pt invalid_argument
using namespace std;

class Persoana{
    private:
        string nume;
        string prenume;
        string cnp;
        int varsta;

        bool validareCNP(const string& cnp) const {
            return cnp.length()==13; // implementare logica de validare a cnp-ului
        }

    public:
        Persoana() : nume(""), prenume(""), cnp(""), varsta(0) {} //constructor defautl
        
        Persoana(const string& nume, const string& prenume, const string& cnp, int varsta) //constructor cu parametri si validare cnp
            : nume(nume), prenume(prenume), cnp(cnp), varsta(varsta) {
            if (!validareCNP(cnp)) {
                throw invalid_argument("CNP invalid!");
            }
        }

        Persoana(const Persoana& other) //constructor de copiere
            : nume(other.nume), prenume(other.prenume), cnp(other.cnp), varsta(other.varsta) {}

        virtual ~Persoana() {} //destructor virtual	\

        //getteri
        string getNume() const { return nume; }
        string getPrenume() const { return prenume; }
        string getCNP() const { return cnp; }
        int getVarsta() const { return varsta; }

        //setteri
        void setNume(const string& nume) { this->nume = nume; }
        void setPrenume(const string& prenume) { this->prenume = prenume; }
        void setCNP(const string& cnp) {
            if (!validareCNP(cnp)) {
                throw invalid_argument("CNP invalid!");
            }
            this->cnp = cnp;
        }
        void setVarsta(int varsta) { this->varsta = varsta; }

        //metoda virtuala pura care va fi suprascrisa de clasele derivate
        virtual void afisareDate() const=0;

        //supraincarcare operator <<
        friend ostream& operator<<(ostream& out, const Persoana& p){
            p.afisareDate(); //apeleaza metoda virtuala specifica obiectului
            return out;
        }
};

#endif // PERSOANA_H