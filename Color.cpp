#include <windows.h>

///////////////////////////////////////////////////////////////
//////
//////        Proc�dure permettant de modifier la couleur du texte et du fond sur lequel on �crit (surlignage)
//////
//////        ENTREES : entier, entier
//////
///////////////////////////////////////////////////////////////
void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}