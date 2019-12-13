#include <iostream>
#include <string>
#include "biblio.h"
#include "color.h"
using namespace std;

void rechercheAvancee(Bibliotheque biblio) {
	int MenuWithColor(Bibliotheque biblio, int numMenu), choix;

    void rechercheTitre(Bibliotheque biblio);
    void rechercheGenre(Bibliotheque biblio);
    void rechercheAuteur(Bibliotheque biblio);
    void rechercheDate(Bibliotheque biblio);

    string recherche[20];
    int nbrRecherche = 0;

    do {
        choix = MenuWithColor(biblio, 2);
        switch (choix) {
        case 1:
            rechercheTitre(biblio);
            break;
        case 2:
            rechercheGenre(biblio);
            break;
        case 3:
            rechercheAuteur(biblio);
            break;
        case 4:
            rechercheDate(biblio);
            break;
        case 5:
            break;
        default:
            cout << red << "Erreur inconnue" << endl;
            break;
        }
    } while (choix != 5);
}