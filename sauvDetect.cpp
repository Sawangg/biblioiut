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
            sauvImport(biblio);
            cout << "Une sauvegarde est disponible ! Voulez-vous l'utiliser ?" << endl << "(Si vous sélectionnez NON vous écraserez la sauvegarde précédente !)" << endl << "\t\tOUI" << "\t\tNON" << endl;
            system("pause");

            // Menu sauvegarde
            int choix = sauvMenu(); // 1 si oui et 2 si non
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
