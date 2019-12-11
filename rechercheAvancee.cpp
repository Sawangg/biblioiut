#include <iostream>
#include <string>
#include "biblio.h"
#include "color.h"
using namespace std;

void rechercheAvancee(Bibliotheque biblio) {
	int MenuWithColor(int numMenu), choix;

    do {
        choix = MenuWithColor(2);
        switch (choix) {
        case 1:
            system("pause");
            break;
        case 2:
            system("pause");
            break;
        case 3:
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