#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de supprimer un auteur de la bibliothèque
///////
///////     ENTREES: bibliotheque, entier
///////     
///////     Il faut au préalable vérifier que parmi les livres que l'auteur a écrit il n'y en a aucun où il est le seul écrivain !
///////
/////////////////////////////////////////////////////////////////////////////
void suppressionAuteurBibliotheque(Bibliotheque& biblio, int indiceAuteur) {
	int nbLivres = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements;
	// Supprimer l'auteur dans les livres qu'il a écrit
	for (int i = 0; i < nbLivres; i++) {
		int indiceLivre = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[0];
		suppressionAuteurLivre(biblio, indiceAuteur, indiceLivre);
	}

	// Supprimer l'auteur dans la bibliothèque
	biblio.bibliothequeAuteur.ListeElements[indiceAuteur] = biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeAuteur.nbElements - 1];
	biblio.bibliothequeAuteur.nbElements--;
	// Modifier l'indice de l'auteur dans ses livres
	modifierIndiceAuteurLivre(biblio, biblio.bibliothequeAuteur.nbElements, indiceAuteur);
}
/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de modifier l'indice d'un auteur parmi la liste des auteurs d'un livre
///////
///////     ENTREES: bibliotheque, entier, entier
///////     
/////////////////////////////////////////////////////////////////////////////
void modifierIndiceAuteurLivre(Bibliotheque& biblio, int ancienIndice, int nouvelIndice) {
	for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
		int compteur = 0;
		bool trouve = false;

		while (compteur < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !trouve) {
			if (biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[compteur] == ancienIndice) {
				biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[compteur] = nouvelIndice;

				trouve = true;
			} else {
				compteur++;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de supprimer un auteur parmi la liste des auteurs du livre
///////
///////     ENTREES: bibliotheque, entier, entier
///////     
/////////////////////////////////////////////////////////////////////////////
void suppressionAuteurLivre(Bibliotheque& biblio, int indiceAuteur, int indiceLivre) {
	int compteur = 0;
	bool trouve = false;

	while (compteur < biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements && !trouve) {
		if (biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[compteur] == indiceAuteur) {
			trouve = true;
		} else {
			compteur++;
		}
	}

	if (trouve) {
		biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[compteur] = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements - 1];
		biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements--;

		suppressionLivreAuteur(biblio, indiceLivre, indiceAuteur);
	}
}

/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de supprimer un livre de la bibliothèque
///////
///////     ENTREES: bibliotheque, entier
/////// 
/////////////////////////////////////////////////////////////////////////////
void suppressionLivreBibliotheque(Bibliotheque& biblio, int indiceLivre) {
	// Supprimer le livre chez ses auteurs
	int nbAuteurs = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.nbElements;

	for (int i = 0; i < nbAuteurs; i++) {
		int indiceAuteur = biblio.bibliothequeLivre.ListeElements[indiceLivre].auteursLivre.ListeElements[0];
		// Si l'auteur n'a plus de livres on le supprime
		if (biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements == 1) {
			suppressionAuteurBibliotheque(biblio, indiceAuteur);
		} else {
			suppressionLivreAuteur(biblio, indiceLivre, indiceAuteur);
		}
	}

	// Supprimer le livre de la bibliothèque
	biblio.bibliothequeLivre.ListeElements[indiceLivre] = biblio.bibliothequeLivre.ListeElements[biblio.bibliothequeLivre.nbElements - 1];
	biblio.bibliothequeLivre.nbElements--;
	// Modifier l'indice du livre chez ses auteurs
	modifierIndiceLivreAuteur(biblio, biblio.bibliothequeLivre.nbElements, indiceLivre);
}
/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de modifier l'indice d'un livre chez ses auteurs
///////
///////     ENTREES: bibliotheque, entier, entier
/////// 
/////////////////////////////////////////////////////////////////////////////
void modifierIndiceLivreAuteur(Bibliotheque& biblio, int ancienIndice, int nouvelIndice) {
	for (int i = 0; i < biblio.bibliothequeAuteur.nbElements; i++) {
		int compteur = 0;
		bool trouve = false;

		while (compteur < biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements && !trouve) {
			if (biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[compteur] == ancienIndice) {
				trouve = true;
			} else {
				compteur++;
			}
		}

		if (trouve) {
			biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[compteur] = nouvelIndice;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
///////
///////     Procédure qui permet de supprimer un livre dans la liste des livres d'un auteur
///////
///////     ENTREES: bibliotheque, entier
/////// 
/////////////////////////////////////////////////////////////////////////////
void suppressionLivreAuteur(Bibliotheque& biblio, int indiceLivre, int indiceAuteur) {
	int compteur = 0;
	bool trouve = false;

	while (compteur < biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements && !trouve) {
		if (biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[compteur] == indiceLivre) {
			trouve = true;
		} else {
			compteur++;
		}
	}
	if (trouve) {
		biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[compteur] = biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.ListeElements[biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements - 1];
		biblio.bibliothequeAuteur.ListeElements[indiceAuteur].livresAuteur.nbElements--;

		suppressionAuteurLivre(biblio, indiceAuteur, indiceLivre);
	}
}