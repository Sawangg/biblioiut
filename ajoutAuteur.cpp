#include <iostream>
#include <string>

#include "biblio.h"
#include "color.h"

using namespace std;

int  ajoutAuteur(Bibliotheque& biblio) {
	Date saisieDate();
	string mort;

	cout << "Quel est le nom de l'auteur ?" << endl;
	getline(cin, biblio.tab_auteurs[biblio.nbrAuteurs].nom);

	cout << "Quel est le prénom de l'auteur ?" << endl;
	getline(cin, biblio.tab_auteurs[biblio.nbrAuteurs].prenom);

	cout << "Quel est la date de naissance de l'auteur ?" << endl;
	biblio.tab_auteurs[biblio.nbrAuteurs].dateN = saisieDate();

	cout << "L'auteur est-il mort (O/N) ? ";
	getline(cin, mort);
	while (mort != "O" && mort != "o" && mort != "N" && mort != "n") {
		cout << red << "Votre choix est invalide!" << normal << " L'auteur est-il mort (O/N) ? ";
		getline(cin, mort);
	}
	if (mort == "O" || mort == "o") {
		cout << "Quel est la date de mort de l'auteur ?" << endl;
		biblio.tab_auteurs[biblio.nbrAuteurs].dateM = saisieDate();
	} else {
		biblio.tab_auteurs[biblio.nbrAuteurs].dateM.jour = 0;
		biblio.tab_auteurs[biblio.nbrAuteurs].dateM.mois = 0;
		biblio.tab_auteurs[biblio.nbrAuteurs].dateM.annee = 0;
	}
	
	biblio.tab_auteurs[biblio.nbrAuteurs].nbrLivresAuteur = 0;

	// Verif auteur existant
	biblio.nbrAuteurs++;

	return biblio.nbrAuteurs-1;
}