#include <iostream>

#include "Header.h"
using namespace std;

void auteursLivre(Bibliotheque biblio, int indiceLivre, Liste<int>& indicesAuteurs) {
	indicesAuteurs.nbElements = 0;

	for (int i = 0; i < biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements; i++) {
		indicesAuteurs.ListeElements[indicesAuteurs.nbElements] = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[i];
		indicesAuteurs.nbElements++;
	}
}

void suppressionLivre(Bibliotheque& biblio, int indiceLivre) {
	Liste<int> indicesAuteurs;

	auteursLivre(biblio, indiceLivre, indicesAuteurs);
	if (indicesAuteurs.nbElements > 0) {
		// Auteurs du livre
		for (int i = 0; i < indicesAuteurs.nbElements; i++) {
			// Supprimer le livre chez les auteurs
			bool livre = false;
			int z = 0;
			while (z < biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements && !livre) {
				if (biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[z] == indiceLivre) {
					biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[z] = biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements - 1];
					biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements--;
					livre = true;
				}
				z++;
			}

			// Vérifier
			if (biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements == 0) {
				// Supprimer auteurs
				suppressionAuteur(biblio, i);
			}
		}

		// Supprimer le livre
		biblio.bibliothequeLivre.ListeElements[indiceLivre] = biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements - 1];
		biblio.bibliothequeLivre.nbElements--;
		auteursLivre(biblio, biblio.bibliothequeLivre.nbElements - 1, indicesAuteurs);
		for (int i = 0; i < indicesAuteurs.nbElements; i++) {
			// Modifier indice du livre des auteurs qui ont écrit le dernier livre
			bool livre = false;
			int z = 0;
			while (z < biblio.bibliothequeAuteur.ListeElements[indicesAuteurs.ListeElements[i]].livresAuteur.nbElements && !livre) {
				if (biblio.bibliothequeAuteur.ListeElements[indicesAuteurs.ListeElements[i]].livresAuteur.ListeElements[z] == biblio.bibliothequeLivre.nbElements - 1) {
					biblio.bibliothequeAuteur.ListeElements[indicesAuteurs.ListeElements[i]].livresAuteur.ListeElements[z] = indiceLivre;
					livre = true;
				}
				z++;
			}
		}
	} else {
		cout << red << "Erreur inconnue..." << normal << endl;
		system("pause");
	}
}

void livresAuteur(Bibliotheque biblio, int indiceAuteur, Liste<int>& indicesLivres) {
	indicesLivres.nbElements = 0;

	for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
		bool aEcrit = false;
		int z = 0;

		while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !aEcrit) {
			if (biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z] == indiceAuteur) {
				indicesLivres.ListeElements[indicesLivres.nbElements] = i;
				indicesLivres.nbElements++;
				aEcrit = true;
			}
			z++;
		}
	}
}

void suppressionAuteur(Bibliotheque& biblio, int indiceAuteur) {
	Liste<int> indicesLivres;

	biblio.bibliothequeAuteur.ListeElements[indiceAuteur] = biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements - 1];
	biblio.bibliothequeAuteur.nbElements--;
	livresAuteur(biblio, biblio.bibliothequeAuteur.nbElements, indicesLivres);
	for (int i = 0; i < indicesLivres.nbElements; i++) {
		// Modifier indice du livre des auteurs qui ont écrit le dernier livre
		bool auteur = false;
		int z = 0;
		while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !auteur) {
			if (biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z] == biblio.bibliothequeLivre.nbElements) {
				biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z] = indiceAuteur;
				auteur = true;
			}
			z++;
		}
	}
}