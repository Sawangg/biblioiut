#include <iostream>
#include <string>
#include <windows.h> 
#include <conio.h>

#include "color.h"
#include "biblio.h"

#define KEY_UP        72
#define KEY_DOWN      80
#define KEY_LEFT      75
#define KEY_RIGHT     77
#define ENTER         13
using namespace std;

COORD now;
int positionOptions;

int MenuWithColor(Bibliotheque biblio, int menu) {
	void menuOptions(Bibliotheque biblio, int menu, string listOptions[], int& nbOptions);
	void changeSelection(int oldSelection, int newSelection, string options[], int menu);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	string options[30];
	int nbOptions = 0;
	menuOptions(biblio, menu, options, nbOptions);

	SetColorAndBackground(15, 0);

	int selection = 1, oldselection, touche;
	bool choisi = false;

	oldselection = selection;
	 
	if (menu != 5 && menu != 6) system("cls");
	cout << options[0];
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	positionOptions = coninfo.dwCursorPosition.Y;

	for (int i = 1; i <= nbOptions; i++) {
		if (menu != 5 && menu != 6) {
			cout << Upurple << i << ". " << normal << options[i] << endl;
		} else {
			cout << Upurple << "\t" << i << ". " << normal << options[i] << endl;
		}
	}
	changeSelection(oldselection, selection, options, menu);

	while (!choisi) {
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);

		do {
			touche = _getch();

			oldselection = selection;
			switch (touche)
			{
			case KEY_UP:
				if (selection == 1) {
					selection = nbOptions;
				}
				else {
					selection--;
				}
				break;
			case KEY_DOWN:
				if (selection == nbOptions) {
					selection = 1;
				}
				else {
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
		} while (touche != ENTER && touche != KEY_UP && touche != KEY_DOWN && !(touche >= 49 && touche <= (48 + nbOptions)));

		changeSelection(oldselection, selection, options, menu);
	}

	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);

	return selection;
}

void changeSelection(int oldSelection, int newSelection, string options[], int menu) {
	void changeCoord(int w, int y);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	now.X = coninfo.dwCursorPosition.X;
	now.Y = coninfo.dwCursorPosition.Y;

	changeCoord(0, oldSelection + positionOptions - 1);
	if (menu != 5 && menu != 6) {
		cout << Upurple << oldSelection << ". ";
	} else {
		cout << Upurple << "\t" << oldSelection << ". ";
	}
	SetColorAndBackground(15, 0);
	cout << options[oldSelection];
	SetColorAndBackground(0, 15);

	changeCoord(0, newSelection + positionOptions - 1);
	if (menu != 5 && menu != 6) {
		cout << Upurple << newSelection << ". ";
	} else {
		cout << Upurple << "\t" << newSelection << ". ";
	}
	SetColorAndBackground(0, 15);
	cout << options[newSelection];
	SetColorAndBackground(15, 0);

	changeCoord(now.X, now.Y);
}

void changeCoord(int x, int y) {
	COORD p = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}