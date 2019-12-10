#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "controle.h"

using namespace std;

void Menu(Bibliotheque biblio) {
    int choix = 0;
    void menuOptions(int menu);
    void afficheLivres(Bibliotheque biblio);
    void afficheLivre(Livre livre);
    int rechercheLivre(Bibliotheque biblio);
    int ajoutLivre(Bibliotheque& biblio);
    int supprLivre(Bibliotheque& biblio);
    int pos;

    do {
        menuOptions(1);
        choix = ControleEntier();

        if (biblio.nbrElem == 0 && (choix == 1 || choix == 3 || choix == 4)) {
            cout << "\n";
            cout << "\x1B[31mLa bilbiotheque ne contient aucun livre !\033[0m" << endl;
            system("pause");
        } else {
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
                cout << "Merci de rentrer un titre effectuer la suppression : ";
                supprLivre(biblio);
                system("pause");
                break;
            case 4:
                cout << "Merci de rentrer un titre effectuer la recherche : ";
                pos = rechercheLivre(biblio);
                if (pos == -1) {
                    cout << "\x1B[31mLe livre n'a pas ete trouve ! !\033[0m" << endl;
                } else {
                    afficheLivre(biblio.tab_livres[pos]);
                }
                system("pause");
                break;
            case 5:
                system("exit");
                break;
            default:
                cout << "\x1B[31mChoix invalide !\033[0m" << endl;
                system("pause");
                break;
            }
        }
    } while (choix != 5);
}