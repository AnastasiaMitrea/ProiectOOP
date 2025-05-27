#include "../includes/Calendar.h"

namespace Utilitati{

    Date Calendar::m_data_initializare = Date();
    Ora Calendar::m_ora_initializare = Ora();
    
    void Calendar::Initializare() {
        time_t t = time(nullptr);
        tm* timp = localtime(&t);
        m_data_initializare = Date(timp->tm_mday, timp->tm_mon + 1, timp->tm_year + 1900);
        m_ora_initializare = Ora(timp->tm_hour, timp->tm_min);
    }

    Date Calendar::GetDataInitializare() {
        return m_data_initializare;
    }

    Ora Calendar::GetOraInitializare() {
        return m_ora_initializare;
    }
    
    // anul curent
    int Calendar::GetAnCurent() {
        time_t t = time(nullptr);
        return localtime(&t)->tm_year + 1900;
    }

    // luna curenta (1-12)
    int Calendar::GetLunaCurenta() {
        time_t t = time(nullptr);
        return localtime(&t)->tm_mon + 1;
    }

    // ziua curenta (1-31)
    int Calendar::GetZiCurenta() {
        time_t t = time(nullptr);
        return localtime(&t)->tm_mday; 
    }

    Date Calendar::GetDataCurenta() {
        time_t t = time(nullptr);
        tm* timp = localtime(&t); 
        return Utilitati::Date(
        timp->tm_mday,
        timp->tm_mon + 1,
        timp->tm_year + 1900);
    }

    // verificare an  bisect
    bool Calendar::EsteAnBisect(int an) {
        return (an % 4 == 0 && an % 100 != 0) || (an % 400 == 0);
    }

    // verificare data valida
    bool Calendar::EsteDataValida(Date data) {
        if(data.luna < 1 || data.luna > 12 || data.zi < 1) //true daca luna este intre 1 si 12 si ziua este minim 1
            return false;

        int zile_luna[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //nr zile pe luni in ordine , februarie are minim 28 zile
        if(data.luna == 2 && Calendar::EsteAnBisect(data.an))  //luna este februarie si e an bisect
            return data.zi <= 29;  //true daca ziua este maxim 29

        return (data.zi <= zile_luna[data.luna - 1]) ; //true daca nr zilei este <= cu nr maxim de zile al lunii respective
    }

    // calculeaza varsta folosind data nasterii si data curenta
    int Calendar::CalculeazaVarsta(Date data) {
        int zi = GetZiCurenta();
        int luna = GetLunaCurenta();
        int an = GetAnCurent();

        int varsta = an - data.an;
        if(data.luna > luna || (data.luna == luna && data.zi > zi))
            varsta--;

        return varsta;
    }

    std::pair<Ora, int> Calendar::AdaugaMinuteLaOra(const Ora& ora_initiala, int minute_de_adaugat) {
        int total_minute = ora_initiala.ora * 60 + ora_initiala.minut + minute_de_adaugat; //total minute trecute din ziua respectiva

        int ora_noua = (total_minute / 60) % 24;  
        int minut_nou = total_minute % 60;  

        int zile_in_plus = total_minute / (24 * 60); // de cate ori am trecut peste 24h 

        return { Ora(ora_noua, minut_nou), zile_in_plus };
    }

    /*
        ex: ora initiala = 23:15
            minute adaugate = 135 

            total_minute = 23 * 60 + 15 + 135 = 1530 min
            ora_noua = (1530/60) % 24 = 25h % 24 = 1
            minut_nou = 1530 % 60 = 30 

            zile_in plus = 1530 / (24*60) = 1530 / 1440 = 1 => s a trecut 1 data peste miezul noptii

            se returneaza (Ora(1, 30), 1) => ora 1:30, a doua zi

       ex2: ora initiala = 14:20
            minute adaugate = 95

            total_minute = 14 * 60 + 20 + 95 = 955 min
            ora_noua = (955/60) % 24 = 15h % 24 = 15 
            minut_nou = 955 % 60 = 55 

            zile_in plus = 955 / (24*60) = 955 / 1440 = 0 => nu s-a trecut peste miezul noptii

            se returneaza (Ora(15, 55), 0) => ora 15:55, aceeasi zi
    */


}

