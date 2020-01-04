#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h> 

#include "Header.h"

using namespace std;

void menuOptions(Bibliotheque biblio, int menu, string listOptions[], int& nbOptions) {
	ostringstream oss;

	switch (menu) {
	case 1:
		listOptions[0] = createTitre("Bibliotheque IUT");
		listOptions[1] = "Afficher l'ensemble des livres de la bibliothèque";
		listOptions[2] = "Ajouter un nouveau livre";
		listOptions[3] = "Supprimer un livre";
		listOptions[4] = "Rechercher un livre";
		listOptions[5] = "Sauvegarder la bibliothèque";
		listOptions[6] = "Quitter";
		nbOptions = 6;
		break;
	case 2:
		listOptions[0] = createTitre("Recherche livre");
		listOptions[1] = "Rechercher un livre par son titre";
		listOptions[2] = "Rechercher un livre par son genre";
		listOptions[3] = "Rechercher un livre par son auteur";
		listOptions[4] = "Rechercher un livre par sa date de parution";
		listOptions[5] = "Retour";
		nbOptions = 5;
		break;
	case 3:
		listOptions[0] = createTitre("Recherche livre par titre");
		listOptions[1] = "Rechercher un livre par son titre complet";
		listOptions[2] = "Rechercher un livre par un bout de son titre";
		listOptions[3] = "Retour";
		nbOptions = 3;
		break;
	case 4:
		listOptions[0] = createTitre("Contrainte sur l'auteur");
		listOptions[1] = "Contrainte sur le nom de l'auteur";
		listOptions[2] = "Contrainte sur le prénom de l'auteur";
		listOptions[3] = "Contrainte sur la date de naissance de l'auteur";
		listOptions[4] = "Contrainte sur par la date de mort de l'auteur";
		listOptions[5] = "Retour";
		nbOptions = 5;
		break;
	case 5:
		listOptions[0] = "Ajout d'un auteur au livre: \n";
		listOptions[1] = "Choisir un auteur parmi ceux enregistrés";
		listOptions[2] = "Créer un nouvel auteur";
		nbOptions = 2;
		break;
	case 6:
		listOptions[0] = "Sélectionnez un auteur\n";
		for (int i = 0; i < biblio.bibliothequeAuteur.nbElements; i++) {
			listOptions[i + 1] = "M/Mme " + biblio.bibliothequeAuteur.ListeElements[i].nom;
			listOptions[i + 1] += " " + biblio.bibliothequeAuteur.ListeElements[i].prenom + " nait le ";
			listOptions[i + 1] += convertDate2String(biblio.bibliothequeAuteur.ListeElements[i].dateN);
			if (biblio.bibliothequeAuteur.ListeElements[i].dateM.jour != 0) {
				listOptions[i + 1] += " et mort le " + convertDate2String(biblio.bibliothequeAuteur.ListeElements[i].dateM);
			}
		}
		listOptions[biblio.bibliothequeAuteur.nbElements + 1] = "Retour";
		nbOptions = biblio.bibliothequeAuteur.nbElements + 1;
		break;
	case 7:
		listOptions[0] = "Sélectionnez le genre\n";
		for (int i = 0; i < 19; i++) {
			listOptions[i + 1] = GENRES.ListeElements[i];
		}
		nbOptions = 19;
		break;
	case 8:
		listOptions[0] = createTitre("Supprimer un/des livre(s)");
		listOptions[1] = "Supprimer selon un titre";
		listOptions[2] = "Supprimer selon un bout de titre";
		listOptions[3] = "Supprimer selon le genre";
		listOptions[4] = "Supprimer selon un auteur";
		listOptions[5] = "Supprimer selon une date de parution";
		listOptions[6] = "Retour";
		nbOptions = 6;
		break;
	case 9:
		listOptions[0] = createTitre("Recherche");
		listOptions[1] = "Créer des contraintes";
		listOptions[2] = "Créer des groupes de contraintes";
		listOptions[3] = "Modifier une contrainte/groupe de contraintes";
		listOptions[4] = "Supprimer une contrainte/groupe de contraintes";
		listOptions[5] = "Effectuer la recherche";
		listOptions[6] = "Retour";
		nbOptions = 6;
		break;
	case 10:
		listOptions[0] = createTitre("Créer une nouvelle contrainte");
		listOptions[1] = "Contrainte sur le titre";
		listOptions[2] = "Contrainte sur le genre";
		listOptions[3] = "Contrainte sur l'auteur";
		listOptions[4] = "Contrainte sur la date de parution du livre";
		listOptions[5] = "Retour";
		nbOptions = 5;
		break;
	case 11:
		listOptions[0] = "Sélectionnez un genre\n";
		for (int i = 0; i < 19; i++) {
			listOptions[i + 1] = GENRES.ListeElements[i];
		}
		listOptions[19] = "Retour";
		nbOptions = 20;
		break;
	case 12:
		listOptions[0] = createTitre("Modification du livre");
		listOptions[1] = "Modifier les informations du livre";
		listOptions[2] = "Supprimer le livre";
		listOptions[3] = "Retour";
		nbOptions = 3;
		break;
	case 13:
		listOptions[0] = createTitre("Modification données du livre");
		listOptions[1] = "Modifier le titre du livre";
		listOptions[2] = "Modifier le genre du livre";
		listOptions[3] = "Modifier le nombre de pages du livre";
		listOptions[4] = "Modifier la date de parution du livre";
		listOptions[5] = "Modifier les auteurs associés au livre";
		listOptions[6] = "Retour";
		nbOptions = 6;
		break;
	case 14:
		listOptions[0] = createTitre("Modification auteurs du livre");
		listOptions[1] = "Supprimer un auteur";
		listOptions[2] = "Ajouter un auteur";
		listOptions[3] = "Retour";
		nbOptions = 3;
		break;
	default:
		listOptions[0] = "ERROR";
		break;
	}
}
string createTitre(string titre) {
	int sizeTitre = titre.size();
	string newTitre = "";

	for (int i = 0; i < sizeTitre + 2 + 12 * 2; i++) {
		newTitre += string(cyan) + "=";
	}
	newTitre += "\n";
	newTitre += "=";
	for (int i = 0; i < sizeTitre + 12 * 2; i++) {
		newTitre += " ";
	}
	newTitre += "=";
	newTitre += "\n";
	newTitre += "=            " + string(blue) + titre + string(cyan) + "            =";
	newTitre += "\n";
	newTitre += "=";
	for (int i = 0; i < sizeTitre + 12 * 2; i++) {
		newTitre += " ";
	}
	newTitre += "=";
	newTitre += "\n";
	for (int i = 0; i < sizeTitre + 2 + 12 * 2; i++) {
		newTitre += "=";
	}
	newTitre += "\n\n";
	newTitre += normal;

	return newTitre;
}

