#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "controle.h"
#include "color.h"

using namespace std;

int ajoutLivre(Bibliotheque& biblio) {
	string verifDate(int a, int m, int j);
	string nom;
	string auteur;
	int pages;
	int j = 0;
	int m = 0;
	int a = 0;

	cout << endl;
	cout << "Entrer le nom du livre :" << endl;
	getline(cin, nom);
	while (nom[0] == 0) {
		cout << red << "Entrer un nom de livre !" << normal << endl;
		getline(cin, nom);
	}
	biblio.tab_livres[biblio.nbrElem].titre = nom;
	cout << "Entrer le nom de l'auteur :" << endl;
	getline(cin, auteur);
	while (auteur[0] == 0) {
		cout << red << "Entrer un nom d'auteur !" << normal << endl;
		getline(cin, auteur);
	}
	biblio.tab_livres[biblio.nbrElem].auteur = auteur;
	do {
		cout << "Entrer la date de parution" << endl;
		cout << "Jour : ";
		j = ControleEntier();
		while (j < 1 || j > 31) {
			cout << "\x1B[31mLe jour doit etre compris entre 1 et 31 !\033[0m";
			j = ControleEntier();
		}
		biblio.tab_livres[biblio.nbrElem].date.jour = j;
		cout << "Mois : ";
		m = ControleEntier();
		while (m < 1 || m > 12) {
			cout << "\x1B[31mLe mois doit etre compris entre 1 et 12 !\033[0m";
			m = ControleEntier();
		}
		biblio.tab_livres[biblio.nbrElem].date.mois = m;
		cout << "Annee : ";
		a = ControleEntier();
		biblio.tab_livres[biblio.nbrElem].date.annee = a;
		cout << verifDate(a, m, j);
	} while (verifDate(a, m, j) != "");

	cout << "Entrer le nombre de pages : ";
	pages = ControleEntier();
	biblio.tab_livres[biblio.nbrElem].pages = pages;
	cout << "\x1B[32mLe livre a bien ete ajoute !\033[0m" << endl;

	ofstream file;
	file.open("sauvegarde.txt");
	file << "Nom : " << nom;

	/*string STRING;
	ifstream infile;
	infile.open("sauvegarde.txt");
	while (!infile.eof()) {
		getline(infile, STRING);
		cout << STRING;
	}
	infile.close();
	system("pause");*/

	return biblio.nbrElem += 1;
}