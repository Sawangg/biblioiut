#include <iostream>

#include "BiblioUtilitaire.h"

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

void contrainteTitre(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	string information;
	Contraintes contrainte;

	Liste<string> options;
	options.ListeElements[0] = createTitre("Contrainte sur le titre");
	options.ListeElements[1] = "Contrainte sur son titre complet";
	options.ListeElements[2] = "Contrainte sur un bout de son titre";
	options.ListeElements[3] = "Retour";
	options.nbElements = 3;

	switch (menu(options, LIST_NOINDENT, NUMERIC, true)) {
	case 1:
		cout << "Merci de rentrer un titre: ";
		getline(cin, information);
		information = removeAllIndesirableSpace(information);

		ajoutContrainte(contraintes, "TitreCompletLivre", information);
		system("pause");
		break;
	case 2:
		cout << "Merci de rentrer un bout de titre: ";
		getline(cin, information);
		information = removeAllIndesirableSpace(information);

		ajoutContrainte(contraintes, "TitreBoutLivre", information);
		system("pause");
		break;
	case 3:
		// On quitte le menu sans rien faire
		break;
	default:
		break;
	}
}

void contrainteGenre(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	int indiceGenre;
	Contraintes contrainte;

	indiceGenre = selectionGenre("S\202lectionnez le genre\n", LIST_NOINDENT, false);

	if (indiceGenre < GENRES.nbElements) {
		ajoutContrainte(contraintes, "GenreLivre", GENRES.ListeElements[indiceGenre]);
		system("pause");
	} else {
		// On quitte le menu sans rien faire
	}
}

void contrainteAuteur(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	Contraintes contrainte;
	string information;

	Date dateInf, dateSup;

	Liste<string> options;
	options.ListeElements[0] = createTitre("Contrainte sur l'auteur");
	options.ListeElements[1] = "Contrainte sur le nom de l'auteur";
	options.ListeElements[2] = "Contrainte sur le pr\202nom de l'auteur";
	options.ListeElements[3] = "Contrainte sur la date de naissance de l'auteur";
	options.ListeElements[4] = "Contrainte sur par la date de mort de l'auteur";
	options.ListeElements[5] = "Retour";
	options.nbElements = 5;

	switch (menu(options, LIST_NOINDENT, NUMERIC, true)) {
	case 1:
		cout << "Merci de rentrer le nom de l'auteur: ";
		getline(cin, information);
		information = removeAllIndesirableSpace(information);

		ajoutContrainte(contraintes, "NomAuteur", information);
		system("pause");
		break;
	case 2:
		cout << "Merci de rentrer le pr\202nom de l'auteur: ";
		getline(cin, information);
		information = removeAllIndesirableSpace(information);

		ajoutContrainte(contraintes, "Pr\202nomAuteur", information);
		system("pause");
		break;
	case 3:
		// Saisie de a date
		cout << "Entrez la date de naissance de l'auteur" << endl;

		information = convertDate2String(saisieDate(dateInf, dateSup));

		ajoutContrainte(contraintes, "NaissanceAuteur", information);
		system("pause");
		break;
	case 4:
		cout << "Entrez la date de mort de l'auteur" << endl;
		information = convertDate2String(saisieDate(dateInf, dateSup));

		ajoutContrainte(contraintes, "MortAuteur", information);
		system("pause");
		break;
	case 5:
		// On quitte le menu sans rien faire
		break;
	default:
		break;
	}
}

void contrainteDate(Bibliotheque biblio, Liste<Contraintes>& contraintes) {
	string information;
	Contraintes contrainte;

	Date dateInf, dateSup;

	cout << "Entrez la date de parution: " << endl;
	information = convertDate2String(saisieDate(dateInf, dateSup));

	ajoutContrainte(contraintes, "DateLivre", information);
	system("pause");
}