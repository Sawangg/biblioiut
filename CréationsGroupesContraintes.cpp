#include <iostream>

#include "Header.h"
using namespace std;

void CreationGroupesContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
    int select1, select2, select3;
	Liste<string> options;

	Contraintes newContraintes;
	bool ajoute = false;

	do {
		// première sélection
		options.ListeElements[options.nbElements] = createTitre("S\202lection de la premi\212re contrainte");
		creationListeContraintes(options, contraintes);

		select1 = menu(options, LIST_NOINDENT, NUMERIC, true);
		if (select1 != options.nbElements) {
			newContraintes.positionContrainte1 = select1 - 1;

			do {
				// sélection de l'opérateur
				options.ListeElements[0] = createTitre("Choix de l'op\202rateur");
				options.ListeElements[1] = "OU";
				options.ListeElements[2] = "ET";
				options.ListeElements[3] = "Retour";
				options.nbElements = 3;

				select2 = menu(options, LIST_NOINDENT, NUMERIC, true);
				if (select2 != 3) {
					switch (select2) {
					case 1:
						newContraintes.operateur = "OU";
						break;
					case 2:
						newContraintes.operateur = "ET";
						break;
					}

					do {
						// deuxième sélection
						options.ListeElements[options.nbElements] = createTitre("S\202lection de la seconde contrainte");
						creationListeContraintes(options, contraintes);

						select3 = menu(options, LIST_NOINDENT, NUMERIC, true);
						if (select3 != options.nbElements) {
							newContraintes.positionContrainte2 = select3 - 1;

							if (newContraintes.positionContrainte1 == newContraintes.positionContrainte2) {
								cout << red << "Les 2 contraintes ajout\202es sont identiques ! Merci de s\202lectionner 2 contraintes diff\202rentes !" << normal << endl;
								system("pause");
							} else {
								contraintes.ListeElements[contraintes.nbElements] = newContraintes;
								contraintes.nbElements++;

								cout << green << "Le block de contraintes a bien \202t\202 ajout\202 !" << normal << endl;
								system("pause");

								ajoute = true;
							}
						}
					} while (select3 != contraintes.nbElements && !ajoute);
				} else {

				}
			} while (select2 != 3 && !ajoute);
		} else {

		}
	} while (select1 != contraintes.nbElements && !ajoute);
}