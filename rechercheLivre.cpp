#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

void rechercheLivreTitreComplet(Bibliotheque biblio, string titre, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        if (biblio.tab_livres[i].titre == titre) {
            position[nbrOccur] = i;
            nbrOccur++;
        }
    }
}
void rechercheLivreTitrePartie(Bibliotheque biblio, string bout_titre, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        if (biblio.tab_livres[i].titre.find(bout_titre)) {
            position[nbrOccur] = i;
            nbrOccur++;
        }
    }
}

void rechercheLivreGenreMultiple(Bibliotheque biblio, string genre[], int nbrGenres, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < nbrGenres && !trouve) {
            if (biblio.tab_livres[i].genre == genre[z]) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}

void rechercheLivreAuteurNom(Bibliotheque biblio, string nom, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.tab_livres[i].nbrAuteurs && !trouve) {
            if (biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].nom == nom) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurPrenom(Bibliotheque biblio, string prenom, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.tab_livres[i].nbrAuteurs && !trouve) {
            if (biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].prenom == prenom) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurNomComplet(Bibliotheque biblio, string nom, string prenom, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.tab_livres[i].nbrAuteurs && !trouve) {
            if (biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].prenom == prenom && biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].nom == nom) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurDateN(Bibliotheque biblio, Date date, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.tab_livres[i].nbrAuteurs && !trouve) {
            if (biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateN.annee == date.annee && biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateN.mois == date.mois && biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateN.jour == date.jour) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurDateM(Bibliotheque biblio, Date date, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.tab_livres[i].nbrAuteurs && !trouve) {
            if (biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateM.annee == date.annee && biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateM.mois == date.mois && biblio.tab_auteurs[biblio.tab_livres[i].ListeAuteurs[z]].dateM.jour == date.jour) {
                position[nbrOccur] = i;
                nbrOccur++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurCombine(Bibliotheque biblio, int position[], int& nbrOccur) {
    // TRY TRY
}


void rechercheLivreDate(Bibliotheque biblio, Date date, int position[], int& nbrOccur) {
    nbrOccur = 0;

    for (int i = 0; i < biblio.nbrLivres; i++) {
        if (biblio.tab_livres[i].date.annee == date.annee && biblio.tab_livres[i].date.mois == date.mois && biblio.tab_livres[i].date.jour == date.jour) {
            position[nbrOccur] = i;
            nbrOccur++;
        }
    }
}
