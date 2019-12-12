#include <iostream>
#include "biblio.h"
#include "controle.h"
#include "color.h"
using namespace std;

Date saisieDate() {
	int j, m, a;
	Date date;

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
			cout << red << "\x1B[31mLe mois doit etre compris entre 1 et 12 !" << normal << endl;
			m = ControleEntier();
		}
		date.mois = m;

		cout << "Annee : ";
		a = ControleEntier();
		date.annee = a;
		cout << red << verifDate(a, m, j) << normal;
	} while (verifDate(a, m, j) != "");

	return date;
}