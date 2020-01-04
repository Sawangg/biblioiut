#include <iostream>

#include "Header.h"

void CreationContraintes(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
    int choix;
    Liste<string> options;

    do {
        options.ListeElements[0] = createTitre("Cr\202er une nouvelle contrainte");
        options.ListeElements[1] = "Contrainte sur le titre";
        options.ListeElements[2] = "Contrainte sur le genre";
        options.ListeElements[3] = "Contrainte sur l'auteur";
        options.ListeElements[4] = "Contrainte sur la date de parution du livre";
        options.ListeElements[5] = "Retour";
        options.nbElements = 5;
        choix = menu(options, LIST_NOINDENT, NUMERIC, true);

        switch (choix) {
        case 1:
            contrainteTitre(biblio, contraintes);
            break;
        case 2:
			contrainteGenre(biblio, contraintes);
            break;
        case 3:
			contrainteAuteur(biblio, contraintes);
            break;
        case 4:
			contrainteDate(biblio, contraintes);
            break;
        case 5:
            // On quitte le menu...
            break;
        default:
            cout << red << "Erreur inconnue" << endl;
            break;
        }

    } while (choix != 5 && contraintes.nbElements != MAX);
}