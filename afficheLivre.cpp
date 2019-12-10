#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

void afficheLivre(Livre livre) {
    cout << "\n";
    cout << "Titre : " << livre.titre << endl;
    cout << "Auteur : " << livre.auteur << endl;
    cout << "Date : " << livre.date.jour << "/" << livre.date.mois << "/" << livre.date.annee << endl;
    cout << "Pages : " << livre.pages << endl;
}