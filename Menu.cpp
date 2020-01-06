#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h> 

#include "Utilitaire.h"
using namespace std;

///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de créer un titre pour le menu
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de centrer un texte dans la console
//////
//////        ENTREES : chaine
//////        SORTIES : chaine
//////
///////////////////////////////////////////////////////////////
string createTextCenter(string titre) {
	string lineTitre = "";
	string newTitre = "";

	// R\202cup\202rer taille console
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



///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de gérer un menu dynamique retournant l'indice de la sélection
//////
//////        ENTREES : Liste de chapines, entier, entier, booléen
//////        SORTIES : entier
//////
///////////////////////////////////////////////////////////////
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

	// Controle des impossibilit\202s
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
///////////////////////////////////////////////////////////////
//////
//////        Fonction permettant de changer la sélection dans le menu
//////
//////        ENTREES : entier, liste chaînes, booléen, entier, entier, coord
//////        SORTIES : RIEN
//////
///////////////////////////////////////////////////////////////
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
