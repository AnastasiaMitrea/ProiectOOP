#include <iostream>
#include <algorithm>
#include "includes/Bilet.h"
#include "includes/Calendar.h"
#include "includes/Pasager.h"
#include "includes/Persoana.h"
#include "includes/Zbor.h"
#include "includes/Companie.h"
#include "includes/Rezervare.h"
#include "includes/Formular.h"
#include "includes/Pilot.h"
#include "includes/Retea_zboruri.h"
#include "includes/H_Companii/Air_France.h"
#include "includes/H_Companii/Etihad.h"
#include "includes/H_Companii/Tarom.h"
#include "includes/H_Companii/Wizz_Air.h"

using namespace std;
using namespace Transport_Aerian;

std::vector<Pilot*> SelecteazaEchipaj(Companie* companie, Zbor* zbor, const Retea_Rute& retea);
void AfiseazaDataOraCurenta();
void IncarcaRute(Transport_Aerian::Retea_Rute& retea);

int main() {
    srand(static_cast<unsigned>(time(0))); //pt "resetarea" lui rand

    Retea_Rute& retea = Retea_Rute::GetInstanta();
    IncarcaRute(retea);

    //-----------------------ZBORURI PE COMPANII-----------------------

    // EY
    std::vector<std::tuple<std::string, std::string, std::string, int>> date_etihad = {
        {"Ahmad", "Zayed", "1970111123456", 1990},
        {"Nour", "Farid", "1965123456789", 1988},
        {"Khalid", "Omar", "1980032245678", 2005},
        {"Yousef", "Habib", "1979010199999", 2002},
        {"Omar", "Suleiman", "1985050512345", 2009},
        {"Ali", "Hassan", "1973121211111", 1997},
        {"Hadi", "Karim", "1982073012345", 2007}
    };

    // AF
    std::vector<std::tuple<std::string, std::string, std::string, int>> date_af = {
        {"Pierre", "Dubois", "1967021023456", 1991},
        {"Jean", "Martin", "1974080412345", 1999},
        {"Louis", "Petit", "1981032912345", 2006},
        {"Nicolas", "Lemoine", "1976061612345", 2000},
        {"Jacques", "Moreau", "1986123012345", 2014},
        {"Luc", "Fournier", "1981050112345", 2005},
        {"Henri", "Girard", "1988093012345", 2019}
    };

    // RO
    std::vector<std::tuple<std::string, std::string, std::string, int>> date_ro = {
        {"Ion", "Popescu", "1975031012345", 1995},
        {"Vasile", "Ionescu", "1969121200001", 1992},
        {"Gheorghe", "Stan", "1980022022222", 2005},
        {"Andrei", "Marin", "1978010112345", 2004},
        {"Mihai", "Georgescu", "1983050522222", 2010},
        {"Florin", "Radu", "1990033022222", 2019},
        {"Alexandru", "Dumitru", "1991123123456", 2022}
    };

    // WZ
    std::vector<std::tuple<std::string, std::string, std::string, int>> date_wz = {
        {"Luca", "Nagy", "1986010112345", 2012},
        {"Adam", "Toth", "1982092912345", 2006},
        {"Istvan", "Kovacs", "1987070722222", 2013},
        {"David", "Horvath", "1992012012345", 2020},
        {"Peter", "Balazs", "1993050511111", 2022},
        {"Tamas", "Molnar", "1991123112345", 2021},
        {"Laszlo", "Farkas", "1996040100000", 2023}
    };
    
    Companie* etihad = new Etihad();
    Companie* airfrance = new AirFrance();
    Companie* tarom = new Tarom();
    Companie* wizzair = new WizzAir();

    //-------ETIHAD-------
    for (const auto& [n, p, cnp, an] : date_etihad)
        etihad->AdaugaPilot(new Pilot(n, p, cnp, an));

    std::vector<std::pair<std::string, std::string>> rute_etihad = {
        {"Bucuresti", "Paris"}, {"Dubai", "Londra"}, {"New York", "Abu Dhabi"}, {"Paris", "Milano"},
        {"Doha", "Madrid"}, {"Istanbul", "Berlin"}, {"Tokyo", "Singapore"}, {"Roma", "Amsterdam"},
        {"Munchen", "Bucuresti"}, {"Praga", "Lisabona"}, {"Dublin", "Viena"}, {"Toronto", "Chicago"},
        {"Zurich", "Copenhaga"}, {"Bruxelles", "Atena"}
    };
    for (const auto& [plecare, destinatie] : rute_etihad) {
        // zi random intre 1 și 28
        int zi = rand() % 28 + 1;
        int ora = rand() % 24;   // ora random 0-23
        int minut = rand() % 60;  // minute random 0-60 

        Date data_zbor(zi, Utilitati::Calendar::GetLunaCurenta(), Utilitati::Calendar::GetAnCurent());
        Ora ora_zbor(ora, minut);

        Zbor* z = new Zbor(plecare, destinatie, data_zbor, ora_zbor, retea);
        std::string id = etihad->GenereazaIdZbor(); 
        z->SetId(id); 
        etihad->AdaugaZbor(z);  
    }

    //-------AIR FRANCE-------
    for (const auto& [n, p, cnp, an] : date_af)
        airfrance->AdaugaPilot(new Pilot(n, p, cnp, an));
    
    std::vector<std::pair<std::string, std::string>> rute_af = {
        {"Bucuresti", "Paris"}, {"Berlin", "Istanbul"}, {"Amsterdam", "Roma"}, {"New York", "Abu Dhabi"},
        {"Madrid", "Doha"}, {"Londra", "Dubai"}, {"Toronto", "Chicago"}, {"Munchen", "Bucuresti"},
        {"Bruxelles", "Atena"}, {"Praga", "Lisabona"}, {"Dublin", "Viena"}, {"Helsinki", "Oslo"},
        {"Milano", "Barcelona"}, {"Copenhaga", "Zurich"}
    };

    for (const auto& [plecare, destinatie] : rute_af) {
        int zi = rand() % 28 + 1;
        int ora = rand() % 24;
        int minut = rand() % 60;
        
        Date data_zbor(zi, Utilitati::Calendar::GetLunaCurenta(), Utilitati::Calendar::GetAnCurent());
        Ora ora_zbor(ora, minut);

        Zbor* z = new Zbor(plecare, destinatie, data_zbor, ora_zbor, retea);
        z->SetId(airfrance->GenereazaIdZbor());
        airfrance->AdaugaZbor(z);
    }

    //-------TAROM-------
    for (const auto& [n, p, cnp, an] : date_ro)
        tarom->AdaugaPilot(new Pilot(n, p, cnp, an));

    std::vector<std::pair<std::string, std::string>> rute_ro = {
        {"Bucuresti", "Paris"}, {"Istanbul", "Berlin"}, {"Madrid", "Doha"}, {"Roma", "Amsterdam"},
        {"Cluj", "Barcelona"}, {"Constanta", "Milano"}, {"Chisinau", "Viena"}, {"Timisoara", "Bruxelles"},
        {"Sibiu", "Londra"}, {"Iasi", "Munchen"}, {"Bacau", "Dublin"}
    };
    for (const auto& [plecare, destinatie] : rute_ro) {
        int zi = rand() % 28 + 1;
        int ora = rand() % 24;
        int minut = rand() % 60;

        Date data_zbor(zi, Utilitati::Calendar::GetLunaCurenta(), Utilitati::Calendar::GetAnCurent());
        Ora ora_zbor(ora, minut);

        Zbor* z = new Zbor(plecare, destinatie, data_zbor, ora_zbor, retea);
        z->SetId(tarom->GenereazaIdZbor());
        tarom->AdaugaZbor(z);
    }

    //-------WIZZAIR-------
    for (const auto& [n, p, cnp, an] : date_wz)
        wizzair->AdaugaPilot(new Pilot(n, p, cnp, an));

    std::vector<std::pair<std::string, std::string>> rute_wz = {
        {"Bucuresti", "Paris"}, {"Cluj", "Londra"}, {"Timisoara", "Milano"}, {"Sibiu", "Dortmund"},
        {"Iasi", "Bruxelles"}, {"Constanta", "Paris"}, {"Targu Mures", "Bologna"}, {"Oradea", "Malta"},
        {"Arad", "Roma"}, {"Suceava", "Memmingen"}, {"Baia Mare", "Barcelona"}
    };
    for (const auto& [plecare, destinatie] : rute_wz) {
        int zi = rand() % 28 + 1;
        int ora = rand() % 24;
        int minut = rand() % 60;

        Date data_zbor(zi, Utilitati::Calendar::GetLunaCurenta(), Utilitati::Calendar::GetAnCurent());
        Ora ora_zbor(ora, minut);

        Zbor* z = new Zbor(plecare, destinatie, data_zbor, ora_zbor, retea);
        z->SetId(wizzair->GenereazaIdZbor());
        wizzair->AdaugaZbor(z);
    }
    // ^^^^^^^^^^^^^^^^^^^^^^ZBORURI PE COMPANII^^^^^^^^^^^^^^^^^^^^^^

    // -----------------------MENIU-----------------------

    int optiune = 0;
    std::vector<Rezervare*> rezervari;

do {
    system("cls");  
    AfiseazaDataOraCurenta();
    std::cout << "\n=== MENIU PRINCIPAL ===\n";
    std::cout << "1. Afisare zboruri disponibile\n";
    std::cout << "2. Rezerva un zbor\n";
    std::cout << "3. Afiseaza rezervarile existente\n";
    std::cout << "4. Salveaza/Incarca rezervari\n";
    std::cout << "0. Iesire\n";
    std::cout << "Selecteaza o optiune: ";
    std::cin >> optiune;
    std::cin.ignore(); // curat bufferul

    switch (optiune) {
        case 1: {
            system("cls");

            Utilitati::Date data = Utilitati::Calendar::GetDataCurenta();
            Utilitati::Ora ora = Utilitati::Calendar::GetOraInitializare();

            std::cout << "Lista de zboruri solicitata la " << data << ", ora: " << ora << "\n";
            std::cout << "===============================================\n\n";

            std::vector<Companie*> companii = {etihad, airfrance, tarom, wizzair};

            for (Companie* companie : companii) {
                std::cout << "Zboruri oferite de " << companie->GetNume() << ":\n\n";
                companie->AfiseazaZboruriOferite();  
                std::cout << "\n-----------------------------------------------\n\n";
            }

            break;
        }

        case 2: {
            system("cls");

            Utilitati::Formular f = Utilitati::ColecteazaFormular();

            std::vector<Zbor*> zboruri_potrivite;
            Zbor* zbor_ales = nullptr;
            Companie* companie_aleasa = nullptr;

            std::vector<Companie*> companii = {etihad, airfrance, tarom, wizzair};

            // caut zboruri disponibile cu aceeasi plecare, destinatie si data
            for (Companie* comp : companii) {
                for (Zbor* z : comp->GetZboruriOferite()) {
                    if (z && z->GetPlecare() == f.plecare &&
                        z->GetDestinatie() == f.destinatie &&
                        z->GetDataPlecare() == f.data_zbor) {
                        zboruri_potrivite.push_back(z);
                    }
                }
            }

            if (zboruri_potrivite.empty()) {
                std::cout << "\nNu exista zboruri disponibile pentru criteriile selectate.\n";
                break;
            }

            std::cout << "\nZboruri disponibile:\n";
            for (size_t i = 0; i < zboruri_potrivite.size(); ++i) {
                std::cout << i + 1 << ". " << *zboruri_potrivite[i] << "\n";
            }

            std::cout << "\nSelecteaza un zbor (1 - " << zboruri_potrivite.size() << "): ";
            int opt;
            std::cin >> opt; std::cin.ignore();
            if (opt < 1 || opt > (int)zboruri_potrivite.size()) {
                std::cout << "\nOptiune invalida.\n";
                break;
            }

            zbor_ales = zboruri_potrivite[opt - 1];

            // identific compania prin vectorul de zboruri
            for (Companie* comp : companii) {
                for (Zbor* z : comp->GetZboruriOferite()) {
                    if (z == zbor_ales) {
                        companie_aleasa = comp;
                        break;
                    }
                }
                if (companie_aleasa) break;
            }

            // prelucrez biletul
            int pret_baza = zbor_ales->GetPret();
            float pret_final = companie_aleasa->CalculPretCompanie(pret_baza, f.clasa);
            std::string id_bilet = zbor_ales->GenereazaIdBilet(f.clasa);
            std::string servicii = companie_aleasa->GetPoliticaBagaj(f.clasa);

            std::cout << "\n--- DETALII BILET ---\n";
            std::cout << "ID Zbor: " << zbor_ales->GetId() << "\n";
            std::cout << "ID Bilet: " << id_bilet << "\n";
            std::cout << "Servicii clasa " << f.clasa << ": " << servicii << "\n";
            std::cout << "Pret total: " << pret_final << " EUR\n";

            // creez pasagerul si biletul
            Pasager pas(f.nume, f.prenume, f.cnp);
            Bilet b(id_bilet, f.clasa, pret_final);
            pas.SetBilet(b);

            std::vector<Pilot*> echipaj = SelecteazaEchipaj(companie_aleasa, zbor_ales, retea);

            // creez rezervare si afisez
            Rezervare* r = new Rezervare(pas, zbor_ales, echipaj, companie_aleasa);
            std::cout << "\n--- REZERVARE COMPLETA ---\n";
            r->Afisare();

            rezervari.push_back(r);

            break;
        }

        case 3:
            // afisare rezervari
            break;
        case 4:
            // salvare rezervari
            break;
        case 0:
            std::cout << "Iesire din aplicatie. La revedere!\n";
            break;
        default:
            std::cout << "Optiune invalida.\n";
    }

    if(optiune != 0) {
        std::cout << "\nApasa Enter pentru a reveni la meniu...";
        std::cin.get();
    }

} while (optiune != 0);

    // ^^^^^^^^^^^^^^^^^^^^^^MENIU^^^^^^^^^^^^^^^^^^^^^^


    delete etihad; //se apeleaza destructorul care sterge vectorii de piloti
    delete airfrance;
    delete tarom;
    delete wizzair;

    for (Rezervare* r : rezervari)
    delete r;

    return 0;
}


