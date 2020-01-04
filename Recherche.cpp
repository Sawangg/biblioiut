#include <iostream>

#include "Header.h"
using namespace std;

void Recherche(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int choix;
	int select1;
	Liste<int> livres;

	Liste<string> options;

	do {
		options.ListeElements[0] = createTitre("Recherche");
		options.ListeElements[1] = "Cr\202er des contraintes";
		options.ListeElements[2] = "Cr\202er des groupes de contraintes";
		options.ListeElements[3] = "Modifier une contrainte/groupe de contraintes";
		options.ListeElements[4] = "Supprimer une contrainte/groupe de contraintes";
		options.ListeElements[5] = "Effectuer la recherche";
		options.ListeElements[6] = "Retour";
		options.nbElements = 6;
		choix = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choix) {
		case 1:
			if (contraintes.nbElements != MAX) {
				CreationContraintes(biblio, contraintes);
			} else {
				cout << red << "Vous avez atteint la limite du nombre de contraintes !" << normal << endl;
				system("pause");
			}
			break;
		case 2:
			if (contraintes.nbElements >= 2) {
				if (contraintes.nbElements != MAX) {
					CreationGroupesContraintes(biblio, contraintes);
				} else {
					cout << red << "Vous avez atteint la limite du nombre de contraintes !" << normal << endl;
					system("pause");
				}
			} else {
				cout << red << "Vous devez avoir cr\202\202, au minimum, 2 contraintes pour cr\202er un groupe de contraintes !" << normal << endl;
				system("pause");
			}
			break;
		case 3:
			if (contraintes.nbElements >= 1) {
				modificationContrainte(biblio, contraintes);
			} else {
				cout << red << "Vous devez avoir cr\202\202, au minimum, 1 contrainte pour pouvoir la modifier !" << normal << endl;
				system("pause");
			}
			break;
		case 4:
			if (contraintes.nbElements >= 1) {
				suppressionContrainte(biblio, contraintes);
			} else {
				cout << red << "Vous devez avoir cr\202\202, au minimum, 1 contrainte pour pouvoir en supprimer une !" << normal << endl;
				system("pause");
			}
			break;
		case 5:
			if (contraintes.nbElements >= 1) {
				options.ListeElements[options.nbElements] = createTitre("Selection contrainte de recherche");
				creationListeContraintes(options, contraintes);

				select1 = menu(options, LIST_NOINDENT, NUMERIC, true);
				if (select1 != options.nbElements) {
					rechercheLivres(biblio, contraintes.ListeElements, contraintes.ListeElements[select1 - 1], livres);

					if (livres.nbElements > 0) {
						afficheLivres(biblio, livres);
						livres.nbElements = 0;
					} else {
						cout << red << "Aucun livre ne correspond \205 votre recherche !" << normal << endl;
						system("pause");
					}
				}
			} else {
				cout << red << "Vous devez avoir cr\202\202, au minimum, 1 contrainte pour pouvoir effectuer une recherche !" << normal << endl;
				system("pause");
			}
			break;
		case 6:
			// Quitter la recherche
			break;
		default:
			break;
		}
	} while (choix != 6);
}