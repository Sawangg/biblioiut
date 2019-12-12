#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "controle.h"
#include "color.h"

using namespace std;

int ajoutLivre(Bibliotheque& biblio) {
	Date saisieDate();
	string nom;
	string auteur;
	int pages;

	cout << endl;
	cout << "Entrer le nom du livre :" << endl;
	getline(cin, nom);
	while (nom[0] == 0) {
		cout << red << "Entrer un nom de livre !" << normal << endl;
		getline(cin, nom);
	}
	biblio.tab_livres[biblio.nbrLivres].titre = nom;
	cout << "Entrer le nom de l'auteur :" << endl;
	getline(cin, auteur);
	while (auteur[0] == 0) {
		cout << red << "Entrer un nom d'auteur !" << normal << endl;
		getline(cin, auteur);
	}
	/*biblio.tab_livres[biblio.nbrLivres].auteur = auteur;*/

	cout << "Entrez la date de parution" << endl;
	Date date = saisieDate();
	biblio.tab_livres[biblio.nbrLivres].date.jour = date.jour;
	biblio.tab_livres[biblio.nbrLivres].date.mois = date.mois;
	biblio.tab_livres[biblio.nbrLivres].date.annee = date.annee;

	cout << "Entrer le nombre de pages : ";
	pages = ControleEntier();
	biblio.tab_livres[biblio.nbrLivres].pages = pages;
	cout << "\x1B[32mLe livre a bien ete ajoute !\033[0m" << endl;

	ofstream sauvLivres("sauvLivres.txt", ios::app);
	sauvLivres << nom << endl << auteur << endl << date.jour << endl << date.mois << endl << date.annee << endl << pages << endl << SEP << endl;
	sauvLivres.close();

	return biblio.nbrLivres += 1;
}