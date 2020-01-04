#include <iostream>

#include "Header.h"
using namespace std;

void CreationGroupesContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
    int select1, select2, select3;
	Liste<string> options;

	Contraintes newContraintes;
	bool ajoute = false;

	do {
		// premi�re s�lection
		options.ListeElements[options.nbElements] = createTitre("Selection premi�re contrainte");
		creationListeContraintes(options, contraintes);

		select1 = menu(options, LIST_NOINDENT, NUMERIC, true);
		if (select1 != options.nbElements) {
			newContraintes.positionContrainte1 = select1 - 1;

			do {
				// s�lection de l'op�rateur
				options.ListeElements[0] = createTitre("Choix de l'op�rateur");
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
						// deuxi�me s�lection
						options.ListeElements[options.nbElements] = createTitre("Selection seconde contrainte");
						creationListeContraintes(options, contraintes);

						select3 = menu(options, LIST_NOINDENT, NUMERIC, true);
						if (select3 != options.nbElements) {
							newContraintes.positionContrainte2 = select3 - 1;

							if (newContraintes.positionContrainte1 == newContraintes.positionContrainte2) {
								cout << red << "Les 2 contraintes ajout�es sont identiques ! Merci de s�lectionner 2 contraintes diff�rentes..." << normal << endl;
								system("pause");
							} else {
								contraintes.ListeElements[contraintes.nbElements] = newContraintes;
								contraintes.nbElements++;

								cout << green << "Le block de contraintes a bien �t� ajout�..." << normal << endl;
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