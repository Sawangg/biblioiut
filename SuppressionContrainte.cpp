#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

void SuppressionContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int selection;
	string type, data;
	Date date;

	Liste<string> options;
	Liste<int> indicesContraintes;

	options.ListeElements[options.nbElements] = createTitre("Suppression contrainte");
	creationListeContraintes(options, contraintes);

	selection = menu(options, LIST_NOINDENT, NUMERIC, true) - 1;
	if (selection != options.nbElements - 1) {
		// V\202rifier qu'elle n'est pas utilis\202e...
		utilisationContrainte(contraintes, selection, indicesContraintes);
		if (indicesContraintes.nbElements == 0) {
			// Remplacer par la derni\212re...
			contraintes.ListeElements[selection] = contraintes.ListeElements[contraintes.nbElements];
			contraintes.nbElements--;
			// Modifier les contraintes utilisant la derni\212re...
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
			cout << red << "Vous ne pouvez pas supprimer cette contrainte car elle est utilis\202e dans un groupe de contraintes..." << normal << endl;
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