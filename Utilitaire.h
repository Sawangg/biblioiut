#ifndef UTILITAIRE_H
#define UTILITAIRE_H

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
///////          Création de toutes les structures
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
const int MAX = 100;
template <typename A> // Permettra d'utiliser tous les types pour la liste...
struct Liste {
    A ListeElements[MAX];
    int nbElements = 0;
};
typedef struct {
    int jour = -1;
    int mois = 0;
    int annee = 0;
} Date;


string removeTabulation(string text);
string removeDoubleSpace(string text);
string removeBeginSpace(string text);
string removeEndSpace(string text);
string removeAllIndesirableSpace(string text);
string removeAllspace(string text);
string requeteNouveau(string message);

////////////////////////////////////////////////////////////
///////          Fonctions sur les contrôles         ///////
////////////////////////////////////////////////////////////
int ControleEntier();
string verifDate(int a, int m, int j);
Date getDateInf(Date date1, Date date2);
Date getDateSup(Date date1, Date date2);
string verifIntervalleDate(Date dateInf, Date date, Date dateSup);


//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonctions sur les menus
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
string createTextCenter(string titre);
string createTitre(string titreMenu);

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
void SetColorAndBackground(int ForgC, int BackC);


//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction de saisies
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
Date saisieDate(Date dateInf, Date dateSup);


//////////////////////////////////////////////////////////////////////////////////////////////////
///////
///////          Fonction sur les listes
///////
//////////////////////////////////////////////////////////////////////////////////////////////////
void intersectListes(Liste<int>& livres1, Liste<int> livres2);
void unionListes(Liste<int>& livres1, Liste<int> livres2);

#endif
