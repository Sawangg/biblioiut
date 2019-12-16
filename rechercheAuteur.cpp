#include <string>
#include <iostream>
#include "biblio.h"
#include "color.h"
#include "controle.h"
using namespace std;

void rechercheAuteur(Bibliotheque biblio) {
	int MenuWithColor(Bibliotheque biblio, int menu), choix;
	void afficheLivres(Bibliotheque biblio, int indiceLivres[], int nbrLivres);
	Date saisieDate();

	void rechercheLivreAuteurNom(Bibliotheque biblio, string nom, int position[], int& nbrOccur);
	void rechercheLivreAuteurPrenom(Bibliotheque biblio, string prenom, int position[], int& nbrOccur);
	void rechercheLivreAuteurNomComplet(Bibliotheque biblio, string nom, string prenom, int position[], int& nbrOccur);
	void rechercheLivreAuteurDateN(Bibliotheque biblio, Date date, int position[], int& nbrOccur);
	void rechercheLivreAuteurDateM(Bibliotheque biblio, Date date, int position[], int& nbrOccur);
	void rechercheLivreAuteurCombine(Bibliotheque biblio, int position[], int& nbrOccur);

	string nom, prenom;
	Date date;

	int position[100];
	int nbrOccur = 0;

	do {
		choix = MenuWithColor(biblio, 4);
		switch (choix) {
		case 1:
			cout << "Merci de rentrer le nom de l'auteur: ";
			getline(cin, nom);

			rechercheLivreAuteurNom(biblio, nom, position, nbrOccur);

			// Les afficher
			cout << endl << "Les livres écrits par M/Mme " << nom << ": ";
			afficheLivres(biblio, position, nbrOccur);

			system("pause");
			break;
		case 2:
			cout << "Merci de rentrer le prénom de l'auteur: ";
			getline(cin, prenom);

			rechercheLivreAuteurPrenom(biblio, prenom, position, nbrOccur);

			// Les afficher
			cout << endl << "Les livres écrits par " << prenom << ": ";
			afficheLivres(biblio, position, nbrOccur);

			system("pause");
			break;
		case 3:
			cout << "Merci de rentrer le nom de l'auteur: ";
			getline(cin, nom);
			cout << "Merci de rentrer le prénom de l'auteur: ";
			getline(cin, prenom);

			rechercheLivreAuteurNomComplet(biblio, nom, prenom, position, nbrOccur);

			// Les afficher
			cout << endl << "Les livres écrits par " << nom << " " << prenom << ": ";
			afficheLivres(biblio, position, nbrOccur);

			system("pause");
			break;
		case 4:
			// Saisie de a date
			cout << "Entrez la date de naissance de l'auteur" << endl;
			date = saisieDate();

			// Lancer recherche dans dateN
			rechercheLivreAuteurDateN(biblio, date, position, nbrOccur);

			// Les afficher
			cout << endl << "Les livres écrits par un auteur nait le " << date.jour << "/" << date.mois << "/" << date.annee << ": ";
			afficheLivres(biblio, position, nbrOccur);

			system("pause");
			break;
		case 5:
			cout << "Entrez la date de mort de l'auteur" << endl;
			date = saisieDate();

			// Lancer recherche dans dateM
			rechercheLivreAuteurDateM(biblio, date, position, nbrOccur);

			// Les afficher
			cout << endl << "Les livres écrits par un auteur mort le " << date.jour << "/" << date.mois << "/" << date.annee << ": ";
			afficheLivres(biblio, position, nbrOccur);

			system("pause");
			break;
		case 6:
			cout << red << "EN COURS DE DISCUSSION" << normal << endl;

			system("pause");
			break;
		case 7:
			// On quitte

			break;
		default:
			break;
		}
	} while (choix != 7);

	// Les afficher
}