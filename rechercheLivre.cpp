#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

int rechercheLivre(Bibliotheque biblio) {
    string titre;
    cin >> titre;
    int pos = 0;
    while (biblio.nbrLivres > pos) {
        if (biblio.tab_livres[pos].titre == titre) {
            return pos;
        } else {
            pos += 1;
        }
    }
    return -1;
}
