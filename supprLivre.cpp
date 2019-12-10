#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

int supprLivre(Bibliotheque& biblio) {
    int rechercheLivre(Bibliotheque biblio);
    int pos = rechercheLivre(biblio);
    biblio.tab_livres[pos] = biblio.tab_livres[biblio.nbrElem - 1];
    cout << "\x1B[32mLe livre a bien ete supprime !\033[0m" << endl;
    return biblio.nbrElem -= 1;
}
