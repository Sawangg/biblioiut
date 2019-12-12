#ifndef BIBLIO_H
#define BIBLIO_H

#include <string>

using namespace std;

const int MAX_LIVRES = 100;
const int MAX_AUTEURS = 100;

typedef struct {
    int jour = 0;
    int mois = 0;
    int annee = 0;
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
    int nbrAuteurs;
    string genre;
    Date date;
    int pages;
} Livre;

typedef struct {
    Livre tab_livres[MAX_LIVRES];
    int nbrLivres;
    Auteur tab_auteurs[MAX_AUTEURS];
    int nbrAuteurs;
} Bibliotheque;

static string ListeGenre[] = { "Roman", "Manga", "Bande dessinée", "Poésie", "Fable", "Science-fiction", "Fantaisie", "Fantastique", "Horreur", "Biographie", "Conte", "Epopée", "Nouvelle", "Article", "Pièce de théâtre", "Lettre", "Essai", "Policier", "Autre" };

#endif