std::vector<Pilot*> SelecteazaEchipaj(Companie* companie, Zbor* zbor, const Retea_Rute& retea) {
    Pilot* piloti_valizi[30]; // maxim 30 piloti valizi
    int n_valizi = 0;  //nr real de piloti valizi

    int distanta = retea.GetDistanta(zbor->GetPlecare(), zbor->GetDestinatie());

    for (Pilot* p : companie->GetPiloti()) {
        if (!p)
            continue;

        //adaug pilotii in array in functie de distanta zborului - pt zboruri mai lungi de 1000km este nevoie de piloti experimentati
        if (distanta > 1000) {      
            if (p->GetVarsta() >= 30 && p->GetExperientaAni() >= 5)
                piloti_valizi[n_valizi++] = p;
        } else {
            piloti_valizi[n_valizi++] = p;
        }
    }

    std::vector<Pilot*> echipaj;

    if (n_valizi < 2) {
        for (int i = 0; i < n_valizi; ++i)
            echipaj.push_back(piloti_valizi[i]);
        return echipaj;
    }

    // alegem 2 indici random diferiti pt piloti
    int i1 = rand() % n_valizi;
    int i2= rand() % n_valizi;
    while (i2 == i1) {  
        i2 = rand() % n_valizi;
    } 

    //cei 2 piloti alesi random
    echipaj.push_back(piloti_valizi[i1]); 
    echipaj.push_back(piloti_valizi[i2]);

    return echipaj;
}

