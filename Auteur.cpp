#include <iostream>
#include <string>

#include "biblio.h"
#include "color.h"
#include "controle.h"

using namespace std;

void  saisieAuteur(Bibliotheque& biblio, Livre& livre, int indiceLivre) {
	void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque & biblio);
	void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque & biblio);

	Date saisieDate();
	Auteur newAuteur;
	string mort;

	cout << "Quel est le nom de l'auteur ?" << endl;
	getline(cin, newAuteur.nom);
	while (newAuteur.nom == "") {
		cout << red << "Le nom de l'auteur ne peut pas être vide..." << normal << "Quel est le nom de l'auteur ?" << endl;
		getline(cin, newAuteur.nom);
	}

	cout << "Quel est le prénom de l'auteur ?" << endl;
	getline(cin, newAuteur.prenom);
	while (newAuteur.prenom == "") {
		cout << red << "Le prénom de l'auteur ne peut pas être vide..." << normal << "Quel est le prénom de l'auteur ?" << endl;
		getline(cin, newAuteur.prenom);
	}

	cout << "Quel est la date de naissance de l'auteur ?" << endl;
	newAuteur.dateN = saisieDate();

	cout << "L'auteur est-il mort (O/N) ? ";
	getline(cin, mort);
	while (mort != "O" && mort != "o" && mort != "N" && mort != "n") {
		cout << red << "Votre choix est invalide!" << normal << " L'auteur est-il mort (O/N) ? ";
		getline(cin, mort);
	}
	if (mort == "O" || mort == "o") {
		cout << "Quel est la date de mort de l'auteur ?" << endl;
		newAuteur.dateM = saisieDate();
	} else {
		newAuteur.dateM.jour = 0;
		newAuteur.dateM.mois = 0;
		newAuteur.dateM.annee = 0;
	}
	
	int position = auteurExistantBibliotheque(newAuteur, biblio);
	if (position == biblio.nbrAuteurs) {
		ajoutAuteurBibliotheque(newAuteur, biblio);
		ajoutAuteurLivre(position, indiceLivre, biblio);
	} else {
		ajoutAuteurLivre(position, indiceLivre, biblio);
	}
	
}

void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque& biblio) {
		// L'auteur n'existe pas...

		// Ajouter l'auteur à la bibliothèque
		biblio.tab_auteurs[biblio.nbrAuteurs] = auteur;
		// On augmente le nombre d'auteurs de la bibliothèque
		biblio.nbrAuteurs++;

		// SAUVEGARDE ICI
}

void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque& biblio) {
	// On vérifie s'il existe dans le livre
	int i = 0;
	bool trouve = false;
	while (i < biblio.tab_livres[indiceLivre].nbrAuteurs && !trouve) {
		if (biblio.tab_livres[indiceLivre].ListeAuteurs[i] == indiceAuteur) {
			// L'auteur existe déjà
			trouve = true;
		}
		i++;
	}

	if (!trouve) {
		// Ajouter l'auteur au livre car il n'existe pas
		biblio.tab_livres[indiceLivre].ListeAuteurs[biblio.tab_livres[indiceLivre].nbrAuteurs] = indiceAuteur;
		biblio.tab_livres[indiceLivre].nbrAuteurs++;

		// Ajouter le livre à l'auteur
		biblio.tab_auteurs[indiceAuteur].listeLivres[biblio.tab_auteurs[indiceAuteur].nbrLivresAuteur] = indiceLivre;
		biblio.tab_auteurs[indiceAuteur].nbrLivresAuteur++;
	} else {
		cout << yellow << "Cet auteur a déjà été rentré pour ce livre. " << normal;
	}
}