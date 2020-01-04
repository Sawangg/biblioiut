#include <iostream>
#include <sstream>

#include "Header.h"
using namespace std;

void ajoutLivre(Bibliotheque& biblio) {
	int genre;
	Liste<string> options;

	COORD cursor;
	string titre = "";
	int pages;

	system("cls");
	cout << createTitre("Ajout d'un livre");

	// Saisie du titre du livre
	getCoordCursor(cursor);
	cout << cyan << "Entrer le nom du livre :" << normal << endl;
	getline(cin, titre);
	while (titre == "") {
		cout << red << "Entrer un nom de livre valide !" << normal << endl;
		cout << cyan << "Entrer le nom du livre :" << normal << endl;
		getline(cin, titre);
	}
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].titre = titre;
	cleanLine(cursor);
	cout << cyan << "Le titre du livre est " << normal << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].titre << endl;
	cout << endl;

	// Ajout du / des auteur(s) au livre
	ajoutAuteurs(biblio, biblio.bibliothequeLivre.nbElements);
	cout << cyan <<  "Le livre a " << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].auteursLivre.nbElements << " auteur(s) " << normal << endl;
	cout << endl;

	// Ajout du genre au livre
	getCoordCursor(cursor);
	options.ListeElements[0] = "S\202lectionnez le genre\n";
	for (int i = 0; i < 19; i++) {
		options.ListeElements[i + 1] = GENRES.ListeElements[i];
	}
	options.nbElements = GENRES.nbElements;
	genre = menu(options, LIST_INDENT, NUMERIC, false) - 1;
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].genre = GENRES.ListeElements[genre];
	cleanLine(cursor);
	cout << cyan << "Le genre s\202lectionn\202 est : " << normal << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].genre << endl;
	cout << endl;

	// Ajout de la date au livre
	getCoordCursor(cursor);
	cout << "Entrez la date de parution" << endl;
	Date date = saisieDate();
	// Vérification de la date -> pas avant la naissance de l'auteur et pas après...
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].date = date;
	cleanLine(cursor);
	cout << cyan << "Le livre est paru le " << normal << convertDate2String(biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].date) << endl;
	cout << endl;

	// Ajout du nombre de pages du livre
	cout << cyan << "Entrer le nombre de pages : " << normal;
	pages = ControleEntier();
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].pages = pages;
	cout << endl;

	// Vérifier livre existant...
	if (verifLivreExistantBibliotheque(biblio.bibliothequeLivre, biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements])) {
		cout << yellow << "Le livre existe d\202j\205 dans la biblioth\212que !" << normal << endl;
	} else {
		// Confirmation de l'ajout
		biblio.bibliothequeLivre.nbElements++;
		cout << green << "Le livre a bien \202t\202 ajout\202 !" << normal << endl;
	}
	system("pause");
}

int selectionAuteur(Bibliotheque biblio) {
	Liste<string> options;

	options.ListeElements[0] = "S\202lectionnez un auteur\n";

	for (int i = 0; i < biblio.bibliothequeAuteur.nbElements; i++) {
		options.ListeElements[i + 1] = biblio.bibliothequeAuteur.ListeElements[i].nom;
		options.ListeElements[i + 1] += " " + biblio.bibliothequeAuteur.ListeElements[i].prenom + " nait le ";
		options.ListeElements[i + 1] += convertDate2String(biblio.bibliothequeAuteur.ListeElements[i].dateN);
		if (biblio.bibliothequeAuteur.ListeElements[i].dateM.jour != 0) {
			options.ListeElements[i + 1] += " et mort le " + convertDate2String(biblio.bibliothequeAuteur.ListeElements[i].dateM);
		}
	}
	options.ListeElements[biblio.bibliothequeAuteur.nbElements + 1] = "Retour";
	options.nbElements = biblio.bibliothequeAuteur.nbElements + 1;

	return menu(options, LIST_NOINDENT, NUMERIC, false) - 1;
}

string requeteNouveau(string message) {
	string nouveau;

	cout << message;
	getline(cin, nouveau);
	while (nouveau != "O" && nouveau != "o" && nouveau != "N" && nouveau != "n") {
		cout << red << "Votre choix est invalide !" << normal << " " << message;
		getline(cin, nouveau);
	}

	return nouveau;
}