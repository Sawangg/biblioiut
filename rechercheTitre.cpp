#include <string>
#include <iostream>
#include "biblio.h"
using namespace std;

void rechercheTitre(Bibliotheque biblio) {
	int MenuWithColor(Bibliotheque biblio, int menu), choix;
	void afficheSomeLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres);
	void rechercheLivreTitreComplet(Bibliotheque biblio, string titre, int position[], int& nbrOccur);
	void rechercheLivreTitrePartie(Bibliotheque biblio, string bout_titre, int position[], int& nbrOccur);

	string titre[20];

	int position[100];
	int nbrOccur = 0;

	do {
		choix = MenuWithColor(biblio, 3);
		switch (choix) {
		case 1:
			cout << "Merci de rentrer un titre: ";
			getline(cin, titre[0]);

			rechercheLivreTitreComplet(biblio, titre[0], position, nbrOccur);

			afficheSomeLivres(biblio, position, nbrOccur);
			system("pause");
			break;
		case 2:
			cout << "Merci de rentrer un bout de titre: ";
			getline(cin, titre[0]);

			rechercheLivreTitrePartie(biblio, titre[0], position, nbrOccur);

			afficheSomeLivres(biblio, position, nbrOccur);
			system("pause");
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (choix != 3);

	// Les afficher
	cout << endl << "Voici le résultat de la recherche: ";
	afficheSomeLivres(biblio, position, nbrOccur);

	system("pause");
}