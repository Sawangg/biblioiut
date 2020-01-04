#include <iostream>

#include "Header.h"
using namespace std;

// Créer le titre avant...
void creationListeContraintes(Liste<string>& options, Liste<Contraintes> contraintes) {
	options.nbElements = 0;

	for (int i = 0; i < contraintes.nbElements; i++) {
		options.ListeElements[options.nbElements + 1] = descriptionContrainte(contraintes.ListeElements[i]);
		options.nbElements++;
	}
	options.ListeElements[options.nbElements + 1] = "Retour";
	options.nbElements++;
}

void ajoutContrainte(Liste<Contraintes>& contraintes, string typeRestriction, string restriction) {
	Contraintes contrainte;

	contrainte.contrainte1 = typeRestriction + "=" + restriction;
	contrainte.positionContrainte1 = contraintes.nbElements;
	contrainte.operateur = "ET";
	contrainte.contrainte2 = typeRestriction + "=" + restriction;
	contrainte.positionContrainte2 = contraintes.nbElements;

	if (!verifContrainteExistanteBibliotheque(contrainte, contraintes)) {
		contraintes.ListeElements[contraintes.nbElements] = contrainte;
		contraintes.nbElements++;
		cout << green << "La contrainte: " << descriptionContrainte(contrainte) << ", a bien été ajoutée" << normal << endl;
	} else {
		cout << red << "La contrainte: " << descriptionContrainte(contrainte) << ", existe déjà..." << normal << endl;
	}
}
string descriptionContrainte(Contraintes contrainte) {
	string description;

	if (contrainte.positionContrainte1 == contrainte.positionContrainte2) {
		string type, data;
		decompositionContrainte(contrainte, type, data);
		
		if (type == "TitreCompletLivre") {
			description = "Titre est égal à " + data;
		} else if (type == "TitreBoutLivre") {
			description = "Titre contient " + data;
		} else if (type == "DateLivre") {
			description = "Livre paru le " + data;
		} else if (type == "GenreLivre") {
			description = "Le genre du livre est " + data;
		} else if (type == "NomAuteur") {
			description = "Le nom de l'auteur est " + data;
		} else if (type == "PrenomAuteur") {
			description = "Le prénom de l'auteur est " + data;
		} else if (type == "NaissanceAuteur") {
			description = "L'auteur est né le " + data;
		} else if (type == "MortAuteur") {
			description = "L'auteur est mort la " + data;
		} else {
			description = string(red) + "Erreur inconnue" + string(normal);
		}
	} else {
		description = "Contrainte numéro " + convertInt2String(contrainte.positionContrainte1) + " " + contrainte.operateur + " " + "Contrainte numéro " + convertInt2String(contrainte.positionContrainte2);
	}

	return description;
}

void contrainteTitre(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	string information;
	Contraintes contrainte;

	Liste<string> options;
	options.ListeElements[0] = createTitre("Contrainte sur le titre");
	options.ListeElements[1] = "Contrainte sur son titre complet";
	options.ListeElements[2] = "Contrainte sur un bout de son titre";
	options.ListeElements[3] = "Retour";
	options.nbElements = 3;

	switch (menu(options, LIST_NOINDENT, NUMERIC, true)) {
	case 1:
		cout << "Merci de rentrer un titre: ";
		getline(cin, information);

		ajoutContrainte(contraintes, "TitreCompletLivre", information);
		system("pause");
		break;
	case 2:
		cout << "Merci de rentrer un bout de titre: ";
		getline(cin, information);

		ajoutContrainte(contraintes, "TitreBoutLivre", information);
		system("pause");
		break;
	case 3:
		// On quitte le menu sans rien faire
		break;
	default:
		break;
	}
}

void contrainteGenre(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int indiceGenre;
	Contraintes contrainte;

	Liste<string> options;
	options.ListeElements [0] = "Sélectionnez le genre\n";
	for (int i = 0; i < 19; i++) {
		options.ListeElements[i + 1] = GENRES.ListeElements[i];
	}
	options.nbElements = GENRES.nbElements;
	indiceGenre = menu(options, LIST_NOINDENT, NUMERIC, false) - 1;

	if (indiceGenre < GENRES.nbElements) {
		ajoutContrainte(contraintes, "GenreLivre", GENRES.ListeElements[indiceGenre]);
		system("pause");
	} else {
		// On quitte le menu sans rien faire
	}
}

