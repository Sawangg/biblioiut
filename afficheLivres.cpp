#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

void afficheLivres(Bibliotheque biblio) {
    void afficheLivre(Livre livre);
    for (int i = 0; i < biblio.nbrLivres; i++) {
        afficheLivre(biblio.tab_livres[i]);
    }
}