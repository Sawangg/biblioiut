#include <iostream>

#include "Header.h"
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
			suppressionLivre(biblio, indiceLivre);
			indiceLivres.ListeElements[indiceLivre] = indiceLivres.ListeElements[indiceLivres.nbElements - 1];
			indiceLivres.nbElements--;
			cout << green << "Le livre a bien \202t\202 supprim\202 !" << normal << endl;
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
			cout << cyan << "Titre actuel : " << biblio.bibliothequeLivre.ListeElements[indiceLivre].titre << normal << endl;
			cout << "Entrez le nouveau titre: ";
			getline(cin, data);
			while (data == "") {
				cout << "Entrez le nouveau titre : ";
				getline(cin, data);
			}
			biblio.bibliothequeLivre.ListeElements[indiceLivre].titre = data;
			cout << green << "Le titre a bien \202t\202 chang\202 !" << normal << endl;
			system("pause");
			break;
		case 2:
			cout << cyan << "Genre actuel : " << biblio.bibliothequeLivre.ListeElements[indiceLivre].genre << normal << endl;
			optionsGenre.ListeElements[0] = "S\202lectionnez le nouveau genre\n";
			for (int i = 0; i < 19; i++) {
				optionsGenre.ListeElements[i + 1] = GENRES.ListeElements[i];
			}
			optionsGenre.nbElements = 19;
			data = convertInt2String(menu(options, LIST_NOINDENT, NUMERIC, false) - 1);
			biblio.bibliothequeLivre.ListeElements[indiceLivre].genre = GENRES.ListeElements[convertString2Int(data)];
			cout << green << "Le genre a bien \202t\202 chang\202 !" << normal << endl;
			system("pause");
			break;
		case 3:
			cout << cyan << "Nombre de pages actuel : " << biblio.bibliothequeLivre.ListeElements[indiceLivre].pages << normal << endl;
			cout << "Entrer le nouveau nombre de pages : " << normal;
			data = convertInt2String(ControleEntier());
			biblio.bibliothequeLivre.ListeElements[indiceLivre].pages = convertString2Int(data);
			cout << green << "Le nombre de pages a bien \202t\202 chang\202 !" << normal << endl;
			system("pause");
			break;
		case 4:
			cout << cyan << "Date de parution actuelle: " << convertDate2String(biblio.bibliothequeLivre.ListeElements[indiceLivre].date) << normal << endl;
			cout << "Entrez la nouvelle date de parution" << endl;
			// Vérification de la date -> pas avant la naissance de l'auteur et pas après...
			biblio.bibliothequeLivre.ListeElements[indiceLivre].date = saisieDate();
			cout << green << "La date de parution a bien \202t\202 chang\202 !" << normal << endl;
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
		options.ListeElements[0] = createTitre("Modification de ou des auteur(s) du livre");
		options.ListeElements[1] = "Supprimer un auteur";
		options.ListeElements[2] = "Ajouter un auteur";
		options.ListeElements[3] = "Retour";
		options.nbElements = 3;
		choix = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choix) {
		case 1:
			if (biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements > 1) {
				// Supprimer un auteur
				do {
					options.ListeElements[0] = "S\202lectionner un auteur \205 supprimer";
					for (int i = 0; i < biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements; i++) {
						options.ListeElements[i + 1] = biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i]].nom;
						options.ListeElements[i + 1] += " " + biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i]].prenom + " nait le ";
						options.ListeElements[i + 1] += convertDate2String(biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i]].dateN);
						if (biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i]].dateM.jour != 0) {
							options.ListeElements[i + 1] += " et mort le " + convertDate2String(biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i]].dateM);
						}
					}
					options.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements + 1] = "Retour";
					options.nbElements = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements + 1;

					indiceAuteurLivre = menu(options, LIST_NOINDENT, NUMERIC, false) - 1;
					if (indiceAuteurLivre != options.nbElements - 1) {
						// Retirer le livre à l'auteur
						bool livre = false;
						int z = 0;
						while (z < biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.nbElements && !livre) {
							if (biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.ListeElements[z] == indiceLivre) {
								biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.ListeElements[z] = biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.nbElements - 1];
								biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.nbElements--;
								livre = true;
							}
							z++;
						}
						if (biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]].livresAuteur.nbElements == 0) {
							suppressionAuteur(biblio, biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre]);
						}

						// On retire l'auteur au livre
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[indiceAuteurLivre] = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements - 1];
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements--;
						
						cout << green << "L'auteur a bien \202t\202 supprim\202 !" << normal << endl;
						system("pause");
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