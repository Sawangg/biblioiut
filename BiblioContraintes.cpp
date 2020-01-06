#include <iostream>

#include "BiblioUtilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de créer la liste des contraintes pour un menu
//////
//////        ENTREES : liste de contraintes
//////        SORTIES : liste de chaînes
//////
//////	      Créer le titre avant l'appel de la fonction
//////
///////////////////////////////////////////////////////////////
void creationListeContraintes(Liste<string>& options, Liste<Contraintes> contraintes) {
	options.nbElements = 0;

	for (int i = 0; i < contraintes.nbElements; i++) {
		options.ListeElements[options.nbElements + 1] = descriptionContrainte(contraintes.ListeElements[i]);
		options.nbElements++;
	}
	options.ListeElements[options.nbElements + 1] = "Retour";
	options.nbElements++;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de gérer l'ajout d'une contrainte
//////
//////        ENTREES : liste de contraintes, chaîne, chaîne
//////        SORTIES : liste de contraintes
//////
///////////////////////////////////////////////////////////////
void ajoutContrainte(Liste<Contraintes>& contraintes, string typeRestriction, string restriction) {
	Contraintes contrainte;

	contrainte.contrainte1 = typeRestriction + "=" + restriction;
	contrainte.positionContrainte1 = contraintes.nbElements;
	contrainte.operateur = "ET";
	contrainte.contrainte2 = typeRestriction + "=" + restriction;
	contrainte.positionContrainte2 = contraintes.nbElements;

	if (!verifContrainteExistanteBibliotheque(contrainte, contraintes)) {
		contraintes.ListeElements[contraintes.nbElements] = contrainte;
		contraintes.nbElements++;
		cout << green << "La contrainte: " << descriptionContrainte(contrainte) << ", a bien \202t\202 ajout\202e" << normal << endl;
	} else {
		cout << red << "La contrainte: " << descriptionContrainte(contrainte) << ", existe d\202j\205..." << normal << endl;
	}
}
///////////////////////////////////////////////////////////////
//////
//////        Fonction retournant le descriptif d'une contrainte
//////
//////        ENTREES : contrainte
//////        SORTIES : chaîne
//////
///////////////////////////////////////////////////////////////
string descriptionContrainte(Contraintes contrainte) {
	string description;

	if (contrainte.positionContrainte1 == contrainte.positionContrainte2) {
		string type, data;
		decompositionContrainte(contrainte, type, data);
		
		if (type == "TitreCompletLivre") {
			description = "Titre est \202gal \205 " + data;
		} else if (type == "TitreBoutLivre") {
			description = "Titre contient " + data;
		} else if (type == "DateLivre") {
			description = "Livre paru le " + data;
		} else if (type == "GenreLivre") {
			description = "Le genre du livre est " + data;
		} else if (type == "NomAuteur") {
			description = "Le nom de l'auteur est " + data;
		} else if (type == "PrenomAuteur") {
			description = "Le pr\202nom de l'auteur est " + data;
		} else if (type == "NaissanceAuteur") {
			description = "L'auteur est n\202 le " + data;
		} else if (type == "MortAuteur") {
			description = "L'auteur est mort la " + data;
		} else {
			description = string(red) + "Erreur inconnue" + string(normal);
		}
	} else {
		description = "Contrainte num\202ro " + convertInt2String(contrainte.positionContrainte1) + " " + contrainte.operateur + " " + "Contrainte num\202ro " + convertInt2String(contrainte.positionContrainte2);
	}

	return description;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de décomposer une contrainte pour différencier le type et les données
//////
//////        ENTREES : contrainte
//////        SORTIES : chaîne, chaîne
//////
///////////////////////////////////////////////////////////////
void decompositionContrainte(Contraintes contrainte, string& type, string& data) {
	int z = 0;
	while (z < contrainte.contrainte1.length() && contrainte.contrainte1[z] != '=') {
		type += contrainte.contrainte1[z];
		z++;
	}
	z++;
	while (z < contrainte.contrainte1.length()) {
		data += contrainte.contrainte1[z];
		z++;
	}
}