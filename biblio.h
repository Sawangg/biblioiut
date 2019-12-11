#ifndef BIBLIO_H
#define BIBLIO_H

#include <string>

using namespace std;

const int MAX_LIVRES = 100;
const int MAX_AUTEURS = 100;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    string nom;
    string prenom;
    Date dateN;
    Date dateM;
    int nbrLivresAuteur;
    int listeLivres[MAX_LIVRES];
} Auteur;

typedef struct {
    string titre;
    int ListeAuteurs[MAX_AUTEURS];
    string genre;
    string type;
    Date date;
    int pages;
} Livre;

typedef struct {
    Livre tab_livres[MAX_LIVRES];
    int nbrLivres;
    Auteur tab_auteurs[MAX_AUTEURS];
    int nbrAuteurs;
} Bibliotheque;

#endif