void contrainteAuteur(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	Contraintes contrainte;
	string information;

	Liste<string> options;
	options.ListeElements[0] = createTitre("Contrainte sur l'auteur");
	options.ListeElements[1] = "Contrainte sur le nom de l'auteur";
	options.ListeElements[2] = "Contrainte sur le prénom de l'auteur";
	options.ListeElements[3] = "Contrainte sur la date de naissance de l'auteur";
	options.ListeElements[4] = "Contrainte sur par la date de mort de l'auteur";
	options.ListeElements[5] = "Retour";
	options.nbElements = 5;

	switch (menu(options, LIST_NOINDENT, NUMERIC, true)) {
	case 1:
		cout << "Merci de rentrer le nom de l'auteur: ";
		getline(cin, information);

		ajoutContrainte(contraintes, "NomAuteur", information);
		system("pause");
		break;
	case 2:
		cout << "Merci de rentrer le prénom de l'auteur: ";
		getline(cin, information);

		ajoutContrainte(contraintes, "PrénomAuteur", information);
		system("pause");
		break;
	case 3:
		// Saisie de a date
		cout << "Entrez la date de naissance de l'auteur" << endl;
		information = convertDate2String(saisieDate());

		ajoutContrainte(contraintes, "NaissanceAuteur", information);
		system("pause");
		break;
	case 4:
		cout << "Entrez la date de mort de l'auteur" << endl;
		information = convertDate2String(saisieDate());

		ajoutContrainte(contraintes, "MortAuteur", information);
		system("pause");
		break;
	case 5:
		// On quitte le menu sans rien faire
		break;
	default:
		break;
	}
}

void contrainteDate(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	string information;
	Contraintes contrainte;

	cout << "Entrez la date de parution: " << endl;
	information = convertDate2String(saisieDate());

	ajoutContrainte(contraintes, "DateLivre", information);
	system("pause");
}

void decompositionContrainte(Contraintes contrainte, string& type, string& data) {
	int z = 0;
	while (z < contrainte.contrainte1.length() && contrainte.contrainte1[z] != '=') {
		type += contrainte.contrainte1[z];
		z++;
	}
	z++;
	while (z < contrainte.contrainte1.length()) {
		data += contrainte.contrainte1[z];
		z++;
	}
}

void modificationContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int selection;
	string type, data;
	Date date;
	Liste<string> options;

	

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

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << "Nouvelle contrainte: Le titre doit contenir " << data << endl;
					system("pause");
				} else if (type == "GenreLivre") {
					// Selection genre... //
					Liste<string> optionsGenre;
					optionsGenre.ListeElements[0] = "Sélectionnez le genre\n";
					for (int i = 0; i < 19; i++) {
						optionsGenre.ListeElements[i + 1] = GENRES.ListeElements[i];
					}
					optionsGenre.nbElements = 19;
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					data = convertInt2String(menu(options, LIST_NOINDENT, NUMERIC, false) - 1);

					contraintes.ListeElements[selection].contrainte1 = type + "=" + GENRES.ListeElements[convertString2Int(data)];
					contraintes.ListeElements[selection].contrainte2 = type + "=" + GENRES.ListeElements[convertString2Int(data)];
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "DateLivre") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de parution." << endl;
					date = saisieDate();
					data = verifDate(date.annee, date.mois, date.jour);
					while (data != "") {
						cout << red << data << normal << "Rentrez la nouvelle date de parution." << endl;
						date = saisieDate();
						data = verifDate(date.annee, date.mois, date.jour);
					}

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

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "PrenomAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Saisissez le nouveau prénom de l'auteur: ";
					getline(cin, data);
					while (data == "") {
						cout << red << "La saisie ne peut pas etre vide... " << normal << "Saisissez le nouveau prénom de l'auteur: ";
						getline(cin, data);
					}

					contraintes.ListeElements[selection].contrainte1 = type + "=" + data;
					contraintes.ListeElements[selection].contrainte2 = type + "=" + data;
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "NaissanceAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de naissance de l'auteur." << endl;
					date = saisieDate();
					data = verifDate(date.annee, date.mois, date.jour);
					while (data != "") {
						cout << red << data << normal << "Rentrez la nouvelle date de naissance de l'auteur." << endl;
						date = saisieDate();
						data = verifDate(date.annee, date.mois, date.jour);
					}

					contraintes.ListeElements[selection].contrainte1 = type + "=" + convertDate2String(date);
					contraintes.ListeElements[selection].contrainte2 = type + "=" + convertDate2String(date);
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else if (type == "MortAuteur") {
					cout << cyan << "Contrainte actuelle: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					cout << "Rentrez la nouvelle date de mort de l'auteur." << endl;
					date = saisieDate();
					data = verifDate(date.annee, date.mois, date.jour);
					while (data != "") {
						cout << red << data << normal << "Rentrez la nouvelle date de mort de l'auteur." << endl;
						date = saisieDate();
						data = verifDate(date.annee, date.mois, date.jour);
					}

					contraintes.ListeElements[selection].contrainte1 = type + "=" + convertDate2String(date);
					contraintes.ListeElements[selection].contrainte2 = type + "=" + convertDate2String(date);
					cout << cyan << "Nouvelle contrainte: " << descriptionContrainte(contraintes.ListeElements[selection]) << normal << endl;
					system("pause");
				} else {
					cout << red << "Erreur inconnue..." << normal << endl;
					system("pause");
				}
			} else {
				cout << yellow << "Il n'est pas possible de modifier un groupe de contraintes. Vous devez la supprimer et en recréer une nouvelle..." << normal << endl;
				system("pause");
			}
		}
	} while (selection != options.nbElements - 1);
}

void suppressionContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int selection;
	string type, data;
	Date date;

	Liste<string> options;
	Liste<int> indicesContraintes;

	options.ListeElements[options.nbElements] = createTitre("Suppression contrainte");
	creationListeContraintes(options, contraintes);

	selection = menu(options, LIST_NOINDENT, NUMERIC, true) - 1;
	if (selection != options.nbElements - 1) {
		// Vérifier qu'elle n'est pas utilisée...
		utilisationContrainte(contraintes, selection, indicesContraintes);
		if (indicesContraintes.nbElements == 0) {
			// Remplacer par la dernière...
			contraintes.ListeElements[selection] = contraintes.ListeElements[contraintes.nbElements];
			contraintes.nbElements--;
			// Modifier les contraintes utilisant la dernière...
			utilisationContrainte(contraintes, contraintes.nbElements + 1, indicesContraintes);
			for (int i = 0; i < indicesContraintes.nbElements; i++) {
				if (contraintes.ListeElements[i].positionContrainte1 == contraintes.nbElements + 1) {
					contraintes.ListeElements[i].positionContrainte1 = selection;
				}
				if (contraintes.ListeElements[i].positionContrainte2 == contraintes.nbElements + 1) {
					contraintes.ListeElements[i].positionContrainte2 = selection;
				}
			}
		} else {
			cout << red << "Vous ne pouvez pas supprimer cette contrainte car elle est utilisée dans un groupe de contraintes..." << normal << endl;
			system("pause");
		}
	}
}

void utilisationContrainte(Liste<Contraintes> contraintes, int indiceContrainte, Liste<int>& indicesContraintes) {
	indicesContraintes.nbElements = 0;

	for (int i = 0; i < contraintes.nbElements; i++) {
		if (i != indiceContrainte) {
			if (contraintes.ListeElements[i].positionContrainte1 == indiceContrainte || contraintes.ListeElements[i].positionContrainte2 == indiceContrainte) {
				indicesContraintes.ListeElements[indicesContraintes.nbElements] = i;
				indicesContraintes.nbElements++;
			}
		}
	}
}