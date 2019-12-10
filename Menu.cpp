#include <iostream>
#include <string>
#include <windows.h> 
#include <conio.h>
using namespace std;

int MenuWithColor(string options[], int nbOptions) {
	void SetColorAndBackground(int ForgC, int BackC);
	SetColorAndBackground(15, 0);

	char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
	char black[] = { 0x1b,'[','0',';','3','0','m',0 };
	char red[] = { 0x1b,'[','0',';','3','1','m',0 };
	char green[] = { 0x1b,'[','0',';','3', '2','m',0 };
	char yellow[] = { 0x1b,'[','0',';','3', '3', 'm',0 };
	char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
	char Upurple[] = { 0x1b,'[','1',';','3','5','m',0 };
	char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
	char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
	char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
	char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };

	int selection = 1, touche, sizeTitre;
	bool choisi = false;

	while (!choisi) {
		system("cls");

		cout << options[0] << endl;

		for (int i = 1; i <= nbOptions; i++) {
			cout << Upurple << i << ". ";
			if (i == selection) {
				SetColorAndBackground(0, 15);
			}
			else {
				SetColorAndBackground(15, 0);
			}
			cout << options[i];
			SetColorAndBackground(15, 0);
			cout << endl;
		}

		do {
			touche = _getch();

			switch (touche)
			{
			case 72:
				if (selection == 1) {
					selection = nbOptions;
				}
				else {
					selection--;
				}
				break;
			case 80:
				if (selection == nbOptions) {
					selection = 1;
				}
				else {
					selection++;
				}
				break;
			case 13:
				choisi = true;
				break;
			}
		} while (touche != 13 && touche != 72 && touche != 80);
	}

	return selection;
}

void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}