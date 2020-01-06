#include <Windows.h>
#include <iostream>
using namespace std;


///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de modifier l'emplacement du curseur
//////
//////        ENTREES : entier, entier
//////
///////////////////////////////////////////////////////////////
void changeCoord(int x, int y) {
	COORD p = { SHORT(x), SHORT(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de gérer la visibilité du curseur
//////
//////        ENTREES : booléen
//////
///////////////////////////////////////////////////////////////
void cursorVisible(bool visible) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(out, &cursorInfo);
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de récupérer les coordonnés du curseur
//////
//////        SORTIES : coord
//////
///////////////////////////////////////////////////////////////
void getCoordCursor(COORD& position) {
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	position.X = coninfo.dwCursorPosition.X;
	position.Y = coninfo.dwCursorPosition.Y;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de geler la console (taille non modifiable)
//////
//////        ENTREES : RIEN
//////        SORTIES : RIEN
//////
///////////////////////////////////////////////////////////////
void freezConsole() {
	HWND hwnd = GetConsoleWindow();
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant de récupérer la taille de la console
//////
//////        ENTREES : RIEN
//////        SORTIES : coord
//////
///////////////////////////////////////////////////////////////
COORD getTailleConsole() {
	COORD console;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	console.X = coninfo.srWindow.Right + 1;
	console.Y = coninfo.srWindow.Bottom + 1;

	return console;
}

///////////////////////////////////////////////////////////////
//////
//////        Procédure permettant d'effacer jusqu'à une certaine coordonnée
//////
//////        ENTREES : coord
//////        SORTIES : RIEN
//////
///////////////////////////////////////////////////////////////
void cleanLine(COORD debut) {
	COORD cursorNow;

	getCoordCursor(cursorNow);

	changeCoord(debut.X, debut.Y);
	for (int i = 0; i <= cursorNow.Y - debut.Y; i++) {
		for (int z = 0; z <= getTailleConsole().X; z++) {
			cout << " ";
		}
	}

	changeCoord(debut.X, debut.Y);
}
