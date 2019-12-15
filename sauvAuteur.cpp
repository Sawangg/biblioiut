#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "biblio.h"
#include "controle.h"

fstream& GotoLine(fstream& file, unsigned int num) {
    file.seekg(ios::beg);
    for (unsigned int i = 0; i < num - 1; ++i) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return file;
}

void sauvNewAuteur(string liste, Auteur newAuteur, Bibliotheque& biblio) {
    ofstream sauvAuteurs("sauvAuteurs.txt", ios::app);
    string anneeN = convertInt2String(newAuteur.dateN.annee);
    string anneeM = convertInt2String(newAuteur.dateM.annee);

    sauvAuteurs << newAuteur.nom << endl << newAuteur.prenom << endl << newAuteur.dateN.jour << endl << newAuteur.dateN.mois << endl << anneeN << endl << newAuteur.dateM.jour << endl << newAuteur.dateM.mois << endl << anneeM << endl << newAuteur.nbrLivresAuteur << endl << liste << endl << SEP << endl;
    sauvAuteurs.close();
}

void addLivreAuteur(string liste, Auteur newAuteur, Bibliotheque& biblio) {
    ifstream sauvAuteursLire("sauvAuteurs.txt");
    string ligne;
    while (getline(sauvAuteursLire, ligne)) { // IMPOSSIBLE D'ECRIRE A LA BONNE LIGNE ICI
        if (ligne == newAuteur.nom) {
            fstream sauvAuteursEcrire("sauvAuteurs.txt", ios::out | ios::in);
            GotoLine(sauvAuteursEcrire, 9);
            cout << newAuteur.nbrLivresAuteur;
            system("pause");
            sauvAuteursEcrire << newAuteur.nbrLivresAuteur;
            GotoLine(sauvAuteursEcrire, 10);
            cout << liste;
            system("pause");
            sauvAuteursEcrire << liste;
        }
    }
    sauvAuteursLire.close();
}

bool auteurExistantSauvegarde(string nom) {
    ifstream sauvAuteursExist("sauvAuteurs.txt");
    bool exist = false;
    string ligne;
    while (getline(sauvAuteursExist, ligne)) {
        if (ligne == nom) {
            exist = true;
            break;
        }
    }
    return exist;
}