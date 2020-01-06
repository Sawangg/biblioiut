#include "BiblioUtilitaire.h"

using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de faire l'intersection entre deux listes
//////
//////        ENTREES : Liste d'entiers, Liste d'entiers
//////        SORTIES : Liste d'entiers
//////
///////////////////////////////////////////////////////////////
void intersectListes(Liste<int>& livres1, Liste<int> livres2) {
	Liste<int> livres;
	bool intersect = false;

	for (int i = 0; i < livres1.nbElements; i++) {
		int z = 0;
		while (z < livres2.nbElements && !intersect) {
			if (livres1.ListeElements[i] == livres2.ListeElements[z]) {
				livres.ListeElements[livres.nbElements] = livres2.ListeElements[z];
				livres.nbElements++;
				intersect = true;
			}
			z++;
		}
	}

	for (int i = 0; i < livres.nbElements; i++) {
		livres1.ListeElements[i] = livres.ListeElements[i];
	}
	livres1.nbElements = livres.nbElements;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de faire l'union entre deux listes
//////
//////        ENTREES : Liste d'entiers, Liste d'entiers
//////        SORTIES : Liste d'entiers
//////
///////////////////////////////////////////////////////////////
void unionListes(Liste<int>& livres1, Liste<int> livres2) {
	// A faire
	for (int i = 0; i < livres2.nbElements; i++) {
		int compteur = 0;
		bool trouve = false;
		while (compteur < livres1.nbElements && !trouve) {
			if (livres2.ListeElements[i] == livres1.ListeElements[compteur]) {
				trouve = true;
			} else {
				compteur++;
			}
		}

		if (!trouve) {
			livres1.ListeElements[livres1.nbElements] = livres2.ListeElements[i];
			livres1.nbElements++;
		}
	}
}