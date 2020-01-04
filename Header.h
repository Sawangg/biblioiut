#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <Windows.h>
using namespace std;

#define KEY_UP        72
#define KEY_DOWN      80
#define KEY_LEFT      75
#define KEY_RIGHT     77
#define ENTER         13
#define ESCAPE        27
#define INLINE        1
#define LIST_INDENT   2
#define LIST_NOINDENT 3
#define NUMERIC       1
#define ALPHA         2
#define NONE          3

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Création de toutes les constantes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
const int MAX = 100;
const string SEP = "sep##^µ^¨%**=-+---=Ã=-*$1007£é@SeP!?===)à+]°";

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Création de toutes les structures
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename A> // Permettra d'utiliser tous les types pour la liste...
struct Liste {
    A ListeElements[MAX];
    unsigned int nbElements = 0;
};
const Liste<string> GENRES = { {"Roman", "Manga", "Bande dessinée", "Poésie", "Fable", "Science-fiction", "Fantaisie", "Fantastique", "Horreur", "Biographie", "Conte", "Epopée", "Nouvelle", "Article", "Pièce de théâtre", "Lettre", "Essai", "Policier", "Autre" }, 19 };
typedef struct {
    int jour = 0;
    int mois = 0;
    int annee = 0;
} Date;
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
    unsigned int positionContrainte1 = 0;
    string operateur = "ET";
    string contrainte2;
    unsigned int positionContrainte2 = 0;
} Contraintes;

string removeTabulation(string text);
string removeDoubleSpace(string text);
string removeBeginSpace(string text);
string removeEndSpace(string text);
string removeAllIndesirableSpace(string text);

////////////////////////////////////////////////////////////
///////          Fonctions sur les contrôles         ///////
////////////////////////////////////////////////////////////
int ControleEntier();
string verifDate(int a, int m, int j);
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
///////          Fonctions sur les menus
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
int menuGeneral(Bibliotheque biblio, int menu);
int menuGeneralOptions(Bibliotheque biblio, int menu, Liste<string> options);
string createTextCenter(string titre);
string createTitre(string titreMenu);
int sauvMenu();
void changeSelectionSauvegarde(int newSelection, string options[]);

int menu(Liste<string> options, int typeMenu, int puces, bool isCls);
void changeSelection(int selection, Liste<string> options, bool isUnderline, int typeMenu, int puces, COORD positionOption);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonctions sur la console
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void freezConsole();
COORD getTailleConsole();
void cleanLine(COORD menu);
void changeCoord(int x, int y);
void cursorVisible(bool visible);
void getCoordCursor(COORD& position);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonctions de conversion
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
string convertDate2String(Date date);
Date convertString2Date(string dateS);
string convertInt2String(int entier);
int convertString2Int(string entierS);
string convertString2Upper(string data);
string convertString2Lower(string data);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonctions sur les couleurs
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
static char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
static char black[] = { 0x1b,'[','0',';','3','0','m',0 };
static char red[] = { 0x1b,'[','0',';','3','1','m',0 };
static char green[] = { 0x1b,'[','0',';','3', '2','m',0 };
static char yellow[] = { 0x1b,'[','0',';','3', '3', 'm',0 };
static char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
static char Upurple[] = { 0x1b,'[','1',';','3','5','m',0 };
static char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
static char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
static char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
static char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };
int getHeightWithoutSC(string text);
void SetColorAndBackground(int ForgC, int BackC);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur l'affichage des livres
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void afficheLivres(Bibliotheque& biblio);
void creationListeLivresBibliotheque(Bibliotheque biblio, Liste<int>& livres);
void afficheLivres(Bibliotheque& biblio, Liste<int> livres);
void affichageSeparationsColonnes(Liste<int> coordXSeparation, COORD cursor, Livre livre);
void affichageDonneesColonnes(Liste<int> coordXColonne, Liste<int> coordXSeparation, COORD cursor, Bibliotheque biblio, Livre livre);
int creationTableauLivre(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, Liste<int> livres, int debut, int numPage);
void afficheStringInTableau(string donnee, int taille);
void separatorTab();
void enteteTab(Liste<int> coordXColonne, Liste<int> coordXSeparation);
int getPositionLivreTableau(Bibliotheque biblio, int indiceLivres[], int debut, int indiceSelection);
void removeUnderlineOldSelection(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, int indiceLivres[], int oldSelection, int debut);
void underlineSelection(Liste<int> coordXColonne, Liste<int> coordXSeparation, Bibliotheque biblio, int indiceLivres[], int newSelection, int debut);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur l'ajout des livres
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void ajoutLivre(Bibliotheque& biblio);
void ajoutAuteurs(Bibliotheque& biblio, int indiceLivre);
int selectionAuteur(Bibliotheque biblio);



string requeteNouveau(string message);

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
Date saisieDate();
void saisieAuteur(Bibliotheque& biblio, Livre& livre, int indiceLivre);
void ajoutAuteurBibliotheque(Auteur auteur, Bibliotheque& biblio);
void ajoutAuteurLivre(int indiceAuteur, int indiceLivre, Bibliotheque& biblio);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de création de contraintes
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
///////          Fonction de création de groupes de contraintes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void CreationGroupesContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void creationListeContraintes(Liste<string>& options, Liste<Contraintes> contraintes);
void modificationContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes);
void utilisationContrainte(Liste<Contraintes> contraintes, int indiceContrainte, Liste<int>& indicesContraintes);
void suppressionContrainte(Bibliotheque biblio, Liste<Contraintes>& contraintes);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de recherches
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void Recherche(Bibliotheque biblio, Liste<Contraintes> & contraintes);
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
///////          Fonction sur les listes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void intersectListes(Liste<int>& livres1, Liste<int> livres2);
void unionListes(Liste<int> livres1, Liste<int> livres2);

//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur les suppressions
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void auteursLivre(Bibliotheque biblio, int indiceLivre, Liste<int>& indicesAuteurs);
void suppressionLivre(Bibliotheque& biblio, int indiceLivre);
void livresAuteur(Bibliotheque biblio, int indiceAuteur, Liste<int>& indicesLivres);
void suppressionAuteur(Bibliotheque& biblio, int indiceAuteur);

#endif
