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
#define ONE           49
#define TWO			  50
#define THREE         51
#define FOUR          52
#define FIVE          53
#define SIX           54
#define SEVEN         55
#define EIGHT         56
#define NINE          57
using namespace std;

COORD now;

int MenuWithColor(int menu) {
	void menuOptions(int menu, string listOptions[], int& nbOptions);
	void changeSelection(int oldSelection, int newSelection, string options[]);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	string options[30];
	int nbOptions = 0;
	menuOptions(menu, options, nbOptions);

	SetColorAndBackground(15, 0);

	int selection = 1, oldselection, touche;
	bool choisi = false;

	oldselection = selection;
	 
	system("cls");
	cout << options[0] << endl;
	for (int i = 1; i <= nbOptions; i++) {
		cout << Upurple << i << ". " << normal << options[i] << endl;
	}
	changeSelection(oldselection, selection, options);

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

		changeSelection(oldselection, selection, options);
	}

	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);

	return selection;
}

void changeSelection(int oldSelection, int newSelection, string options[]) {
	void changeCoord(int w, int y);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	now.X = coninfo.dwCursorPosition.X;
	now.Y = coninfo.dwCursorPosition.Y;

	changeCoord(0, oldSelection + 5);
	cout << Upurple << oldSelection << ". ";
	SetColorAndBackground(15, 0);
	cout << options[oldSelection];
	SetColorAndBackground(0, 15);

	changeCoord(0, newSelection + 5);
	cout << Upurple << newSelection << ". ";
	SetColorAndBackground(0, 15);
	cout << options[newSelection];
	SetColorAndBackground(15, 0);

	changeCoord(now.X, now.Y);
}

void changeCoord(int x, int y) {
	COORD p = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}