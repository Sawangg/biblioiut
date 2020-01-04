#include <iostream>
#include <sstream>
#include <string>

#include "Header.h"

using namespace std;

int ControleEntier() {
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

string verifDate(int a, int m, int j) {
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
                    erreur = "Le mois que vous avez choisi ne contient pas 29 jours car l'ann\202e n'est pas bissextile\n";
                }
            }
        }
    }
    return erreur;
}

int verifAuteurExistantBibliotheque(Auteur auteur, Bibliotheque biblio) {
    bool existant = false;
    int i = 0;

    while (i < biblio.bibliothequeAuteur.nbElements && !existant) {
        if (auteur.nom == biblio.bibliothequeAuteur.ListeElements[i].nom && auteur.prenom == biblio.bibliothequeAuteur.ListeElements[i].prenom && (auteur.dateN.jour == biblio.bibliothequeAuteur.ListeElements[i].dateN.jour && auteur.dateN.mois == biblio.bibliothequeAuteur.ListeElements[i].dateN.mois && auteur.dateN.annee == biblio.bibliothequeAuteur.ListeElements[i].dateN.annee) && (auteur.dateM.jour == biblio.bibliothequeAuteur.ListeElements[i].dateM.jour && auteur.dateM.mois == biblio.bibliothequeAuteur.ListeElements[i].dateM.mois && auteur.dateM.annee == biblio.bibliothequeAuteur.ListeElements[i].dateM.annee)) {
            existant = true;
        }
        i++;
    }

    if (existant) {
        return i - 1;
    } else {
        return i;
    }
}
bool verifAuteurExistantLivre(Livre livre, int indiceAuteur) {
    int i = 0;
    bool trouve = false;
    while (i < livre.auteursLivre.nbElements && !trouve) {
        if (livre.auteursLivre.ListeElements[i] == indiceAuteur) {
            // L'auteur existe déjà
            trouve = true;
        }
        i++;
    }

    return trouve;
}

bool verifLivreExistantBibliotheque(Liste<Livre> livres, Livre livre) {
    int i = 0;
    bool trouve = false;
    while (i < livres.nbElements && !trouve) {
        if (livres.ListeElements[i].titre == livre.titre && livres.ListeElements[i].pages == livre.pages && livres.ListeElements[i].genre == livre.genre && livres.ListeElements[i].date.jour == livre.date.jour  && livres.ListeElements[i].date.mois == livre.date.mois && livres.ListeElements[i].date.annee == livre.date.annee && livres.ListeElements[i].auteursLivre.ListeElements == livre.auteursLivre.ListeElements) {
            // Le livre existe déjà
            trouve = true;
        }
        i++;
    }

    return trouve;
}

bool verifContrainteExistanteBibliotheque(Contraintes contrainte, Liste<Contraintes> contraintes) {
    int i = 0;
    bool trouve = false;
    while (i < contraintes.nbElements && !trouve) {
        if (contraintes.ListeElements[i].positionContrainte1 == contraintes.ListeElements[i].positionContrainte2) {
            if (contraintes.ListeElements[i].contrainte1 == contrainte.contrainte1 && contraintes.ListeElements[i].contrainte2 == contrainte.contrainte2 && contraintes.ListeElements[i].operateur == contrainte.operateur) {
                // La contrainte existe déjà
                trouve = true;
            }
        } else {
            if (contraintes.ListeElements[i].positionContrainte1 == contrainte.positionContrainte1 && contraintes.ListeElements[i].positionContrainte2 == contrainte.positionContrainte2 && contraintes.ListeElements[i].operateur == contrainte.operateur) {
                // La contrainte existe déjà
                trouve = true;
            }
        }
        
        i++;
    }

    return trouve;
}

string removeTabulation(string text) {
    string newText = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != '\t') {
            newText += text[i];
        } else {
            newText += " ";
        }
    }

    return newText;
}
string removeDoubleSpace(string text) {
    string newText = "";

    int i = 0;
    while (text[i] != '\0') {
        if (!(text[i] == ' ' && text[i + 1] == ' ')) {
            newText += text[i];
        }
        i++;
    }

    return newText;
}
string removeBeginSpace(string text) {
    string newText = "";

    if (text[0] == ' ') {
        for (int i = 1; i < text.length(); i++) {
            newText += text[i];
        }
    } else {
        newText = text;
    }

    return newText;
}
string removeEndSpace(string text) {
    string newText = "";

    if (text[text.length() - 1] == ' ') {
        for (int i = 0; i < text.length() - 1; i++) {
            newText += text[i];
        }
    } else {
        newText = text;
    }

    return newText;
}
string removeAllIndesirableSpace(string text) {
    text = removeTabulation(text);
    text = removeDoubleSpace(text);
    text = removeBeginSpace(text);
    text = removeEndSpace(text);

    return text;
}