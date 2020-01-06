#ifndef BIBLIOUTILITAIRE_H
#define BIBLIOUTILITAIRE_H

#include <string>
#include <Windows.h>

#include "Utilitaire.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Cr\202ation de toutes les constantes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
const string SEP = "sep##^µ^¨%**=-+---=Ã=-*$1007£\202@SeP!?===)\205+]°";

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Cr\202ation de toutes les structures
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
const Liste<string> GENRES = { {"Roman", "Manga", "Bande dessin\202e", "Po\202sie", "Fable", "Science-fiction", "Fantaisie", "Fantastique", "Horreur", "Biographie", "Conte", "Epop\202e", "Nouvelle", "Article", "Pi\212ce de th\202\203tre", "Lettre", "Essai", "Policier", "Autre" }, 19 };
typedef struct {
    string nom;
    string prenom;
    Liste<int> livresAuteur;
    Date dateN;
    Date dateM;
} Auteur;
typedef struct {
    string titre;
    Liste<int> auteursLivre;
    string genre;
    Date date;
    int pages;
} Livre;
typedef struct {
    Liste<Livre> bibliothequeLivre;
    Liste<Auteur> bibliothequeAuteur;
} Bibliotheque;
typedef struct {
    string contrainte1;
    int positionContrainte1 = 0;
    string operateur = "ET";
    string contrainte2;
    int positionContrainte2 = 0;
} Contraintes;


////////////////////////////////////////////////////////////
///////          Fonctions sur les contrôles         ///////
////////////////////////////////////////////////////////////
int verifAuteurExistantBibliotheque(Auteur auteur, Bibliotheque biblio);
bool verifAuteurExistantLivre(Livre livre, int indiceAuteur);
bool verifLivreExistantBibliotheque(Liste<Livre> livres, Livre livre);
bool verifContrainteExistanteBibliotheque(Contraintes contrainte, Liste<Contraintes> contraintes);

///////////////////////////////////////////////////////////////
///////                                                 ///////
///////          Fonctions sur les sauvegardes          ///////
///////                                                 ///////
///////////////////////////////////////////////////////////////
bool detectionSauvegarde();
void importSauvegardeAuteurs(Bibliotheque& biblio);
void importSauvegardeLivres(Bibliotheque& biblio);
void importSauvegarde(Bibliotheque& biblio);
void resetSauvegarde();
void sauvegardeBibliotheque(Bibliotheque biblio);
void sauvegardeLivres(Bibliotheque biblio);
void sauvegardeAuteurs(Bibliotheque biblio);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur l'affichage des livres
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void AfficheLivres(Bibliotheque& biblio);
void creationListeLivresBibliotheque(Bibliotheque biblio, Liste<int>& livres);
void AfficheLivres(Bibliotheque& biblio, Liste<int>& livres);
void affichageSeparationsColonnes(Liste<int> coordXSeparation, COORD cursor, Livre livre);
void affichageDonneesColonnes(Liste<int> coordXColonne, Liste<int> coordXSeparation, COORD cursor, Bibliotheque biblio, Livre livre);
int creationTableauLivre(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, Liste<int> livres, int debut, int numPage);
void afficheStringInTableau(string donnee, int taille);
void separatorTab();
void enteteTab(Liste<int> coordXColonne, Liste<int> coordXSeparation);
int getPositionLivreTableau(Bibliotheque biblio, int indiceLivres[], int debut, int indiceSelection);
void changeSelectionLivre(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, int indiceLivres[], int oldSelection, int debut, bool isUnderline);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur l'ajout des livres
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void AjoutLivre(Bibliotheque& biblio);
void ajoutAuteurs(Bibliotheque& biblio, int indiceLivre);
int selectionAuteur(Bibliotheque biblio, Liste<int> indiceAuteurs, string titre, int typeMenu, bool cls);
int selectionAuteur(Bibliotheque biblio, string titre, int typeMenu, bool cls);
string textSelectionAuteur(Bibliotheque biblio, int indiceAuteur);
int selectionGenre(string titre, int typeMenu, bool cls);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur la modification des livres
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void ModificationLivre(Bibliotheque& biblio, Liste<int>& indiceLivres, int indiceLivre);
void modificationInformationsLivre(Bibliotheque& biblio, int indiceLivre);
void modificationAuteurLivre(Bibliotheque& biblio, int indiceLivre);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de saisies
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
Auteur saisieAuteur();
void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque& biblio);
void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque& biblio);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de cr\202ation de contraintes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void CreationContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes);
string descriptionContrainte(Contraintes contrainte);
void ajoutContrainte(Liste<Contraintes>& contraintes, string typeRestriction, string restriction);
void contrainteTitre(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void contrainteGenre(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void contrainteAuteur(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void contrainteDate(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void decompositionContrainte(Contraintes contrainte, string& type, string& data);
//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de cr\202ation de groupes de contraintes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void CreationGroupesContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void creationListeContraintes(Liste<string>& options, Liste<Contraintes> contraintes);
void ModificationContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void utilisationContrainte(Liste<Contraintes> contraintes, int indiceContrainte, Liste<int>& indicesContraintes);
void SuppressionContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de recherches
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void Recherche(Bibliotheque& biblio, Liste<Contraintes> & contraintes);
void rechercheLivres(Bibliotheque biblio, Contraintes listeContraintes[], Contraintes contraineActuelle, Liste<int>& livres);
void rechercheLivreTitreComplet(Bibliotheque biblio, string titre, Liste<int>& indiceLivres);
void rechercheLivreTitrePartie(Bibliotheque biblio, string bout_titre, Liste<int>& indiceLivres);
void rechercheLivreGenre(Bibliotheque biblio, string genre, Liste<int>& indiceLivres);
void rechercheLivreAuteurNom(Bibliotheque biblio, string nom, Liste<int>& indiceLivres);
void rechercheLivreAuteurPrenom(Bibliotheque biblio, string prenom, Liste<int>& indiceLivres);
void rechercheLivreAuteurDateN(Bibliotheque biblio, Date date, Liste<int>& indiceLivres);
void rechercheLivreAuteurDateM(Bibliotheque biblio, Date date, Liste<int>& indiceLivres);
void rechercheLivreDate(Bibliotheque biblio, Date date, Liste<int>& indiceLivres);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur les suppressions
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void suppressionAuteurBibliotheque(Bibliotheque& biblio, int indiceAuteur);
void modifierIndiceAuteurLivre(Bibliotheque& biblio, int ancienIndice, int nouvelIndice);
void suppressionAuteurLivre(Bibliotheque& biblio, int indiceAuteur, int indiceLivre);
void suppressionLivreBibliotheque(Bibliotheque& biblio, int indiceLivre);
void modifierIndiceLivreAuteur(Bibliotheque& biblio, int ancienIndice, int nouvelIndice);
void suppressionLivreAuteur(Bibliotheque& biblio, int indiceLivre, int indiceAuteur);

void ModificationAuteurs(Bibliotheque& biblio);
void modificationAuteur(Bibliotheque& biblio, int indiceAuteur);

#endif
