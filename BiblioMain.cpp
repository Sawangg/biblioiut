#include <iostream>
#include <string>
#include "biblio.h"

#define ARROW_UP        1
#define ARROW_DOWN      3
#define ARROW_LEFT      4
#define ARROW_RIGHT     2

using namespace std;

int main() {
    locale::global(locale("fr-FR"));

    Bibliotheque biblio;
    Livre tab_livres[MAX_LIVRES];
    string Options[100];
    int nbElem = 0;
    void menuOptions(int menu, string listOptions[], int& nbElem);
    int MenuWithColor(string Options[], int nbElem);

    biblio.nbrElem = 0;

    menuOptions(1, Options, nbElem);
    MenuWithColor(Options, nbElem);

    return 0;
}