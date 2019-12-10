#include <iostream>
#include "sleep.h"

using namespace std;

void menuOptions(int menu, string listOptions[], int& nbElem) {
	char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
	char black[] = { 0x1b,'[','0',';','3','0','m',0 };
	char red[] = { 0x1b,'[','0',';','3','1','m',0 };
	char green[] = { 0x1b,'[','0',';','3', '2','m',0 };
	char yellow[] = { 0x1b,'[','0',';','3', '3', 'm',0 };
	char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
	char Upurple[] = { 0x1b,'[','1',';','3','5','m',0 };
	char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
	char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
	char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
	char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };

	string test;
	int sizeTitre;

	switch (menu) {
	case 1:
		listOptions[0] = "Bibliotheque IUT";
		sizeTitre = listOptions[0].size();
		for (int i = 0; i < sizeTitre + 2 + 6 * 2; i++) {
			test += string(cyan) + "=";
		}
		test += "\n";
		test += "=";
		for (int i = 0; i < sizeTitre + 6 * 2; i++) {
			test += " ";
		}
		test += "=";
		test += "\n";
		test += "=      " + string(blue) + listOptions[0] + string(cyan) + "      =";
		test += "\n";
		test += "=";
		for (int i = 0; i < sizeTitre + 6 * 2; i++) {
			test += " ";
		}
		test += "=";
		test += "\n";
		for (int i = 0; i < sizeTitre + 2 + 6 * 2; i++) {
			test += "=";
		}
		test += "\n";
		listOptions[0] = test;
		listOptions[1] = "Afficher l'ensemble des livres de la bibliothèque";
		listOptions[2] = "Ajouter un nouveau livre";
		listOptions[3] = "Supprimer un livre";
		listOptions[4] = "Rechercher un livre";
		listOptions[5] = "Quitter";
		nbElem = 5;
		break;
	case 2:
		listOptions[0] = "Recherche livre";
		listOptions[1] = "Rechercher un livre par son titre";
		listOptions[2] = "Rechercher un livre par son type";
		listOptions[3] = "Rechercher un livre par son genre";
		listOptions[4] = "Rechercher un livre par son auteur";
		listOptions[5] = "Rechercher un livre par sa date de parution";
		listOptions[6] = "Retour";
		nbElem = 6;
		break;
	default:
		listOptions[0] = "ERROR";
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