#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "color.h"

using namespace std;

int main() {
    locale::global(locale("fr-FR"));

    Bibliotheque biblio;
    Livre tab_livres[MAX_LIVRES];
    string Options[100];

    int choix;
    int MenuWithColor(int numMenu);
    void rechercheAvancee(Bibliotheque biblio);
    void afficheAllLivres(Bibliotheque biblio);
    void sauvDetect(Bibliotheque& biblio);
    int ajoutLivre(Bibliotheque& biblio);
    // int supprLivre(Bibliotheque & biblio);
    
    sauvDetect(biblio); // Detecte si une sauvegarde est présente

    do {
        choix = MenuWithColor(1);
        switch (choix) {
        case 1:
            afficheAllLivres(biblio);
            system("pause");
            break;
        case 2:
            ajoutLivre(biblio);
            system("pause");
            break;
        case 3:
            // supprLivre(biblio); Fonction à modifier du au retour de la recherche
            system("pause");
            break;
        case 4:
            rechercheAvancee(biblio);
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