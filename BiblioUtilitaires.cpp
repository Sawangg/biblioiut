#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de gérer la sélection d'un auteur parmi une liste
//////
//////        ENTREES : biblio , chaîne, entier, booléen
//////        SORTIES : entier
//////
//////        Retourne l'indice de l'auteur sélectionné
//////
///////////////////////////////////////////////////////////////
int selectionAuteur(Bibliotheque biblio, string titre, int typeMenu, bool cls) {
	Liste<string> options;

	options.ListeElements[0] = titre;
	for (int i = 0; i < biblio.bibliothequeAuteur.nbElements; i++) {
		options.ListeElements[i + 1] = textSelectionAuteur(biblio, i);
	}
	options.ListeElements[biblio.bibliothequeAuteur.nbElements + 1] = "Retour";
	options.nbElements = biblio.bibliothequeAuteur.nbElements + 1;

	return menu(options, typeMenu, NUMERIC, cls) - 1;
}
int selectionAuteur(Bibliotheque biblio, Liste<int> indiceAuteurs, string titre, int typeMenu, bool cls) {
	Liste<string> options;

	options.ListeElements[0] = titre;

	for (int i = 0; i < indiceAuteurs.nbElements; i++) {
		options.ListeElements[i + 1] = textSelectionAuteur(biblio, indiceAuteurs.ListeElements[i]);
	}
	options.ListeElements[biblio.bibliothequeAuteur.nbElements + 1] = "Retour";
	options.nbElements = biblio.bibliothequeAuteur.nbElements + 1;

	return menu(options, typeMenu, NUMERIC, cls) - 1;
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de générer le texte de description d'un auteur...
//////
//////        ENTREES : biblio, entier
//////        SORTIES : chaîne
//////
///////////////////////////////////////////////////////////////
string textSelectionAuteur(Bibliotheque biblio, int indiceAuteur) {
	string info;

	info = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].nom;
	info += " " + biblio.bibliothequeAuteur.ListeElements[indiceAuteur].prenom + " n\202 le ";
	info += convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN);
	if (biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM.jour != 0) {
		info += " et mort le " + convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM);
	}

	return info;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de gérer la sélection d'un genre parmi une liste
//////
//////        ENTREES : chaîne, entier, booléen
//////        SORTIES : entier
//////
//////        Retourne l'indice du genre sélectionné
//////
///////////////////////////////////////////////////////////////
int selectionGenre(string titre, int typeMenu, bool cls) {
	Liste<string> options;

	options.ListeElements[0] = titre;
	for (int i = 0; i < 19; i++) {
		options.ListeElements[i + 1] = GENRES.ListeElements[i];
	}
	options.nbElements = GENRES.nbElements;

	return menu(options, LIST_NOINDENT, NUMERIC, false) - 1;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de gérer la saisie d'un auteur
//////
//////        ENTREES : RIEN
//////        SORTIES : auteur
//////
///////////////////////////////////////////////////////////////
Auteur saisieAuteur() {
	Auteur newAuteur;
	string mort;
	Date defaut;

	cout << "Quel est le nom de l'auteur ?" << endl;
	getline(cin, newAuteur.nom);
	while (newAuteur.nom == "") {
		cout << red << "Le nom de l'auteur ne peut pas \210tre vide..." << normal << "Quel est le nom de l'auteur ?" << endl;
		getline(cin, newAuteur.nom);
	}
	newAuteur.nom = removeAllIndesirableSpace(newAuteur.nom);

	cout << "Quel est le pr\202nom de l'auteur ?" << endl;
	getline(cin, newAuteur.prenom);
	while (newAuteur.prenom == "") {
		cout << red << "Le pr\202nom de l'auteur ne peut pas \210tre vide..." << normal << "Quel est le pr\202nom de l'auteur ?" << endl;
		getline(cin, newAuteur.prenom);
	}
	newAuteur.prenom = removeAllIndesirableSpace(newAuteur.prenom);

	cout << "Quel est la date de naissance de l'auteur ?" << endl;
	newAuteur.dateN = saisieDate(defaut, defaut);

	cout << "L'auteur est-il mort (O/N) ? ";
	getline(cin, mort);
	while (mort != "O" && mort != "o" && mort != "N" && mort != "n") {
		cout << red << "Votre choix est invalide!" << normal << " L'auteur est-il mort (O/N) ? ";
		getline(cin, mort);
	}
	if (mort == "O" || mort == "o") {
		cout << "Quel est la date de mort de l'auteur ?" << endl;
		newAuteur.dateM = saisieDate(newAuteur.dateN, defaut);
	} else {
		newAuteur.dateM.jour = -1;
		newAuteur.dateM.mois = 0;
		newAuteur.dateM.annee = 0;
	}

	return newAuteur;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de gérer l'ajout d'un auteur à la bibliothèque
//////
//////        ENTREES : auteur
//////        SORTIES : bibliothèque
//////
///////////////////////////////////////////////////////////////
void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque& biblio) {
	// Ajouter l'auteur \205 la biblioth\212que
	biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements] = auteur;
	// On augmente le nombre d'auteurs de la biblioth\212que
	biblio.bibliothequeAuteur.nbElements++;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de gérer l'ajour d'un auteur à un livre
//////
//////        ENTREES : entier, entier
//////        SORTIES : bibliotheque
//////
///////////////////////////////////////////////////////////////
void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque& biblio) {
	// Ajouter l'auteur au livre car il n'existe pas
	biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
	biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;

	// Ajouter le livre \205 l'auteur
	biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements] = indiceLivre;
	biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements++;

	cout << green << "L'auteur a bien \202t\202 ajout\202 au livre." << normal << endl;
}