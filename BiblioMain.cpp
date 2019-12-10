#include <iostream>
#include <string>
#include "biblio.h"

using namespace std;

int main() {
    Bibliotheque biblio;
    Livre tab_livres[MAX_LIVRES];
    biblio.nbrElem = 0;
    void Menu(Bibliotheque biblio);
    Menu(biblio);
    return 0;
}