void IncarcaRute(Transport_Aerian::Retea_Rute& retea) {
    std::vector<std::tuple<std::string, std::string, int>> rute = {
        {"Bucuresti", "Londra", 2100}, {"Bucuresti", "Paris", 1870}, {"Bucuresti", "Amsterdam", 1780},
        {"Bucuresti", "Berlin", 1600}, {"Bucuresti", "Madrid", 2500}, {"Bucuresti", "Roma", 1130},
        {"Bucuresti", "Atena", 750},   {"Bucuresti", "Istanbul", 450}, {"Bucuresti", "Lisabona", 3200},
        {"Londra", "New York", 5560},  {"Londra", "Tokyo", 9580},      {"Londra", "Oslo", 1200},
        {"Paris", "Barcelona", 1030},  {"Paris", "Berlin", 1050},      {"Paris", "Moscova", 2480},
        {"Amsterdam", "Stockholm", 1100}, {"Amsterdam", "Oslo", 980}, {"Amsterdam", "Dubai", 5180},
        {"Madrid", "Lisabona", 620},   {"Madrid", "Casablanca", 1100}, {"Roma", "Milano", 480},
        {"Roma", "Munchen", 880},      {"Roma", "Bruxelles", 1170},   {"Atena", "Tel Aviv", 1180},
        {"Atena", "Doha", 2980},       {"Istanbul", "Cairo", 1250},   {"Istanbul", "Bagdad", 1600},
        {"Istanbul", "Dubai", 3000},   {"Lisabona", "New York", 5410},{"Lisabona", "Londra", 1570},
        {"Lisabona", "Amsterdam", 1860},{"Lisabona", "Paris", 1450}, {"Londra", "Berlin", 950},
        {"Berlin", "Varsovia", 570},   {"Berlin", "Kiev", 1200},       {"Berlin", "Moscova", 1600},
        {"Berlin", "Bucuresti", 1600}, {"Berlin", "Madrid", 2300},     {"Amsterdam", "Praga", 880},
        {"Praga", "Viena", 300},       {"Viena", "Budapesta", 220},    {"Budapesta", "Bucuresti", 850},
        {"Bucuresti", "Chisinau", 450},{"Chisinau", "Iasi", 130},      {"Iasi", "Cluj", 460},
        {"Cluj", "Timisoara", 320},    {"Timisoara", "Bucuresti", 540},{"Timisoara", "Munchen", 1000},
        {"Munchen", "Zurich", 320},    {"Zurich", "Milano", 280},      {"Milano", "Paris", 850}
    };

    for (const auto& [oras1, oras2, distanta] : rute)   // functie lambda - adaug tuplul oras1, oras2, distanta in retea
        retea.AdaugaDistanta(oras1, oras2, distanta);
}


void AfiseazaDataOraCurenta() {
    Utilitati::Date data = Utilitati::Calendar::GetDataCurenta();
    Utilitati::Ora ora = Utilitati::Calendar::GetOraInitializare();  // sau GetOraCurenta dacă ai

    std::cout << "Data curenta: " << data << ", ora: " << ora << "\n";
}
