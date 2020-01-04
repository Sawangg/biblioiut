#include <iostream>

#include "Header.h"

Date saisieDate() {
	int j, m, a;
	Date date;

	do {
		cout << "Jour : ";
		j = ControleEntier();
		while (j < 1 || j > 31) {
			cout << red << "Le jour doit etre compris entre 1 et 31 !" << normal << endl;
			j = ControleEntier();
		}
		date.jour = j;

		cout << "Mois : ";
		m = ControleEntier();
		while (m < 1 || m > 12) {
			cout << red << "Le mois doit etre compris entre 1 et 12 !" << normal << endl;
			m = ControleEntier();
		}
		date.mois = m;

		cout << "Ann\202e : ";
		a = ControleEntier();
		date.annee = a;
		cout << red << verifDate(a, m, j) << normal;
	} while (verifDate(a, m, j) != "");

	return date;
}

Auteur  saisieAuteur() {
	Auteur newAuteur;
	string mort;

	cout << "Quel est le nom de l'auteur ?" << endl;
	getline(cin, newAuteur.nom);
	while (newAuteur.nom == "") {
		cout << red << "Le nom de l'auteur ne peut pas \210tre vide..." << normal << "Quel est le nom de l'auteur ?" << endl;
		getline(cin, newAuteur.nom);
	}

	cout << "Quel est le pr\202nom de l'auteur ?" << endl;
	getline(cin, newAuteur.prenom);
	while (newAuteur.prenom == "") {
		cout << red << "Le pr\202nom de l'auteur ne peut pas \210tre vide..." << normal << "Quel est le pr\202nom de l'auteur ?" << endl;
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

	return newAuteur;
}

void ajoutAuteurs(Bibliotheque& biblio, int indiceLivre) {
	string nouveau = "O";
	COORD cursor;
	int indiceAuteur = 0, typeAjout;

	Auteur auteur;
	Liste<string> options;

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
				indiceAuteur = selectionAuteur(biblio);

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
					// Ajouter à la biblio
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
				indiceAuteur = selectionAuteur(biblio);

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
					// Ajouter à la biblio
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
		default:
			break;
		}

		cleanLine(cursor);
	} while (nouveau != "N" && nouveau != "n");
}


void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque& biblio) {
	// Ajouter l'auteur à la bibliothèque
	biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements] = auteur;
	// On augmente le nombre d'auteurs de la bibliothèque
	biblio.bibliothequeAuteur.nbElements++;
}

void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque& biblio) {
	// Ajouter l'auteur au livre car il n'existe pas
	biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements] = indiceAuteur;
	biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements++;

	// Ajouter le livre à l'auteur
	biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements] = indiceLivre;
	biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements++;

	cout << green << "L'auteur a bien \202t\202 ajout\202 au livre." << normal << endl;
}