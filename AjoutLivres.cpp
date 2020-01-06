#include <iostream>
#include <sstream>

#include "BiblioUtilitaire.h"
using namespace std;

void AjoutLivre(Bibliotheque& biblio) {
	int data;
	string titre = "";
	Date dateInf, dateSup;

	COORD cursor;

	system("cls");
	cout << createTitre("Ajout d'un livre");

	// Saisie du titre du livre
	getCoordCursor(cursor);
	cout << cyan << "Entrer le nom du livre: " << normal << endl;
	getline(cin, titre);
	while (titre == "") {
		cout << red << "Entrer un nom de livre valide !" << normal << endl;
		cout << cyan << "Entrer le nom du livre: " << normal;
		getline(cin, titre);
	}
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].titre = removeAllIndesirableSpace(titre);
	cleanLine(cursor);
	cout << cyan << "Le titre du livre est " << normal << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].titre << endl;
	cout << endl;

	// Ajout du / des auteur(s) au livre
	ajoutAuteurs(biblio, biblio.bibliothequeLivre.nbElements);
	cout << cyan <<  "Le livre a " << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].auteursLivre.nbElements << " auteur(s) " << normal << endl;
	cout << endl;

	// Ajout du genre au livre
	getCoordCursor(cursor);
	data = selectionGenre("S\202lectionnez le genre\n", LIST_NOINDENT, false);
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].genre = GENRES.ListeElements[data];
	cleanLine(cursor);
	cout << cyan << "Le genre s\202lectionn\202 est: " << normal << biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].genre << endl;
	cout << endl;

	// Ajout de la date au livre
	getCoordCursor(cursor);
	cout << "Entrez la date de parution" << endl;
	for (int i = 0; i < biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].auteursLivre.nbElements; i++) {
		int indiceAuteur = biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].auteursLivre.ListeElements[i];

		if (dateInf.jour == -1) {
			dateInf = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN;
		} else {
			dateInf = getDateSup(dateInf, biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateN);
		}

		dateSup = getDateInf(dateSup, biblio.bibliothequeAuteur.ListeElements[indiceAuteur].dateM);
	}
	Date date = saisieDate(dateInf, dateSup);
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].date = date;
	cleanLine(cursor);
	cout << cyan << "Le livre est paru le " << normal << convertDate2String(biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].date) << endl;
	cout << endl;

	// Ajout du nombre de pages du livre
	cout << cyan << "Entrer le nombre de pages : " << normal;
	data = ControleEntier();
	biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements].pages = data;
	cout << endl;

	// V\202rifier livre existant...
	if (verifLivreExistantBibliotheque(biblio.bibliothequeLivre, biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements])) {
		cout << yellow << "Le livre existe d\202j\205 dans la biblioth\212que..." << normal << endl;
	} else {
		// Confirmation de l'ajout
		biblio.bibliothequeLivre.nbElements++;
		cout << green << "Le livre a bien \202t\202 ajout\202 !" << normal << endl;
	}
	system("pause");
}

