#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Header.h"
using namespace std;

bool detectionSauvegarde() {
    bool existe = false;

    ifstream sauvLivresExist("sauvLivres.txt");
    ifstream sauvAuteursExist("sauvAuteurs.txt");

    if (sauvLivresExist.good() == true && sauvAuteursExist.good() == true) {
        existe = true;
        string ligne;

        getline(sauvLivresExist, ligne);
        if (ligne == "" && existe) {
            existe = false;
        }

        getline(sauvAuteursExist, ligne);
        if (ligne == "" && existe) {
            existe = false;
        }

    }

    sauvLivresExist.close();
    sauvAuteursExist.close();

    return existe;
}

void importSauvegardeAuteurs(Bibliotheque& biblio) {
    ifstream sauvLivres("sauvLivres.txt", ios::app);

    int numLivre = 0;
    int livsuiv = 0;
    int ligneLivreSuiv = 0;
    string ligneLivre;
    string auteur = "";
    int nbAuteurs = 0;


    while (getline(sauvLivres, ligneLivre)) {
        if (ligneLivre == SEP) {
            numLivre++;
            nbAuteurs = 0;
            auteur = "";
            continue;
        }
        if (ligneLivreSuiv == 0) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].titre = ligneLivre;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 1) {
            for (int i = 0; i < ligneLivre.length(); i++) {
                if (ligneLivre[i] == '|') {
                    biblio.bibliothequeLivre.ListeElements[livsuiv].auteursLivre.ListeElements[nbAuteurs] = stoi(auteur);
                    nbAuteurs++;
                    auteur = "";
                } else {
                    auteur += ligneLivre[i];
                }
            }
            biblio.bibliothequeLivre.ListeElements[livsuiv].auteursLivre.ListeElements[nbAuteurs] = stoi(auteur);
            biblio.bibliothequeLivre.ListeElements[livsuiv].auteursLivre.nbElements = nbAuteurs + 1;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 2) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].genre = ligneLivre;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 3) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].pages = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 4) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].date.jour = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 5) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].date.mois = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 6) {
            biblio.bibliothequeLivre.ListeElements[livsuiv].date.annee = stoi(ligneLivre);
            ligneLivreSuiv = 0;
            livsuiv++;
        }
    }
    biblio.bibliothequeLivre.nbElements = numLivre;
}

void importSauvegardeLivres(Bibliotheque& biblio) {
    ifstream sauvAuteurs("sauvAuteurs.txt", ios::app);

    int numAuteurs = 0;
    int autsuiv = 0;
    int ligneAuteurSuiv = 0;
    string ligneAuteur;
    string livres;
    int nbLivres = 0;

    while (getline(sauvAuteurs, ligneAuteur)) {
        if (ligneAuteur == SEP) {
            numAuteurs++;
            nbLivres = 0;
            livres = "";
            continue;
        }
        if (ligneAuteurSuiv == 0) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].prenom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 1) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].nom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 2) {
            for (int i = 0; i < ligneAuteur.length(); i++) {
                if (ligneAuteur[i] == '|') {
                    biblio.bibliothequeAuteur.ListeElements[autsuiv].livresAuteur.ListeElements[nbLivres] = stoi(livres);
                    nbLivres++;
                    livres = "";
                } else {
                    livres += ligneAuteur[i];
                }
            }
            biblio.bibliothequeAuteur.ListeElements[autsuiv].livresAuteur.ListeElements[nbLivres] = stoi(livres);
            biblio.bibliothequeAuteur.ListeElements[autsuiv].livresAuteur.nbElements = nbLivres + 1;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 3) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateN.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 4) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateN.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 5) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateN.annee = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 6) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateM.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 7) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateM.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 8) {
            biblio.bibliothequeAuteur.ListeElements[autsuiv].dateM.annee = stoi(ligneAuteur);
            ligneAuteurSuiv = 0;
            autsuiv++;
        }
    }
    biblio.bibliothequeAuteur.nbElements = numAuteurs;
}

void importSauvegarde(Bibliotheque& biblio) {
    // On importe la sauvegarde des livres
    importSauvegardeLivres(biblio);

    // On importe la sauvegarde des livres
    importSauvegardeAuteurs(biblio);
}

void resetSauvegarde() {
    ofstream resetLivres("sauvLivres.txt");
    resetLivres.close();
    ofstream resetAuteurs("sauvAuteurs.txt");
    resetAuteurs.close();
}

void sauvegardeBibliotheque(Bibliotheque biblio) {
    resetSauvegarde();

    // On sauvegarde les livres
    sauvegardeLivres(biblio);
    // On sauvegarde les auteurs
    sauvegardeAuteurs(biblio);

    cout << yellow << "La sauvegarde a été effectuée avec succès..." << normal << endl;
    system("pause");
}
void sauvegardeLivres(Bibliotheque biblio) {
    ofstream sauvLivres("sauvLivres.txt", ios::app);
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        sauvLivres << biblio.bibliothequeLivre.ListeElements[i].titre << endl;
        for (int z = 0; z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements; z++) {
            sauvLivres << biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z];
            if (z != biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements - 1) {
                sauvLivres << "|";
            } else {
                sauvLivres << endl;
            }
        }
        sauvLivres << biblio.bibliothequeLivre.ListeElements[i].genre << endl;
        sauvLivres << convertInt2String(biblio.bibliothequeLivre.ListeElements[i].pages) << endl;
        sauvLivres << biblio.bibliothequeLivre.ListeElements[i].date.jour << endl;
        sauvLivres << biblio.bibliothequeLivre.ListeElements[i].date.mois << endl;
        sauvLivres << biblio.bibliothequeLivre.ListeElements[i].date.annee << endl;
        sauvLivres << SEP << endl;
    }
    sauvLivres.close();
}
void sauvegardeAuteurs(Bibliotheque biblio) {
    ofstream sauvAuteurs("sauvAuteurs.txt", ios::app);
    for (int i = 0; i < biblio.bibliothequeAuteur.nbElements; i++) {
        sauvAuteurs << biblio.bibliothequeAuteur.ListeElements[i].prenom << endl;
        sauvAuteurs << biblio.bibliothequeAuteur.ListeElements[i].nom << endl;
        for (int z = 0; z < biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements; z++) {
            sauvAuteurs << biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.ListeElements[z];
            if (z != biblio.bibliothequeAuteur.ListeElements[i].livresAuteur.nbElements - 1) {
                sauvAuteurs << "|";
            } else {
                sauvAuteurs << endl;
            }
        }
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateN.jour) << endl;
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateN.mois) << endl;
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateN.annee) << endl;
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateM.jour) << endl;
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateM.mois) << endl;
        sauvAuteurs << convertInt2String(biblio.bibliothequeAuteur.ListeElements[i].dateM.annee) << endl;
        sauvAuteurs << SEP << endl;
    }
    sauvAuteurs.close();
}