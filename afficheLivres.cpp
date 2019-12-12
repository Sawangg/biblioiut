#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

void afficheAllLivres(Bibliotheque biblio) {
    void afficheLivre(Livre livre);

    for (int i = 0; i < biblio.nbrLivres; i++) {
        afficheLivre(biblio.tab_livres[i]);
    }
}

void afficheSomeLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres) {
    void afficheLivre(Livre livre);

    for (int i = 0; i < nbrLivres; i++) {
        afficheLivre(biblio.tab_livres[indiceLivres[i]]);
    }
}