void ajoutAuteurs(Bibliotheque& biblio, int indiceLivre) {
	string nouveau = "O";
	COORD cursor;
	int indiceAuteur = 0, typeAjout;

	Auteur auteur;
	Liste<string> options;
	Date dateInfNaissance, dateSupNaissance, dateInfMort, dateSupMort;

	getCoordCursor(cursor);
	do {
		options.ListeElements[0] = "Ajout d'un auteur au livre: \n";
		options.ListeElements[1] = "Choisir un auteur parmi ceux enregistr\202s";
		options.ListeElements[2] = "Cr\202er un nouvel auteur";
		options.nbElements = 2;
		typeAjout = menu(options, LIST_INDENT, NUMERIC, false);
		cleanLine(cursor);

		switch (typeAjout) {
		case 1:
			// Affichage des auteurs existant (s'assurer qu'il y en a)
			if (biblio.bibliothequeAuteur.nbElements > 0 && biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements != biblio.bibliothequeAuteur.nbElements) {
				indiceAuteur = selectionAuteur(biblio, "S\202lectionner un auteur\n", LIST_INDENT, false);

				if (indiceAuteur < biblio.bibliothequeAuteur.nbElements) {
					if (!verifAuteurExistantLivre(biblio.bibliothequeLivre.ListeElements[indiceLivre], indiceAuteur)) {
						ajoutAuteurLivre(indiceAuteur, indiceLivre, biblio);
						nouveau = requeteNouveau("Voulez-vous ajouter un nouvel auteur au livre (O/N) ? ");
					} else {
						cout << yellow << "Cet auteur a d\202j\205 \202t\202 rentr\202 pour ce livre..." << normal << endl;
						system("pause");
					}
				} else {
					// retour
				}
			} else {
				cout << red << "Il n'y a pas d'auteurs enregistr\202s ou alors tous les auteurs enregistr\202s sont d\202j\205 associ\202s au livre..." << normal << endl;
				cout << cyan << "Cr\202ation de l'auteur: " << normal << endl;
				auteur = saisieAuteur();

				indiceAuteur = verifAuteurExistantBibliotheque(auteur, biblio);
				if (indiceAuteur == biblio.bibliothequeAuteur.nbElements) {
					// Ajouter au livre
					biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
					biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;
					// Ajouter \205 la biblio
					biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements] = auteur;
					biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.nbElements] = indiceLivre;
					biblio.bibliothequeAuteur.nbElements++;
					biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.nbElements++;
				} else {
					if (verifAuteurExistantLivre(biblio.bibliothequeLivre.ListeElements[indiceLivre], indiceAuteur)) {
						// Alerter...
						cout << yellow << "Cet auteur a d\202j\205 \202t\202 ajout\202 au livre..." << normal << endl;
						system("pause");
					} else {
						// Ajouter au livre
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;
						biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.nbElements] = indiceLivre;
						biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements].livresAuteur.nbElements++;
					}
				}

				nouveau = requeteNouveau("Voulez-vous ajouter un nouvel auteur au livre (O/N) ? ");
			}

			break;
		case 2:
			// Controler la limite sinon on repasse directement dans le case 1
			if (biblio.bibliothequeAuteur.nbElements == MAX) {
				cout << red << "La limite du nombre d'auteurs a \202t\202 atteinte..." << normal << endl;
				indiceAuteur = selectionAuteur(biblio, "S\202lectionner un auteur\n", LIST_INDENT, false);

				if (indiceAuteur < biblio.bibliothequeAuteur.nbElements) {
					if (!verifAuteurExistantLivre(biblio.bibliothequeLivre.ListeElements[indiceLivre], indiceAuteur)) {
						ajoutAuteurLivre(indiceAuteur, indiceLivre, biblio);
						nouveau = requeteNouveau("Voulez-vous ajouter un nouvel auteur au livre (O/N) ? ");
					} else {
						cout << yellow << "Cet auteur a d\202j\205 \202t\202 rentr\202 pour ce livre..." << normal << endl;
						system("pause");
					}
				} else {
					// retour
				}
			} else {
				cout << cyan << "Cr\202ation de l'auteur: " << normal << endl;
				auteur = saisieAuteur();

				indiceAuteur = verifAuteurExistantBibliotheque(auteur, biblio);
				if (indiceAuteur == biblio.bibliothequeAuteur.nbElements) {
					// Ajouter au livre
					biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
					biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;
					// Ajouter \205 la biblio
					biblio.bibliothequeAuteur.ListeElements[indiceAuteur] = auteur;
					biblio.bibliothequeAuteur.nbElements++;
					// Ajouter le livre \205 l'auteur
					biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements - 1].livresAuteur.nbElements] = indiceLivre;
					biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements++;
				} else {
					if (verifAuteurExistantLivre(biblio.bibliothequeLivre.ListeElements[indiceLivre], indiceAuteur)) {
						// Alerter...
						cout << yellow << "Cet auteur a d\202j\205 \202t\202 ajout\202 au livre..." << normal << endl;
						system("pause");
					} else {
						// Ajouter au livre
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
						biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;
						biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements] = indiceLivre;
						biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements++;
					}
				}

				nouveau = requeteNouveau("Voulez-vous ajouter un nouvel auteur au livre (O/N) ? ");
			}
			break;
		default:
			break;
		}

		cleanLine(cursor);
	} while (nouveau != "N" && nouveau != "n");
}