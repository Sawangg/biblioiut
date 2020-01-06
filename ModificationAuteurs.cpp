#include <iostream>
#include "BiblioUtilitaire.h"

using namespace std;

void ModificationAuteurs(Bibliotheque& biblio) {
	Liste<string> options;
	int choix;
	bool repeter;

	do {
		choix = selectionAuteur(biblio, createTitre("Selection auteur \205 modifier"), LIST_NOINDENT, true);

		if (choix != biblio.bibliothequeAuteur.nbElements) {
			modificationAuteur(biblio, choix);
			repeter = true;
		} else {
			repeter = false;
		}
	} while (repeter);
}

void modificationAuteur(Bibliotheque& biblio, int indiceAuteur) {
	Liste<string> options, options2;
	int choix, choix2, compteur = 0;
	bool trouve = false;
	string data = "";

	do {
		Date dateInf, dateSup;

		options.ListeElements[0] = createTitre("Modification auteur");
		options.ListeElements[1] = "Modifier le nom de l'auteur";
		options.ListeElements[2] = "Modifier le pr\202nom de l'auteur";
		options.ListeElements[3] = "Modifier la date de naissance de l'auteur";
		options.ListeElements[4] = "Modifier la date de mort de l'auteur";
		options.ListeElements[5] = "Ajouter un livre \205 l'auteur";
		options.ListeElements[6] = "Supprimer un livre \205 l'auteur";
		options.ListeElements[7] = "Supprimer l'auteur";
		options.ListeElements[8] = "Retour";
		options.nbElements = 8;

		choix = menu(options, LIST_NOINDENT, NUMERIC, true);
		switch (choix) {
		case 1:
			cout << cyan << "Nom actuel de l'auteur: " << biblio.bibliothequeAuteur.ListeElements[indiceAuteur].nom << normal << endl;
			cout << "Entrez le nouveau nom de l'auteur: ";
			getline(cin, data);
			while (removeAllIndesirableSpace(data) == "") {
				cout << red << "Le nom de l'auteur ne peut pas \210tre vide... " << normal << "Entrez le nouveau nom de l'auteur: ";
				getline(cin, data);
			}
			data = removeAllIndesirableSpace(data);
			biblio.bibliothequeAuteur.ListeElements[indiceAuteur].nom = removeAllIndesirableSpace(data);
			cout << cyan << "Nouveau nom de l'auteur: " << biblio.bibliothequeAuteur.ListeElements[indiceAuteur].nom << normal << endl;
			system("pause");
			break;
		case 2:
			cout << cyan << "Pr\202nom actuel de l'auteur: " << biblio.bibliothequeAuteur.ListeElements[indiceAuteur].prenom << normal << endl;
			cout << "Entrez le nouveau pr\202nom de l'auteur: ";
			getline(cin, data);
			while (removeAllIndesirableSpace(data) == "") {
				cout << red << "Le pr\202nom de l'auteur ne peut pas \210tre vide... " << normal << "Entrez le nouveau pr\202nom de l'auteur: ";
				getline(cin, data);
			}
			data = removeAllIndesirableSpace(data);
			biblio.bibliothequeAuteur.ListeElements[indiceAuteur].prenom = removeAllIndesirableSpace(data);
			cout << cyan << "Nouveau pr\202nom de l'auteur: " << biblio.bibliothequeAuteur.ListeElements[indiceAuteur].prenom << normal << endl;
			system("pause");
			break;
		case 3:
			cout << cyan << "Date de naissance actuelle de l'auteur: " << convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN) << normal << endl;
			cout << "Saisissez la nouvelle date de naissance: ";
			for (int i = 0; i < biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements; i++) {
				int indiceLivre = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[i];
				if (dateSup.jour == -1) {
					dateSup = biblio.bibliothequeLivre.ListeElements[indiceLivre].date;
				} else {
					dateSup = getDateSup(dateSup, biblio.bibliothequeLivre.ListeElements[indiceLivre].date);
				}
			}
			data = convertDate2String(saisieDate(dateInf, dateSup));
			biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN = convertString2Date(data);
			cout << cyan << "Nouvelle date de naissance de l'auteur: " << convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN) << normal << endl;
			system("pause");
			break;
		case 4:
			cout << cyan << "Date de mort actuelle de l'auteur: " << convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM) << normal << endl;
			cout << "Saisissez la nouvelle date de mort: ";
			dateInf = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN;
			for (int i = 0; i < biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements; i++) {
				int indiceLivre = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[i];
				if (dateInf.jour == -1) {
					dateInf = biblio.bibliothequeLivre.ListeElements[indiceLivre].date;
				} else {
					dateInf = getDateSup(dateInf, biblio.bibliothequeLivre.ListeElements[indiceLivre].date);
				}
			}
			data = convertDate2String(saisieDate(dateInf, dateSup));
			biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM = convertString2Date(data);
			cout << cyan << "Nouvelle date de mort de l'auteur: " << convertDate2String(biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM) << normal << endl;
			system("pause");
			break;
		case 5:
			do {
				options2.nbElements = 0;
				options2.ListeElements[0] = createTitre("S\202lection du livre \205 ajouter");
				for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {						
					options2.ListeElements[options2.nbElements + 1] = biblio.bibliothequeLivre.ListeElements[i].titre;
					options2.nbElements++;
				}
				options2.ListeElements[options2.nbElements + 1] = "Retour";
				options2.nbElements++;

				choix2 = menu(options2, LIST_NOINDENT, NUMERIC, true);
				if (choix2 != options2.nbElements) {
					compteur = 0;
					trouve = false;
					while (compteur < biblio.bibliothequeLivre.ListeElements[choix2 - 1].auteursLivre.nbElements && !trouve) {
						if (biblio.bibliothequeLivre.ListeElements[choix2 - 1].auteursLivre.ListeElements[compteur] == indiceAuteur) {
							trouve = true;
						}
						compteur++;
					}

					if (!trouve) {
						// On ajoute le livre \205 l'auteur
						biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements] = choix2 - 1;
						biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements++;

						// On ajoute l'auteur au livre
						biblio.bibliothequeLivre.ListeElements[choix2 - 1].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[choix2 - 1].auteursLivre.nbElements] = indiceAuteur;
						biblio.bibliothequeLivre.ListeElements[choix2 - 1].auteursLivre.nbElements++;

						cout << green << "Le livre a bien \202t\202 ajout\202 \205 l'auteur..." << normal << endl;
						system("pause");
					} else {
						cout << red << "Cet auteur a d\202j\205 \202crit ce livre..." << normal << endl;
						system("pause");
					}
				}
			} while (choix2 != options2.nbElements);
			break;
		case 6:
			do {
				options2.nbElements = 0;
				options2.ListeElements[0] = createTitre("S\202lection du livre \205 supprimer");
				for (int i = 0; i < biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements; i++) {
					options2.ListeElements[options2.nbElements + 1] = biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[i]].titre;
					options2.nbElements++;
				}
				options2.ListeElements[options2.nbElements + 1] = "Retour";
				options2.nbElements++;

				choix2 = menu(options2, LIST_NOINDENT, NUMERIC, true);
				if (choix2 != options2.nbElements) {
					int indiceLivre = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[choix2 - 1];
					if (biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements == 1) {
						cout << red << "Vous ne pouvez pas supprimer ce livre car il n'a qu'un auteur. Ajoutez un auteur au livre et r\202essayez..." << normal << endl;
						system("pause");
					} else {
						if (biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements == 1) {
							if (requeteNouveau("Cet auteur n'a qu'un livre, en supprimant cet auteur de la liste des auteurs du livre vous supprimerez aussi l'auteur, \210tes vous sûr de vouloir continuer ?") == "O") {
								suppressionAuteurBibliotheque(biblio, indiceAuteur);
								cout << green << "L'auteur a bien \202t\202 supprim\202..." << normal << endl;
								system("pause");
							} else {
								// Ne rien faire
							}
						} else {
							suppressionLivreAuteur(biblio, indiceLivre, indiceAuteur);

							cout << green << "Le livre a bien \202t\202 supprim\202 de la liste des livres de l'auteur..." << normal << endl;
							system("pause");
						}
					}
				}
			} while (choix2 != options2.nbElements);
			break;
		case 7:
			compteur = 0;
			trouve = false;
			while (compteur < biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements && !trouve) {
				if (biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[compteur]].auteursLivre.nbElements == 1) {
					trouve = true;
				}
				compteur++;
			}

			if (trouve) {
				cout << red << "Vous ne pouvez pas supprimer cet auteur car l'un des livres qu'il a \202crit ne comporte qu'un auteur..." << normal << endl;
				system("pause");
			} else {
				suppressionAuteurBibliotheque(biblio, indiceAuteur);
				indiceAuteur = -1;
				cout << green << "L'auteur a bien \202t\202 supprim\202..." << normal << endl;
				system("pause");
			}
			break;
		default:
			break;
		}
	} while (choix != options.nbElements && indiceAuteur >= 0);
}