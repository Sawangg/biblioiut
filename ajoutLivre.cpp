#include <iostream>
#include <string>
#include <fstream>

#include <sstream>

#include "biblio.h"
#include "controle.h"
#include "color.h"

using namespace std;

int ajoutLivre(Bibliotheque& biblio) {
	Date saisieDate();
	int indiceAuteur;
	void ajoutAuteur(Bibliotheque& biblio, Livre& livre, int indiceLivre);
	int MenuWithColor(Bibliotheque biblio, int menu);
	void cleanLine(COORD menu);

	COORD menu;
	string nom;
	string auteur;
	int pages;

	cout << endl;
	//Saisie nom du livre
	cout << "Entrer le nom du livre :" << endl;
	getline(cin, nom);
	while (nom[0] == 0) {
		cout << red << "Entrer un nom de livre !" << normal << endl;
		getline(cin, nom);
	}
	biblio.tab_livres[biblio.nbrLivres].titre = nom;

	//Menu pour choix parmi les auteurs ou en cr�er un autre
	string valide;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	menu.X = coninfo.dwCursorPosition.X;
	menu.Y = coninfo.dwCursorPosition.Y;
	do {
		int choix1 = MenuWithColor(biblio, 5);
		cleanLine(menu);
		switch (choix1) {
		case 1:
			// Affichage des auteurs existant (s'assurer qu'il y en a)
			if (biblio.nbrAuteurs) {
				do {
					indiceAuteur = MenuWithColor(biblio, 6);

					switch (indiceAuteur) {
					default:
						if (indiceAuteur <= biblio.nbrAuteurs) {
							biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[biblio.tab_livres[biblio.nbrLivres].nbrAuteurs] = indiceAuteur;
							biblio.tab_livres[biblio.nbrLivres].nbrAuteurs++;
						}
						break;
					}
				} while (indiceAuteur != biblio.nbrAuteurs + 1);
			} else {
				// Bloquer -> CASE 2
				cout << red << "Il n'y a pas d'auteurs enregistr�s..." << normal << endl;
				cout << "Cr�ation de l'auteur: " << endl;
				ajoutAuteur(biblio, biblio.tab_livres[biblio.nbrLivres], biblio.nbrLivres);
			}

			break;
		case 2:
			// Controler la limite sinon on repasse directement dans le case 1
			if (biblio.nbrAuteurs == MAX_AUTEURS) {
				// Bloquer -> CASE 1
				cout << red << "La limite du nombre d'auteurs a �t� atteinte..." << normal << endl;
				do {
					indiceAuteur = MenuWithColor(biblio, 6);

					switch (indiceAuteur) {
					default:
						if (indiceAuteur <= biblio.nbrAuteurs) {
							biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[biblio.tab_livres[biblio.nbrLivres].nbrAuteurs] = indiceAuteur;
							biblio.tab_livres[biblio.nbrLivres].nbrAuteurs++;
						}
						break;
					}
				} while (indiceAuteur != biblio.nbrAuteurs + 1);
			} else {
				cout << "Cr�ation de l'auteur: " << endl;
				ajoutAuteur(biblio, biblio.tab_livres[biblio.nbrLivres], biblio.nbrLivres);
			}
			break;
		default:
			break;
		}

		cout << "Voulez-vous ajouter un nouvel auteur au livre (0/N) ? ";
		getline(cin, valide);
		while (valide != "O" && valide != "o" && valide != "N" && valide != "n") {
			cout << red << "Votre choix est invalide!" << normal << " Voulez-vous ajouter un nouvel auteur au livre (O/N) ? ";
			getline(cin, valide);
		}

		cleanLine(menu);
	} while (valide != "N" && valide != "n");
	cout << "Vous avez entr� " << biblio.tab_livres[biblio.nbrLivres].nbrAuteurs << " auteurs: " << endl;
	// Afficher les deux auteurs
	for (int i = 0; i < biblio.tab_livres[biblio.nbrLivres].nbrAuteurs; i++) {
		cout << "\t" << i + 1 << ". M/Mme " << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].nom;
		cout << " " << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].prenom << " nait le " << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.jour;
		cout << "/" << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.mois;
		cout << "/" << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.annee;
		if (biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateM.jour != 0) {
			cout << " et mort le ";
			cout << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.jour;
			cout << "/" << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.mois;
			cout << "/" << biblio.tab_auteurs[biblio.tab_livres[biblio.nbrLivres].ListeAuteurs[i]].dateN.annee;
		}
		cout << "." << endl;
	}

	cout << "Entrez la date de parution" << endl;
	Date date = saisieDate();
	biblio.tab_livres[biblio.nbrLivres].date.jour = date.jour;
	biblio.tab_livres[biblio.nbrLivres].date.mois = date.mois;
	biblio.tab_livres[biblio.nbrLivres].date.annee = date.annee;

	cout << "Entrer le nombre de pages : ";
	pages = ControleEntier();
	biblio.tab_livres[biblio.nbrLivres].pages = pages;
	cout << "\x1B[32mLe livre a bien ete ajoute !\033[0m" << endl;

	// Conversion int en string pour supprimer les espaces
	stringstream ss;
	ss << date.annee;
	string str = ss.str();
	string annee;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '�') {
			annee += str[i];
		}
	}

	ofstream sauvLivres("sauvLivres.txt", ios::app);
	sauvLivres << nom << endl << auteur << endl << date.jour << endl << date.mois << endl << annee << endl << pages << endl << SEP << endl;
	sauvLivres.close();

	return biblio.nbrLivres += 1;
}

void cleanLine(COORD menu) {
	// R�cupr�rer position curseur
	COORD cursorNow;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	cursorNow.X = coninfo.dwCursorPosition.X;
	cursorNow.Y = coninfo.dwCursorPosition.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu);
	for (int i = 0; i < cursorNow.Y - menu.Y; i++) {
		cout << "                                                                        " << endl;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu);
}