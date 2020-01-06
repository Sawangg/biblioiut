#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

void ModificationContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int selection;
	string type, data;
	Date date;
	Liste<string> options;

	Date dateInf, dateSup;

	do {
		options.ListeElements[options.nbElements] = createTitre("Modification contrainte");
		creationListeContraintes(options, contraintes);
		selection = menu(options, LIST_NOINDENT, NUMERIC, true) - 1;

		if (selection != options.nbElements - 1) {
			if (contraintes.ListeElements[selection].positionContrainte1 == contraintes.ListeElements[selection].positionContrainte2) {
				decompositionContrainte(contraintes.ListeElements[selection], type, data);
				if (type == "TitreCompletLivre") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Saisissez le nouveau titre: ";
					getline(cin, data);
					while (data == "") {
						cout << red << "Le titre ne peut pas etre vide... " << normal << "Saisissez le nouveau titre: ";
						getline(cin, data);
					}
					data = removeAllIndesirableSpace(data);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "TitreBoutLivre") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Saisissez le nouveau bout de titre: ";
					getline(cin, data);
					while (data == "") {
						cout << red << "La saisie ne peut pas etre vide... " << normal << "Saisissez le nouveau bout de titre: ";
						getline(cin, data);
					}
					data = removeAllIndesirableSpace(data);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << "Nouvelle contrainte: Le titre doit contenir " << data << endl;
					system("pause");
				} else if (type == "GenreLivre") {
					// Selection genre... //
					Liste<string> optionsGenre;
					optionsGenre.ListeElements[0] = "S\202lectionnez le genre\n";
					for (int i = 0; i < 19; i++) {
						optionsGenre.ListeElements[i + 1] = GENRES.ListeElements[i];
					}
					optionsGenre.nbElements = 19;
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					data = convertInt2String(menu(optionsGenre, LIST_NOINDENT, NUMERIC, false) - 1);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + GENRES.ListeElements[convertString2Int(data)];
					contraintes.ListeElements[selection].contrainte2 = type + "=" + GENRES.ListeElements[convertString2Int(data)];
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "DateLivre") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de parution." << endl;
					date = saisieDate(dateInf, dateSup);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + convertDate2String(date);
					contraintes.ListeElements[selection].contrainte2 = type + "=" + convertDate2String(date);
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "NomAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Saisissez le nouveau nom de l'auteur: ";
					getline(cin, data);
					while (data == "") {
						cout << red << "La saisie ne peut pas etre vide... " << normal << "Saisissez le nouveau nom de l'auteur: ";
						getline(cin, data);
					}
					data = removeAllIndesirableSpace(data);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "PrenomAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Saisissez le nouveau pr\202nom de l'auteur: ";
					getline(cin, data);
					while (data == "") {
						cout << red << "La saisie ne peut pas etre vide... " << normal << "Saisissez le nouveau pr\202nom de l'auteur: ";
						getline(cin, data);
					}
					data = removeAllIndesirableSpace(data);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "NaissanceAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de naissance de l'auteur." << endl;
					date = saisieDate(dateInf, dateSup);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + convertDate2String(date);
					contraintes.ListeElements[selection].contrainte2 = type + "=" + convertDate2String(date);
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "MortAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de mort de l'auteur." << endl;
					date = saisieDate(dateInf, dateSup);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + convertDate2String(date);
					contraintes.ListeElements[selection].contrainte2 = type + "=" + convertDate2String(date);
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else {
					cout << red << "Erreur inconnue..." << normal << endl;
					system("pause");
				}
			} else {
				cout << yellow << "Il n'est pas possible de modifier un groupe de contraintes. Vous devez la supprimer et en recr\202er une nouvelle..." << normal << endl;
				system("pause");
			}
		}
	} while (selection != options.nbElements - 1);
}
