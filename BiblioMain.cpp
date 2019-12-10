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
    int nbElem = 0;
    void menuOptions(int menu, string listOptions[], int& nbElem);
    int MenuWithColor(string Options[], int nbElem);
    void afficheLivres(Bibliotheque biblio);
    int ajoutLivre(Bibliotheque& biblio);
    int supprLivre(Bibliotheque & biblio);

    biblio.nbrElem = 0;

    menuOptions(1, Options, nbElem);
    do {
        switch (MenuWithColor(Options, nbElem)) {
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
            menuOptions(1, Options, nbElem);

            break;
        case 5:
            system("exit");
            break;
        default:
            cout << red << "Erreur inconnue" << endl;
            break;
        }
    } while (MenuWithColor(Options, nbElem) != 5);
    return 0;
}