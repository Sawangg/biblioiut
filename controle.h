#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include <string>
#include <sstream>
#include "biblio.h"
using namespace std;

static int ControleEntier() {
    string theInput = "";
    int inputAsInt;
    bool successful = false;

	while (theInput == "") {
		getline(cin, theInput);
	}
    stringstream ss(theInput);
    ss >> inputAsInt;
    successful = !ss.fail();

    while (cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789") != string::npos || !successful) {
        cout << "\x1B[31mMerci de rentrer un entier positif compris entre 0 et 2147483647 (inclus) !\033[0m" << endl;

        if (theInput.find_first_not_of("0123456789") == string::npos) {
            cin.clear();
        }

		getline(cin, theInput);
		while (theInput == "") {
			getline(cin, theInput);
		}
        stringstream ss(theInput);
        ss >> inputAsInt;
        successful = !ss.fail();
    }

    string::size_type st;
    inputAsInt = stoi(theInput, &st);
    return inputAsInt;
}

static bool verifGenre(string genre) {
    int i = 0;
    bool trouve = false;

    while (i < 19 && !trouve) {
        if (genre == ListeGenre[i]) {
            trouve = true;
        }
        i++;
    }

    return trouve;
}

static string verifDate(int a, int m, int j) {
	string erreur;

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (j == 31) {
			erreur = "Le mois que vous avez choisi ne contient pas 31 jours ! La date est invalide\n";
		} else {
			erreur = "";
		}
	} else {
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			erreur = "";
		} else {
			if ((j == 29) && (a % 4 == 0) && (a / 100 != 0)) {
				erreur = "";
			} else {
				if (j < 29) {
					erreur = "";
				} else {
					erreur = "Le mois que vous avez choisi ne contient pas 29 jours car l'annee n'est pas bissextile\n";
				}
			}
		}
	}
	return erreur;
}

#endif