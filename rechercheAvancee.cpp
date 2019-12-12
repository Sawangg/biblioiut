#include <iostream>
#include <string>
#include "biblio.h"
#include "color.h"
using namespace std;

void rechercheAvancee(Bibliotheque biblio) {
	int MenuWithColor(int numMenu), choix;

    void rechercheTitre(Bibliotheque biblio);
    void rechercheGenre(Bibliotheque biblio);
    void rechercheAuteur(Bibliotheque biblio);

    string recherche[20];
    int nbrRecherche = 0;

    do {
        choix = MenuWithColor(2);
        switch (choix) {
        case 1:
            rechercheTitre(biblio);

            system("pause");
            break;
        case 2:
            rechercheGenre(biblio);

            system("pause");
            break;
        case 3:
            rechercheAuteur(biblio);

            system("pause");
            break;
        case 4:


            system("pause");
            break;
        case 5:
            break;
        default:
            cout << red << "Erreur inconnue" << endl;
            break;
        }
    } while (choix != 5);
}