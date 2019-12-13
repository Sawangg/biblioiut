#include <iostream>
#include <string>

#include "biblio.h"
#include "color.h"
#include "controle.h"

using namespace std;

void  ajoutAuteur(Bibliotheque& biblio, Livre& livre, int indiceLivre) {
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
	
	biblio.tab_auteurs[biblio.nbrAuteurs].nbrLivresAuteur = 1;
	
	if (auteurExistant(biblio.tab_auteurs[biblio.nbrAuteurs], biblio)) {

	} else {
		// Ajouter l'auteur à la bibliothèque
		biblio.tab_auteurs[biblio.nbrAuteurs].listeLivres[0] = indiceLivre;
		biblio.tab_auteurs[biblio.nbrAuteurs].nbrLivresAuteur = 1;
		// SAUVEGARDE ICI

		// Ajouter l'auteur au livre
		livre.ListeAuteurs[livre.nbrAuteurs] = biblio.nbrAuteurs;
		livre.nbrAuteurs++;

		// On augmente le nombre d'auteurs
		biblio.nbrAuteurs++;
	}
}