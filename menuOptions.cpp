#include <iostream>
#include "sleep.h"
#include "color.h"

using namespace std;

void menuOptions(int menu, string listOptions[], int& nbOptions) {
	string createTitre(string titreMenu);

	switch (menu) {
	case 1:
		listOptions[0] = createTitre("Bibliotheque IUT");
		listOptions[1] = "Afficher l'ensemble des livres de la bibliothèque";
		listOptions[2] = "Ajouter un nouveau livre";
		listOptions[3] = "Supprimer un livre";
		listOptions[4] = "Rechercher un livre";
		listOptions[5] = "Quitter";
		nbOptions = 5;
		break;
	case 2:
		listOptions[0] = createTitre("Recherche livre");
		listOptions[1] = "Rechercher un livre par son titre";
		listOptions[2] = "Rechercher un livre par son genre";
		listOptions[3] = "Rechercher un livre par son auteur";
		listOptions[4] = "Rechercher un livre par sa date de parution";
		listOptions[5] = "Retour";
		nbOptions = 5;
		break;
	case 3:
		listOptions[0] = createTitre("Recherche livre par titre");
		listOptions[1] = "Rechercher un livre par son titre complet";
		listOptions[2] = "Rechercher un livre par un bout de son titre";
		listOptions[3] = "Retour";
		nbOptions = 3;
		break;
	case 4:
		listOptions[0] = createTitre("Recherche livre par auteur");
		listOptions[1] = "Rechercher un livre par le nom de l'auteur";
		listOptions[2] = "Rechercher un livre par le prénom de l'auteur";
		listOptions[3] = "Rechercher un livre par le nom complet de l'auteur";
		listOptions[4] = "Rechercher un livre par la date de naissance de l'auteur";
		listOptions[5] = "Rechercher un livre par la date de mort de l'auteur";
		listOptions[6] = "Rechercher un livre par combinaison de 2 recherches"; //DateN + prénom par exemple
		listOptions[7] = "Retour";
		nbOptions = 7;
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

string createTitre(string titre) {
	int sizeTitre = titre.size();
	string newTitre = "";

	for (int i = 0; i < sizeTitre + 2 + 12 * 2; i++) {
		newTitre += string(cyan) + "=";
	}
	newTitre += "\n";
	newTitre += "=";
	for (int i = 0; i < sizeTitre + 12 * 2; i++) {
		newTitre += " ";
	}
	newTitre += "=";
	newTitre += "\n";
	newTitre += "=            " + string(blue) + titre + string(cyan) + "            =";
	newTitre += "\n";
	newTitre += "=";
	for (int i = 0; i < sizeTitre + 12 * 2; i++) {
		newTitre += " ";
	}
	newTitre += "=";
	newTitre += "\n";
	for (int i = 0; i < sizeTitre + 2 + 12 * 2; i++) {
		newTitre += "=";
	}
	newTitre += "\n";

	return newTitre;
}