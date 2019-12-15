#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "controle.h"
#include "color.h"

void sauvImport(Bibliotheque& biblio) {
    ifstream sauvLivres("sauvLivres.txt", ios::app);

    int numLivre = 0;
    int livsuiv = 0;
    int ligneLivreSuiv = 0;
    string ligneLivre;

    while (getline(sauvLivres, ligneLivre)) {
        if (ligneLivre == SEP) {
            numLivre++;
            continue;
        }
        if (ligneLivreSuiv == 0) {
            biblio.tab_livres[livsuiv].titre = ligneLivre;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 1) {
            for (unsigned int i = 0; i < ligneLivre.length(); i++) { // jsp si c bon lol
                // AUTEUR(S) ICI
            }
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 2) {
            biblio.tab_livres[livsuiv].date.jour = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 3) {
            biblio.tab_livres[livsuiv].date.mois = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 4) {
            biblio.tab_livres[livsuiv].date.annee = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 5) {
            biblio.tab_livres[livsuiv].pages = stoi(ligneLivre);
            ligneLivreSuiv = 0;
        } else if (ligneLivreSuiv == 6) {
            biblio.tab_livres[livsuiv].genre = ligneLivre; // genre
            livsuiv++;
        }
    }
    biblio.nbrLivres = numLivre;

    ifstream sauvAuteurs("sauvAuteurs.txt", ios::app);

    int numAuteurs = 0;
    int autsuiv = 0;
    int ligneAuteurSuiv = 0;
    string ligneAuteur;

    while (getline(sauvAuteurs, ligneAuteur)) {
        if (ligneAuteur == SEP) {
            numAuteurs++;
            continue;
        }
        if (ligneAuteurSuiv == 0) {
            biblio.tab_auteurs[autsuiv].nom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 1) {
            biblio.tab_auteurs[autsuiv].prenom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 2) {
            biblio.tab_auteurs[autsuiv].dateN.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 3) {
            biblio.tab_auteurs[autsuiv].dateN.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 4) {
            biblio.tab_auteurs[autsuiv].dateN.annee = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 5) {
            biblio.tab_auteurs[autsuiv].dateM.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 6) {
            biblio.tab_auteurs[autsuiv].dateM.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 7) {
            biblio.tab_auteurs[autsuiv].dateM.annee = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 8) {
            biblio.tab_auteurs[autsuiv].nbrLivresAuteur = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 9) {
            // LIVRE(S) ICI
            ligneAuteurSuiv++;
            autsuiv++;
        }
    }
    biblio.nbrAuteurs = numAuteurs;
}