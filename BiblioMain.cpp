#include <iostream>
#include <string>
#include "biblio.h"
#include "color.h"

using namespace std;

int main() {
    locale::global(locale("fr-FR"));

    Bibliotheque biblio;
    Livre tab_livres[MAX_LIVRES];
    string Options[100];
    int nbElem = 0, choix;
    int MenuWithColor(int numMenu);
    void afficheLivres(Bibliotheque biblio);
    int ajoutLivre(Bibliotheque& biblio);
    int supprLivre(Bibliotheque & biblio);

    biblio.nbrElem = 0;

    do {
        choix = MenuWithColor(1);
        switch (choix) {
        case 1:
            afficheLivres(biblio);
            system("pause");
            break;
        case 2:
            ajoutLivre(biblio);
            system("pause");
            break;
        case 3:
            supprLivre(biblio);
            system("pause");
            break;
        case 4:
            MenuWithColor(2); // préférable d'utiliser une nouvelle procédure et d'y appeler le menu dedans

            break;
        case 5:
            system("exit");
            break;
        default:
            cout << red << "Erreur inconnue" << endl;
            break;
        }
    } while (choix != 5);
    return 0;
}