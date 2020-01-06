#include "BiblioUtilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier l'existence d'un auteur dans la bibliothèque
//////
//////        ENTREES : auteurs, bibliotheque
//////        SORTIES :entier
//////
//////        Retourne l'indice de l'auteur
//////
///////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier l'existence d'un auteur dans la liste des auteurs du livre
//////
//////        ENTREES : livre, entier
//////        SORTIES : booléen
//////
///////////////////////////////////////////////////////////////
bool verifAuteurExistantLivre(Livre livre, int indiceAuteur) {
    int i = 0;
    bool trouve = false;
    while (i < livre.auteursLivre.nbElements && !trouve) {
        if (livre.auteursLivre.ListeElements[i] == indiceAuteur) {
            // L'auteur existe d\202j\205
            trouve = true;
        }
        i++;
    }

    return trouve;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier l'existence d'un livre dans la bibliothèque
//////
//////        ENTREES : Liste de livres, livre
//////        SORTIES : booléen
//////
///////////////////////////////////////////////////////////////
bool verifLivreExistantBibliotheque(Liste<Livre> livres, Livre livre) {
    int i = 0;
    bool trouve = false;
    while (i < livres.nbElements && !trouve) {
        if (livres.ListeElements[i].titre == livre.titre && livres.ListeElements[i].pages == livre.pages && livres.ListeElements[i].genre == livre.genre && livres.ListeElements[i].date.jour == livre.date.jour && livres.ListeElements[i].date.mois == livre.date.mois && livres.ListeElements[i].date.annee == livre.date.annee && livres.ListeElements[i].auteursLivre.ListeElements == livre.auteursLivre.ListeElements) {
            // Le livre existe d\202j\205
            trouve = true;
        }
        i++;
    }

    return trouve;
}

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de vérifier l'existence d'une contraintes dans une liste de contraintes
//////
//////        ENTREES : contrainte, liste de contraintes
//////        SORTIES : booléen
//////
///////////////////////////////////////////////////////////////
bool verifContrainteExistanteBibliotheque(Contraintes contrainte, Liste<Contraintes> contraintes) {
    int i = 0;
    bool trouve = false;
    while (i < contraintes.nbElements && !trouve) {
        if (contraintes.ListeElements[i].positionContrainte1 == contraintes.ListeElements[i].positionContrainte2) {
            if (contraintes.ListeElements[i].contrainte1 == contrainte.contrainte1 && contraintes.ListeElements[i].contrainte2 == contrainte.contrainte2 && contraintes.ListeElements[i].operateur == contrainte.operateur) {
                // La contrainte existe d\202j\205
                trouve = true;
            }
        } else {
            if (contraintes.ListeElements[i].positionContrainte1 == contrainte.positionContrainte1 && contraintes.ListeElements[i].positionContrainte2 == contrainte.positionContrainte2 && contraintes.ListeElements[i].operateur == contrainte.operateur) {
                // La contrainte existe d\202j\205
                trouve = true;
            }
        }

        i++;
    }

    return trouve;
}
