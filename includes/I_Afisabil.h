#ifndef IAFISABIL_H
#define IAFISABIL_H

#include <iostream>
#include <string>

namespace Interfete {

class IAfisabil {
    public:
        // afiseaza obiectul direct
        virtual void Afisare() const = 0;

        // returneaza o descriere text completa despre obiectul respectiv
        virtual std::string DescriereText() const = 0;

        // returneaza ID ul unic al obiectului ca text , de ex la persoana id = cnp
        virtual std::string GetIdText() const = 0;

        virtual ~IAfisabil() {}
    };

}

#endif
