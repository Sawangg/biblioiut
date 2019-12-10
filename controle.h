#ifndef CONTROLE_H
#define CONTROLE_H

#include <iostream>
#include <string>
using namespace std;

static int ControleEntier() {
    string theInput = "";
    int inputAsInt;

	while (theInput == "") {
		getline(cin, theInput);
	}

    while (cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789") != string::npos) {

        cout << "\x1B[31mMerci de rentrer un entier !\033[0m" << endl;

        if (theInput.find_first_not_of("0123456789") == string::npos) {
            cin.clear();
            cin.ignore(256, '\n');
        }

		getline(cin, theInput);
		while (theInput == "") {
			getline(cin, theInput);
		}
    }

    string::size_type st;
    inputAsInt = stoi(theInput, &st);
    return inputAsInt;
}

#endif