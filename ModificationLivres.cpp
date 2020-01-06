#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

void ModificationLivre(Bibliotheque& biblio, Liste<int>& indiceLivres, int indiceLivre) {
	int choix;
	Liste<string> options;

	do {
		options.ListeElements[0] = createTitre("Modification du livre");
		options.ListeElements[1] = "Modifier les informations du livre";
		options.ListeElements[2] = "Supprimer le livre";
		options.ListeElements[3] = "Retour";
		options.nbElements = 3;
		choix = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choix) {
		case 1:
			// Modifier les informations
			modificationInformationsLivre(biblio, indiceLivre);
			break;
		case 2:
			// Supprimer le livre
			suppressionLivreBibliotheque(biblio, indiceLivre);
			indiceLivres.ListeElements[indiceLivre] = indiceLivres.ListeElements[indiceLivres.nbElements - 1];
			indiceLivres.nbElements--;
			cout << green << "Le livre a bien \202t\202 supprim\202..." << normal << endl;
			system("pause");
			break;
		case 3:
			// Quitter le menu
			break;
		default:
			break;
		}
	} while (choix != 3 && choix != 2);

}

void modificationInformationsLivre(Bibliotheque& biblio, int indiceLivre) {
	int choix, choix2;
	string data;

	Liste<string> options;
	Liste<string> optionsGenre;
	Date dateInf, dateSup;

	do {
		options.ListeElements[0] = createTitre("Modification donn\202es du livre");
		options.ListeElements[1] = "Modifier le titre du livre";
		options.ListeElements[2] = "Modifier le genre du livre";
		options.ListeElements[3] = "Modifier le nombre de pages du livre";
		options.ListeElements[4] = "Modifier la date de parution du livre";
		options.ListeElements[5] = "Modifier les auteurs associ\202s au livre";
		options.ListeElements[6] = "Retour";
		options.nbElements = 6;
		choix = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choix) {
		case 1:
			cout << cyan << "Titre actuel: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].titre << normal << endl;
			cout << "Entrez le nouveau titre: ";
			getline(cin, data);
			while (data == "") {
				cout << "Entrez le nouveau titre: ";
				getline(cin, data);
			}
			data = removeAllIndesirableSpace(data);
			biblio.bibliothequeLivre.ListeElements[indiceLivre].titre = data;
			cout << cyan << "Nouveau titre: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].titre << normal << endl;
			system("pause");
			break;
		case 2:
			cout << cyan << "Genre actuel: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].genre << normal << endl;
			data = convertInt2String(selectionGenre("S\202lectionnez le nouveau genre\n", LIST_NOINDENT, false));
			biblio.bibliothequeLivre.ListeElements[indiceLivre].genre = GENRES.ListeElements[convertString2Int(data)];
			cout << cyan << "Nouveau genre: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].genre << normal << endl;
			system("pause");
			break;
		case 3:
			cout << cyan << "Nombre de pages actuel: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].pages << normal << endl;
			cout << "Entrer le nombre de pages : " << normal;
			data = convertInt2String(ControleEntier());
			biblio.bibliothequeLivre.ListeElements[indiceLivre].pages = convertString2Int(data);
			cout << cyan << "Nouveau nombre de pages: " << biblio.bibliothequeLivre.ListeElements[indiceLivre].pages << normal << endl;
			system("pause");
			break;
		case 4:
			cout << cyan << "Date de parution actuelle: " << convertDate2String(biblio.bibliothequeLivre.ListeElements[indiceLivre].date) << normal << endl;
			cout << "Entrez la nouvelle date de parution" << endl;
			// Vérification de la date -> pas avant la naissance de l'auteur et pas après...
			for (int i = 0; i < biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements; i++) {
				int indiceAuteur = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i];
				if (dateInf.jour == -1) {
					dateInf = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN;
				} else {
					dateInf = getDateSup(dateInf, biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN);
				}

				dateSup = getDateInf(dateSup, biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM);
			}
			biblio.bibliothequeLivre.ListeElements[indiceLivre].date = saisieDate(dateInf, dateSup);
			cout << cyan << "Nouvelle date de parution: " << convertDate2String(biblio.bibliothequeLivre.ListeElements[indiceLivre].date) << normal << endl;
			system("pause");
			break;
		case 5:
			modificationAuteurLivre(biblio, indiceLivre);
			break;
		case 6:
			// On quitte le menu
			break;
		default:
			break;
		}
	} while (choix != 6);
}

void modificationAuteurLivre(Bibliotheque& biblio, int indiceLivre) {
	int choix, indiceAuteurLivre;
	Liste<string> options;

	do {
		options.ListeElements[0] = createTitre("Modification des auteurs du livre");
		options.ListeElements[1] = "Supprimer un auteur";
		options.ListeElements[2] = "Ajouter un auteur";
		options.ListeElements[3] = "Retour";
		options.nbElements = 3;
		choix = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choix) {
		case 1:
			if (biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements > 1) {
				do {
					indiceAuteurLivre = selectionAuteur(biblio, biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre, "S\202lectionner un auteur \205 supprimer", LIST_NOINDENT, false);
					if (indiceAuteurLivre != options.nbElements - 1) {
						suppressionAuteurLivre(biblio, biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre], indiceLivre);
						
						cout << green << "L'auteur a bien \202t\202 supprim\202 du livre !" << normal << endl;
						system("pause");
					} else {
						// Retour
					}
				} while (indiceAuteurLivre != options.nbElements - 1 && biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements > 1);
			} else {
				cout << red << "Le livre n'a qu'un auteur, vous ne pouvez donc pas le supprimer !" << normal << endl;
				system("pause");
			}
			break;
		case 2:
			ajoutAuteurs(biblio, indiceLivre);
		case 3:
			// Quitter ce menu
			break;
		default:
			break;
		}
	} while (choix != 3);
}