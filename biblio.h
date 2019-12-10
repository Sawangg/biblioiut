#ifndef BIBLIO_H
#define BIBLIO_H

#include <string>

using namespace std;

const int MAX_LIVRES = 100;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

/*typedef struct {
    string nom;
    string prenom;
    Date naissance;
    Date mort;
    Livre livres;
} Auteur;*/

typedef struct {
    string titre;
    string auteur;
    Date date;
    int pages;
} Livre;

typedef struct {
    Livre tab_livres[MAX_LIVRES];
    int nbrElem;
} Bibliotheque;

#endif