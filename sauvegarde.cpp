#include <string>
#include <fstream>

#include "biblio.h"
#include "controle.h"
#include "color.h"

using namespace std;

void sauvegarde(Bibliotheque biblio) {
	// On supprime les fichiers
	ofstream resetLivres("sauvLivres.txt");
	resetLivres.close();
	ofstream resetAuteurs("sauvAuteurs.txt");
	resetAuteurs.close();

	// On sauvgearde les livres
	ofstream sauvLivres("sauvLivres.txt", ios::app);
	for (int i = 0; i < biblio.nbrLivres; i++) {
		sauvLivres << biblio.tab_livres[i].titre << endl;
		for (int z = 0; z < biblio.tab_livres[i].nbrAuteurs; z++) {
			sauvLivres << biblio.tab_livres[i].ListeAuteurs[z];
			if (z != biblio.tab_livres[i].nbrAuteurs - 1) {
				sauvLivres << "|";
			} else {
				sauvLivres << endl;
			}
		}
		sauvLivres << biblio.tab_livres[i].genre << endl;
		sauvLivres << convertInt2String(biblio.tab_livres[i].pages) << endl;
		sauvLivres << biblio.tab_livres[i].date.jour << endl;
		sauvLivres << biblio.tab_livres[i].date.mois << endl;
		sauvLivres << biblio.tab_livres[i].date.annee << endl;
		sauvLivres << SEP << endl;
	}
	sauvLivres.close();

	// On sauvegarde les auteurs
	ofstream sauvAuteurs("sauvAuteurs.txt", ios::app);
	for (int i = 0; i < biblio.nbrAuteurs; i++) {
		sauvAuteurs << biblio.tab_auteurs[i].prenom << endl;
		sauvAuteurs << biblio.tab_auteurs[i].nom << endl;
		for (int z = 0; z < biblio.tab_auteurs[i].nbrLivresAuteur; z++) {
			sauvAuteurs << biblio.tab_auteurs[i].listeLivres[z];
			if (z != biblio.tab_auteurs[i].nbrLivresAuteur - 1) {
				sauvAuteurs << "|";
			} else {
				sauvAuteurs << endl;
			}
		}
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateN.jour) << endl;
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateN.mois) << endl;
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateN.annee) << endl;
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateM.jour) << endl;
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateM.mois) << endl;
		sauvAuteurs << convertInt2String(biblio.tab_auteurs[i].dateM.annee) << endl;
		sauvAuteurs << SEP << endl;
	}
	sauvAuteurs.close();

	cout << yellow << "La sauvegarde a été effectué avec succès..." << normal << endl;
	system("pause");
}