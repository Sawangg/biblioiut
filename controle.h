#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include <string>
#include <sstream>
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

#endif