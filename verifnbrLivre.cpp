#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

void verifnbrLivre(Bibliotheque biblio) {
    if (biblio.nbrElem == 0) {
        cout << "\n";
        cout << "La bilbiotheque ne contient aucun livre !" << endl;
    }
}
