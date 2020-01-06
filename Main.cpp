#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;
#include <ctype.h>

int main() {
	Bibliotheque biblio;
	Liste<Contraintes> contraintes;

	Liste<string> options;
	void menuOptions(Bibliotheque biblio, int menu, string listOptions[], int& nbOptions);

	system("mode con LINES=40 COLS=160"); // On initialise la taille de la console
	freezConsole(); // On bloque la taille de la console


	if (detectionSauvegarde()) {
		options.ListeElements[0] = string(yellow) + createTextCenter("Une sauvegarde est diponible, souhaitez-vous la charger ?") + string(normal) + "\n";
		options.ListeElements[1] = "OUI";
		options.ListeElements[2] = "NON";
		options.nbElements = 2;
		
		if (menu(options, INLINE, NONE, true) == 1) {
			importSauvegarde(biblio);
		} else {
			biblio.bibliothequeLivre.nbElements = 0;
			biblio.bibliothequeAuteur.nbElements = 0;
		}
	}
	system("cls");

	int choixMenu;
	do {
		options.ListeElements[0] = createTitre("Bibliotheque IUT");
		options.ListeElements[1] = "Afficher l'ensemble des livres de la biblioth\212que";
		options.ListeElements[2] = "Ajouter un nouveau livre";
		options.ListeElements[3] = "Modifier un auteur";
		options.ListeElements[4] = "Rechercher un livre";
		options.ListeElements[5] = "Sauvegarder la biblioth\212que";
		options.ListeElements[6] = "Quitter";
		options.nbElements = 6;
		choixMenu = menu(options, LIST_NOINDENT, NUMERIC, true);

		switch (choixMenu) {
		case 1:
			if (biblio.bibliothequeLivre.nbElements > 0) {
				AfficheLivres(biblio);
			} else {
				cout << red << "Vous devez avoir au minimum 1 livre \205 afficher !" << normal << endl;
				system("pause");
			}
			
			break;
		case 2:
			AjoutLivre(biblio);
			break;
		case 3:
			if (biblio.bibliothequeAuteur.nbElements >= 1) {
				ModificationAuteurs(biblio);
			} else {
				cout << red << "Il n'y a pas d'auteurs enregistr\202s dans la biblioth\212que !" << normal << endl;
				system("pause");
			}
			break;
		case 4:
			if (biblio.bibliothequeLivre.nbElements > 0) {
				Recherche(biblio, contraintes);
			} else {
				cout << red << "Vous devez avoir au minimum 1 livre dans la biblioth\212que pour effectuer des recherches !" << normal << endl;
				system("pause");
			}
			break;
		case 5:
			if (biblio.bibliothequeLivre.nbElements > 0) {
				sauvegardeBibliotheque(biblio);
			} else {
				cout << red << "Vous devez avoir au minimum 1 livre dans la biblioth\212que pour effectuer une sauvegarde !" << normal << endl;
				system("pause");
			}
			break;
		case 6:
			// On quitte le menu et le programme
			break;
		default:
			break;
		}
	} while (choixMenu != 7);

	return 0;
}