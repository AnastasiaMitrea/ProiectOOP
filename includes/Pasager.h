#ifndef PASAGER_H
#define PASAGER_H

#include <iostream> 
#include <string>
#include <vector>
#include "Persoana.h"
#include "Bilet.h"
#include "Zbor.h"

using namespace std;

class Pasager : public Persoana {
    private:
        Bilet pasagerBilet; //obiect de tip Bilet asociat pasagerului
        Zbor pasagerZbor; //obiect de tip Zbor asociat pasagerului

};