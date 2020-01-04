#include "Header.h"

using namespace std;

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

void unionListes(Liste<int> livres1, Liste<int> livres2) {
	// A faire
}