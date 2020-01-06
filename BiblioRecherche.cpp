#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Procédure effectuant la recherche selon la contrainte sélecionnée
//////
//////        ENTREES : bibliotheque, liste de contraintes, contrainte, Liste d'entiers
//////        SORTIES : Liste d'entiers
//////
///////////////////////////////////////////////////////////////
void rechercheLivres(Bibliotheque biblio, Contraintes listeContraintes[], Contraintes contrainteActuelle, Liste<int>& livres) {
	int passage = 0;

	if (contrainteActuelle.positionContrainte1 == contrainteActuelle.positionContrainte2) {
		string type = "", data = "";
        decompositionContrainte(contrainteActuelle, type, data);

		if (type == "TitreCompletLivre") {
			rechercheLivreTitreComplet(biblio, data, livres);
		} else if (type == "TitreBoutLivre") {
			rechercheLivreTitrePartie(biblio, data, livres);
		} else if (type == "GenreLivre") {
			rechercheLivreGenre(biblio, data, livres);
		} else if (type == "DateLivre") {
			rechercheLivreDate(biblio, convertString2Date(data), livres);
		} else if (type == "NomAuteur") {
			rechercheLivreAuteurNom(biblio, data, livres);
		} else if (type == "PrenomAuteur") {
			rechercheLivreAuteurPrenom(biblio, data, livres);
		} else if (type == "NaissanceAuteur") {
			rechercheLivreAuteurDateN(biblio, convertString2Date(data), livres);
		} else if (type == "MortAuteur") {
			rechercheLivreAuteurDateM(biblio, convertString2Date(data), livres);
		} else {
			cout << red << "Erreur inconnu !" << normal;
			system("pause");
		}
	} else {
		Liste<int> livres2;

		rechercheLivres(biblio, listeContraintes, listeContraintes[contrainteActuelle.positionContrainte1], livres);
		rechercheLivres(biblio, listeContraintes, listeContraintes[contrainteActuelle.positionContrainte2], livres2);

		if (contrainteActuelle.operateur == "ET") {
			intersectListes(livres, livres2);
		} else {
			unionListes(livres, livres2);
		}
	}
}


///////////////////////////////////////////////////////////////
//////
//////        Procédures de recherche selon la contrainte
//////
///////////////////////////////////////////////////////////////

void rechercheLivreTitreComplet(Bibliotheque biblio, string titre, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        if (convertString2Upper(biblio.bibliothequeLivre.ListeElements[i].titre) == convertString2Upper(titre)) {
            indiceLivres.ListeElements[indiceLivres.nbElements] = i;
            indiceLivres.nbElements++;
        }
    }
}
void rechercheLivreTitrePartie(Bibliotheque biblio, string bout_titre, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        if (biblio.bibliothequeLivre.ListeElements[i].titre.find(convertString2Lower(convertString2Lower(bout_titre)))) {
            indiceLivres.ListeElements[indiceLivres.nbElements] = i;
            indiceLivres.nbElements++;
        }
    }
}

void rechercheLivreGenre(Bibliotheque biblio, string genre, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        bool trouve = false;
        int z = 0;

        if (biblio.bibliothequeLivre.ListeElements[i].genre == genre) {
            indiceLivres.ListeElements[indiceLivres.nbElements] = i;
            indiceLivres.nbElements++;
            trouve = true;
        }
        z++;
    }
}

void rechercheLivreAuteurNom(Bibliotheque biblio, string nom, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !trouve) {
            if (convertString2Upper(biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].nom) == convertString2Upper(nom)) {
                indiceLivres.ListeElements[indiceLivres.nbElements] = i;
                indiceLivres.nbElements++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurPrenom(Bibliotheque biblio, string prenom, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !trouve) {
            if (convertString2Upper(biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].prenom) == convertString2Upper(prenom)) {
                indiceLivres.ListeElements[indiceLivres.nbElements] = i;
                indiceLivres.nbElements++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurDateN(Bibliotheque biblio, Date date, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !trouve) {
            if (biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateN.annee == date.annee && biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateN.mois == date.mois && biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateN.jour == date.jour) {
                indiceLivres.ListeElements[indiceLivres.nbElements] = i;
                indiceLivres.nbElements++;
                trouve = true;
            }
            z++;
        }
    }
}
void rechercheLivreAuteurDateM(Bibliotheque biblio, Date date, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        bool trouve = false;
        int z = 0;
        while (z < biblio.bibliothequeLivre.ListeElements[i].auteursLivre.nbElements && !trouve) {
            if (biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateM.annee == date.annee && biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateM.mois == date.mois && biblio.bibliothequeAuteur.ListeElements[biblio.bibliothequeLivre.ListeElements[i].auteursLivre.ListeElements[z]].dateM.jour == date.jour) {
                indiceLivres.ListeElements[indiceLivres.nbElements] = i;
                indiceLivres.nbElements++;
                trouve = true;
            }
            z++;
        }
    }
}

void rechercheLivreDate(Bibliotheque biblio, Date date, Liste<int>& indiceLivres) {
    for (int i = 0; i < biblio.bibliothequeLivre.nbElements; i++) {
        if (biblio.bibliothequeLivre.ListeElements[i].date.annee == date.annee && biblio.bibliothequeLivre.ListeElements[i].date.mois == date.mois && biblio.bibliothequeLivre.ListeElements[i].date.jour == date.jour) {
            indiceLivres.ListeElements[indiceLivres.nbElements] = i;
            indiceLivres.nbElements++;
        }
    }
}