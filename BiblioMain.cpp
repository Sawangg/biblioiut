#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "color.h"

using namespace std;

int main() {
    Bibliotheque biblio;
    Livre tab_livres[MAX_LIVRES];
    string Options[100];

    system("mode con LINES=40 COLS=160");
    HWND hwnd = GetConsoleWindow();
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    int choix;
    int MenuWithColor(Bibliotheque biblio, int numMenu);
    void rechercheAvancee(Bibliotheque biblio);
    void afficheLivres(Bibliotheque biblio);
    void sauvDetect(Bibliotheque& biblio);
    int ajoutLivre(Bibliotheque& biblio);
    void sauvegarde(Bibliotheque biblio);
    // int supprLivre(Bibliotheque & biblio);
    
    sauvDetect(biblio); // Detecte si une sauvegarde est présente
    
    do {
        choix = MenuWithColor(biblio, 1);
        switch (choix) {
        case 1:
            afficheLivres(biblio);
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
            sauvegarde(biblio);
            break;
        case 6:
            cout << red << "Adieu !!" << normal << endl;
            break;
        default:
            cout << red << "Erreur inconnue" << normal << endl;
            break;
        }
    } while (choix != 6);

    return 0;
}