string createTextCenter(string titre) {
	string lineTitre = "";
	string newTitre = "";

	// Récupérer taille console
	int longueur, hauteur, length = 0;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	longueur = coninfo.srWindow.Right + 1;
	hauteur = coninfo.srWindow.Bottom + 1;

	for (int i = 0; i < titre.length(); i++) {
		lineTitre += titre[i];
		
		if (titre[i] == '\n' || i == titre.length() - 1) {
			for (int z = 0; z < (longueur - lineTitre.length()) / 2; z++) {
				newTitre += " ";
			}
			newTitre += lineTitre;
			lineTitre = "";
			length = 0;
		}
	}


	return newTitre;
}




int menu(Liste<string> options, int typeMenu, int puces, bool isCls) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD positionOption;;

	int positionOptions = 0;

	SetColorAndBackground(15, 0);

	int selection = 1, oldselection = 1, touche;
	bool choisi = false;

	if (isCls) system("cls");
	// On affiche le titre du menu
	cout << options.ListeElements[0];
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	positionOptions = coninfo.dwCursorPosition.Y;

	// Controle des impossibilités
	if (!(typeMenu == INLINE && options.nbElements == 2 && options.ListeElements[1].length() + options.ListeElements[2].length() < getTailleConsole().X)) {
		typeMenu = LIST_NOINDENT;
	}

	for (int i = 1; i <= options.nbElements; i++) {
		if (typeMenu == INLINE) {
			positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * i;
			if (i == 2) positionOption.X += options.ListeElements[1].length();
			positionOption.Y = positionOptions;
		} else {
			positionOption.X = 0;
			positionOption.Y = positionOptions + i - 1;
		}

		if (i == selection) {
			changeSelection(i, options, true, typeMenu, puces, positionOption);
		} else {
			changeSelection(i, options, false, typeMenu, puces, positionOption);
		}
	}

	while (!choisi) {
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);

		do {
			touche = _getch();

			oldselection = selection;
			if ((touche == KEY_UP && typeMenu != INLINE) || (touche == KEY_LEFT && typeMenu == INLINE)) {
				if (selection == 1) {
					selection = options.nbElements;
				} else {
					selection--;
				}

				if (typeMenu == INLINE) {
					positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * oldselection;
					if (oldselection == 2) positionOption.X += options.ListeElements[1].length();
					positionOption.Y = positionOptions;
				} else {
					positionOption.X = 0;
					positionOption.Y = positionOptions + oldselection - 1;
				}
				changeSelection(oldselection, options, false, typeMenu, puces, positionOption);

				if (typeMenu == INLINE) {
					positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * selection;
					if (selection == 2) positionOption.X += options.ListeElements[1].length();
					positionOption.Y = positionOptions;
				} else {
					positionOption.X = 0;
					positionOption.Y = positionOptions + selection - 1;
				}
				changeSelection(selection, options, true, typeMenu, puces, positionOption);
			} else if ((touche == KEY_DOWN && typeMenu != INLINE) || (touche == KEY_RIGHT && typeMenu == INLINE)) {
				if (selection == options.nbElements) {
					selection = 1;
				} else {
					selection++;
				}
				if (typeMenu == INLINE) {
					positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * oldselection;
					if (oldselection == 2) positionOption.X += options.ListeElements[1].length();
					positionOption.Y = positionOptions;
				} else {
					positionOption.X = 0;
					positionOption.Y = positionOptions + oldselection - 1;
				}
				changeSelection(oldselection, options, false, typeMenu, puces, positionOption);

				if (typeMenu == INLINE) {
					positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * selection;
					if (selection == 2) positionOption.X += options.ListeElements[1].length();
					positionOption.Y = positionOptions;
				} else {
					positionOption.X = 0;
					positionOption.Y = positionOptions + selection - 1;
				}
				changeSelection(selection, options, true, typeMenu, puces, positionOption);
			} else if (touche == ENTER) {
				choisi = true;
			} else {
				if (touche >= 49 && touche <= (48 + options.nbElements)) {
					oldselection = selection;
					selection = touche - 48;
					if (typeMenu == INLINE) {
						positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * oldselection;
						if (oldselection == 2) positionOption.X += options.ListeElements[1].length();
						positionOption.Y = positionOptions;
					} else {
						positionOption.X = 0;
						positionOption.Y = positionOptions + oldselection - 1;
					}
					changeSelection(oldselection, options, false, typeMenu, puces, positionOption);

					if (typeMenu == INLINE) {
						positionOption.X = ((getTailleConsole().X - (options.ListeElements[1].length() + options.ListeElements[2].length())) / 3) * selection;
						if (selection == 2) positionOption.X += options.ListeElements[1].length();
						positionOption.Y = positionOptions;
					} else {
						positionOption.X = 0;
						positionOption.Y = positionOptions + selection - 1;
					}
					changeSelection(selection, options, true, typeMenu, puces, positionOption);
					choisi = true;
				}
			}
		} while (touche != ENTER && touche != KEY_UP && touche != KEY_DOWN && !(touche >= 49 && touche <= (48 + options.nbElements)));
	}

	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	changeCoord(0, positionOptions + options.nbElements);

	return selection;
}	
void changeSelection(int selection, Liste<string> options, bool isUnderline, int typeMenu, int puces, COORD positionOption) {
	COORD now;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	getCoordCursor(now);
	changeCoord(positionOption.X, positionOption.Y);

	if (isUnderline) {
		SetColorAndBackground(0, 15);
	} else {
		SetColorAndBackground(15, 0);
	}

	if (typeMenu == LIST_INDENT) {
		cout << "\t";
	}
	if (puces == NUMERIC || (puces == ALPHA && options.nbElements > 26)) {
		cout << Upurple << selection << ". " << normal;
	} else if (puces == ALPHA) {
		cout << Upurple << ('a' + (selection - 1)) << ". " << normal;
	}

	if (isUnderline) {
		SetColorAndBackground(0, 15);
	} else {
		SetColorAndBackground(15, 0);
	}

	cout << options.ListeElements[selection];

	SetColorAndBackground(15, 0);

	changeCoord(now.X, now.Y);
}
