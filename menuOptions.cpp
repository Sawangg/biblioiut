#include <iostream>
#include "sleep.h"

using namespace std;

void menuOptions(int menu) {
    system("cls");

    switch (menu) {
    case 1:
        cout << "\x1B[36m========================================================\033[0m" << endl;
        cout << "\x1B[36m=                                                      =\033[0m" << endl;
        cout << "\x1B[36m=\033[0m                  \x1B[34mBibliotheque IUT\033[0m                    \x1B[36m=\033[0m " << endl;
        cout << "\x1B[36m=                                                      =\033[0m" << endl;
        cout << "\x1B[36m========================================================\033[0m" << endl;
        cout << "\n";
        cout << "\x1B[35m1.\033[0m Afficher l'ensemble des livres de la bibliotheque" << endl;
        cout << "\x1B[35m2.\033[0m Ajouter un nouveau livre" << endl;
        cout << "\x1B[35m3.\033[0m Supprimer un livre" << endl;
        cout << "\x1B[35m4.\033[0m Rechercher un livre" << endl;
        cout << "\x1B[35m5.\033[0m Quitter" << endl;
        break;
    default:
        cout << "\x1B[31mMenu innexistant !\033[0m";
        break;
    }

    /*for (;;) {
        Sleep(175);
        cout << "\b\\" << flush;
        Sleep(175);
        cout << "\b|" << flush;
        Sleep(175);
        cout << "\b/" << flush;
        Sleep(175);
        cout << "\b-" << flush;
    }
    cout << " \b Une sauvegarde est disponible";*/

}