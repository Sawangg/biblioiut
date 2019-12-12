#include <iostream>
#include <string>
#include <windows.h> 
#include <conio.h>

#include "color.h"

#define KEY_UP        72
#define KEY_DOWN      80
#define KEY_LEFT      75
#define KEY_RIGHT     77
#define ENTER         13
using namespace std;

COORD nowSauvegarde;

int sauvMenu() {
	void changeSelectionSauvegarde(int oldSelection, int newSelection, string options[]);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	string options[30];
	options[1] = "OUI";
	options[2] = "NON";
	int nbOptions = 2;

	SetColorAndBackground(15, 0);

	int selection = 1, oldselection, touche;
	bool choisi = false;

	oldselection = selection;

	system("cls");
	cout << "Une sauvegarde est diponible, souhaitez-vous la charger ?" << endl;
	cout << "(Si non, vous écraserez la sauvegarde actuelle avec les nouvelles données" << endl;
	cout << "\t\t" << options[1] << "\t\t" << options[2] << endl;

	changeSelectionSauvegarde(oldselection, selection, options);

	while (!choisi) {
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);

		do {
			touche = _getch();

			oldselection = selection;
			switch (touche) {
			case KEY_LEFT:
				if (selection == 1) {
					selection = nbOptions;
				} else {
					selection--;
				}
				break;
			case KEY_RIGHT:
				if (selection == nbOptions) {
					selection = 1;
				} else {
					selection++;
				}
				break;
			case ENTER:
				choisi = true;
				break;
			default:
				if (touche >= 49 && touche <= (48 + nbOptions)) {
					oldselection = selection;
					selection = touche - 48;
					choisi = true;
				}
			}
		} while (touche != ENTER && touche != KEY_LEFT && touche != KEY_RIGHT && !(touche >= 49 && touche <= (48 + nbOptions)));

		changeSelectionSauvegarde(oldselection, selection, options);
	}

	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);

	return selection;
}

void changeSelectionSauvegarde(int oldSelection, int newSelection, string options[]) {
	void changeCoord(int w, int y);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	nowSauvegarde.X = coninfo.dwCursorPosition.X;
	nowSauvegarde.Y = coninfo.dwCursorPosition.Y;

	if (newSelection == 1) {
		changeCoord(0, 2);
		SetColorAndBackground(15, 0);
		cout << "\t\t";
		SetColorAndBackground(0, 15);
		cout << options[1];
		SetColorAndBackground(15, 0);
		cout << "\t\t";
		cout << options[2] << endl;
	} else {
		changeCoord(0, 2);
		SetColorAndBackground(15, 0);
		cout << "\t\t";
		cout << options[1];
		cout << "\t\t";
		SetColorAndBackground(0, 15);
		cout << options[2] << endl;
	}

	changeCoord(nowSauvegarde.X, nowSauvegarde.Y);
}