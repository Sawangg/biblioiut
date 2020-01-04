#include <iostream>
#include <sstream>
#include <string>

#include "Header.h"

using namespace std;

string convertDate2String(Date date) {
    string dateS;

    dateS = convertInt2String(date.jour) + "/" + convertInt2String(date.mois) + "/" + convertInt2String(date.annee);

    return dateS;
}
Date convertString2Date(string dateS) {
	Date date;
	string data = "";

	int separator = 0;
	for (int i = 0; i < dateS.length(); i++) {
		if (dateS[i] == '/') {
			switch (separator) {
			case 0:
				date.jour = convertString2Int(data);
				break;
			case 1:
				date.mois = convertString2Int(data);
				break;
			case 2:
				date.annee = convertString2Int(data);
				break;
			default:
				cout << red << "Erreur inconnue" << normal << endl;
				system("pause");
				break;
			}
			separator++;
			data = "";
		} else {
			data += dateS[i];
		}
	}
	return date;
}

string convertInt2String(int entier) {
	stringstream ss;
	ss << entier;
	string str = ss.str();
	string stringFin;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			stringFin += str[i];
		}
	}
	return stringFin;
}
int convertString2Int(string entierS) {
	int entier;

	string::size_type st;
	entier = stoi(entierS, &st);

	return entier;
}

string convertString2Upper(string data) {
	for (int i = 0; i < data.length(); i++) {
		if (data[i] >= 'a' && data[i] <= 'z') {
			data[i] = data[i] - 'a' + 'A';
		}
	}

	return data;
}
string convertString2Lower(string data) {
	for (int i = 0; i < data.length(); i++) {
		if (data[i] >= 'A' && data[i] <= 'Z') {
			data[i] = data[i] - 'A' + 'a';
		}
	}

	return data;
}