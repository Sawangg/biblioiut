#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"
#include "controle.h"
#include "color.h"

void sauvImport(Bibliotheque& biblio) {
    // On importe la sauvegarde des livres
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
            biblio.tab_livres[livsuiv].titre = ligneLivre;
            ligneLivreSuiv++;
        } else if(ligneLivreSuiv == 1) {
            for (int i = 0; i < ligneLivre.length(); i++) {
                if (ligneLivre[i] == '|') {
                    biblio.tab_livres[livsuiv].ListeAuteurs[nbAuteurs] = stoi(auteur);
                    nbAuteurs++;
                    auteur = "";
                } else {
                    auteur += ligneLivre[i];
                }
            }
            biblio.tab_livres[livsuiv].ListeAuteurs[nbAuteurs] = stoi(auteur);
            biblio.tab_livres[livsuiv].nbrAuteurs = nbAuteurs + 1;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 2) {
            biblio.tab_livres[livsuiv].genre = ligneLivre;
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 3) {
            biblio.tab_livres[livsuiv].pages = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 4) {
            biblio.tab_livres[livsuiv].date.jour = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 5) {
            biblio.tab_livres[livsuiv].date.mois = stoi(ligneLivre);
            ligneLivreSuiv++;
        } else if (ligneLivreSuiv == 6) {
            biblio.tab_livres[livsuiv].date.annee = stoi(ligneLivre);
            ligneLivreSuiv = 0;
            livsuiv++;
        } 
    }
    biblio.nbrLivres = numLivre;


    // On importe la sauvegarde des livres
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
            biblio.tab_auteurs[autsuiv].prenom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 1) {
            biblio.tab_auteurs[autsuiv].nom = ligneAuteur;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 2) {
            for (int i = 0; i < ligneAuteur.length(); i++) {
                if (ligneAuteur[i] == '|') {
                    biblio.tab_auteurs[autsuiv].listeLivres[nbLivres] = stoi(livres);
                    nbLivres++;
                    livres = "";
                } else {
                    livres += ligneAuteur[i];
                }
            }
            biblio.tab_auteurs[autsuiv].listeLivres[nbLivres] = stoi(livres);
            biblio.tab_auteurs[autsuiv].nbrLivresAuteur = nbLivres + 1;
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 3) {
            biblio.tab_auteurs[autsuiv].dateN.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 4) {
            biblio.tab_auteurs[autsuiv].dateN.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 5) {
            biblio.tab_auteurs[autsuiv].dateN.annee = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 6) {
            biblio.tab_auteurs[autsuiv].dateM.jour = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 7) {
            biblio.tab_auteurs[autsuiv].dateM.mois = stoi(ligneAuteur);
            ligneAuteurSuiv++;
        } else if (ligneAuteurSuiv == 8) {
            biblio.tab_auteurs[autsuiv].dateM.annee = stoi(ligneAuteur);
            ligneAuteurSuiv = 0;
            autsuiv++;
        }
    }
    biblio.nbrAuteurs = numAuteurs;
}