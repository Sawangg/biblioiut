#include <iostream>
#include <string>
#include <fstream>
#include "biblio.h"

void sauvDetect(Bibliotheque& biblio) {
    void sauvImport(Bibliotheque & biblio);
    int sauvMenu();

    ifstream sauvLivresExist("sauvLivres.txt");
    ifstream sauvAuteursExist("sauvAuteurs.txt");
    if (sauvLivresExist.good() == true && sauvAuteursExist.good() == true) {
        bool vide = true;
        string ligne;

        while (getline(sauvLivresExist, ligne)) {
            while (getline(sauvAuteursExist, ligne)) {
                vide = false;
                break;
            }
            vide = false;
            break;
        }

        if (vide) {
            biblio.nbrLivres = 0;
            biblio.nbrAuteurs = 0;
        } else {
            // Menu sauvegarde
            int choix = sauvMenu(); // 1 si oui et 2 si non
            if (choix == 2) {
                ofstream sauvLivres; // Création sauvegarde livres
                sauvLivres.open("sauvLivres.txt");
                sauvLivres.close();
                ofstream sauvAuteurs; // Création sauvegarde auteurs
                sauvAuteurs.open("sauvAuteurs.txt");
                sauvAuteurs.close();
                biblio.nbrLivres = 0;
                biblio.nbrAuteurs = 0;
            } else {
                sauvImport(biblio);
            }
        }
        sauvLivresExist.close();
        sauvAuteursExist.close();
    } else {
        ofstream sauvLivres; // Création sauvegarde livres
        sauvLivres.open("sauvLivres.txt");
        sauvLivres.close();
        ofstream sauvAuteurs; // Création sauvegarde auteurs
        sauvAuteurs.open("sauvAuteurs.txt");
        sauvAuteurs.close();
        biblio.nbrLivres = 0;
        biblio.nbrAuteurs = 0;
    }
}
