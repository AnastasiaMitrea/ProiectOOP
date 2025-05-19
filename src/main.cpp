#include <iostream>
#include "../includes/Bilet.h"
#include "../includes/Pasager.h"
#include "../includes/Zbor.h"

using namespace std;
using namespace Transport_Aerian;

int main() {
    // creez un bilet
   Bilet bilet("B123", "business", 500);

    // creez un pasager
   Pasager p("Popescu", "Ion", "1234567890123", 35, bilet);

    // creez un zbor
    Zbor* z1 = new Zbor(
        "Z001", "Bucuresti", "Paris",
        Date{12, 6, 2025}, Ora{10, 30},
        Date{12, 6, 2025}, Ora{12, 15},
        105, 500, 120
    );

    // adaug zborul la pasager
    p.AdaugaZbor(z1);

    // afisez pasagerul
    cout << endl << p << endl;

    // afisez numarul total de pasageri
    cout << "Total pasageri: " << Pasager::GetNumarPasageri() << endl;

    // eliberez zborul
    delete z1;
    return 0;
}
