#include <iostream>

#include "Utilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de demander un "nouveau" réponse unique, Oui ou Non
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string requeteNouveau(string message) {
	string nouveau;

	cout << message;
	getline(cin, nouveau);
	nouveau = removeAllspace(nouveau);
	while (nouveau != "O" && nouveau != "o" && nouveau != "N" && nouveau != "n") {
		cout << red << "Votre choix est invalide!" << normal << " " << message;
		getline(cin, nouveau);
	}

	return nouveau;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de saisir une date dans un intervalle donné et de la vérifier
//////
//////        ENTREES : date, date
//////        SORTIES : date
//////
///////////////////////////////////////////////////////////////
Date saisieDate(Date dateInf, Date dateSup) {
	int j, m, a;
	Date date;
	string erreur;

	do {
		cout << "Jour : ";
		j = ControleEntier();
		while (j < 1 || j > 31) {
			cout << red << "Le jour doit etre compris entre 1 et 31 !" << normal << endl;
			j = ControleEntier();
		}
		date.jour = j;

		cout << "Mois : ";
		m = ControleEntier();
		while (m < 1 || m > 12) {
			cout << red << "Le mois doit etre compris entre 1 et 12 !" << normal << endl;
			m = ControleEntier();
		}
		date.mois = m;

		cout << "Ann\202e : ";
		a = ControleEntier();
		date.annee = a;
		erreur = verifDate(a, m, j);
		cout << red << erreur << normal;
		if (erreur == "") {
			erreur = verifIntervalleDate(dateInf, date, dateSup);
			cout << red << erreur << normal;
		}

	} while (erreur != "");

	return date;
}