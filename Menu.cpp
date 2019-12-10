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

int MenuWithColor(string options[], int nbOptions) {
	void changeCoord(int w, int y);
	COORD now;

	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	SetColorAndBackground(15, 0);

	int selection = 1, oldselection, touche;
	bool choisi = false;

	oldselection = selection;
	 
	system("cls");
	cout << options[0] << endl;
	for (int i = 1; i <= nbOptions; i++) {
		cout << Upurple << i << ". " << normal << options[i] << endl;
	}

	while (!choisi) {
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
		now.X = coninfo.dwCursorPosition.X;
		now.Y = coninfo.dwCursorPosition.Y;

		changeCoord(0, oldselection + 5);
		cout << Upurple << oldselection << ". ";
		SetColorAndBackground(15, 0);
		cout << options[oldselection];
		SetColorAndBackground(0, 15);

		changeCoord(0, selection + 5);
		cout << Upurple << selection << ". ";
		SetColorAndBackground(0, 15);
		cout << options[selection];
		SetColorAndBackground(15, 0);

		changeCoord(now.X, now.Y);

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
			}
		} while (touche != ENTER && touche != KEY_UP && touche != KEY_DOWN);
	}

	cout << selection;
	system("pause");

	return selection;
}

void changeCoord(int x, int y) {
	COORD p = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}