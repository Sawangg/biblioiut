#include <iostream>
#include "controle.h"
#include "biblio.h"
using namespace std;

void rechercheDate(Bibliotheque biblio) {
	void rechercheLivreDate(Bibliotheque biblio, Date date, int position[], int& nbrOccur);
	void afficheLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres);

	Date saisieDate();

	Date date;
	int position[100];
	int nbrOccur;

	cout << "Entrez la date du livre à rechercher" << endl;
	date = saisieDate();

	rechercheLivreDate(biblio, date, position, nbrOccur);

	// Les afficher
	cout << endl << "Les livres parus le " << date.jour << "/" << date.mois << "/" << date.annee << ": ";
	afficheLivres(biblio, position, nbrOccur);

	system("pause");
}