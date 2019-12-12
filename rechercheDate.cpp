#include <iostream>
#include "controle.h"
#include "biblio.h"
using namespace std;

void rechercheDate(Bibliotheque biblio) {
	void rechercheLivreDate(Bibliotheque biblio, Date date, int position[], int& nbrOccur);
	Date saisieDate();

	Date date;
	int position[100];
	int nbrOccur;

	cout << "Entrez la date du livre à rechercher" << endl;
	date = saisieDate();

	rechercheLivreDate(biblio, date, position, nbrOccur);

	// Les afficher
}