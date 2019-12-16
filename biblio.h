#ifndef BIBLIO_H
#define BIBLIO_H

#include <string>

using namespace std;

const int MAX_LIVRES = 100;
const int MAX_AUTEURS = 100;
const string SEP = "sep##^�^�%**=-+---=�=-*$1007��@SeP!?===)�+]�";

typedef struct {
    int jour = 0;
    int mois = 0;
    int annee = 0;
} Date;

typedef struct {
    string nom;
    string prenom;
    int nbrLivresAuteur = 0;
    int listeLivres[MAX_LIVRES];
    Date dateN;
    Date dateM;
} Auteur;

typedef struct {
    string titre;
    int ListeAuteurs[MAX_AUTEURS];
    int nbrAuteurs = 0;
    string genre;
    int pages;
    Date date;
} Livre;

typedef struct {
    Livre tab_livres[MAX_LIVRES];
    int nbrLivres = 0;
    Auteur tab_auteurs[MAX_AUTEURS];
    int nbrAuteurs = 0;
} Bibliotheque;

static string ListeGenre[] = { "Roman", "Manga", "Bande dessin�e", "Po�sie", "Fable", "Science-fiction", "Fantaisie", "Fantastique", "Horreur", "Biographie", "Conte", "Epop�e", "Nouvelle", "Article", "Pi�ce de th��tre", "Lettre", "Essai", "Policier", "Autre" };

#endif