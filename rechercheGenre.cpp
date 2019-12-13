#include <string>
#include <iostream>
#include "biblio.h"
#include "color.h"
using namespace std;

void rechercheGenre(Bibliotheque biblio) {
	void rechercheLivreGenreMultiple(Bibliotheque biblio, string genre[], int nbrGenres, int position[], int& nbrOccur);

	string genre[20];
	int nbrGenres = 0;
	string nouveau;

	int position[100];
	int nbrOccur = 0;

	do {
		cout << "Merci de rentrer un genre: ";
		getline(cin, genre[nbrGenres]);
		// Verif
		nbrGenres++;

		cout << "Voulez-vous chercher des livres correspondant à un genre supplémentaire (O/N) ? ";
		getline(cin, nouveau);
		while (nouveau != "o" && nouveau != "O" && nouveau != "N" && nouveau != "n") {
			cout << red << "Votre choix est invalide..." << normal << endl;
			cout << "Voulez-vous chercher des livres correspondant à un genre supplémentaire (O/N) ? ";
			getline(cin, nouveau);
		}
	} while (nouveau == "o" || nouveau == "O");

	rechercheLivreGenreMultiple(biblio, genre, nbrGenres, position, nbrOccur);


	// Les afficheer trié par genre
}