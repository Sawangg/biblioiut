#ifndef COLOR_H
#define COLOR_H

#include <windows.h>

static char normal[] = { 0x1b,'[','0',';','3','9','m',0 };
static char black[] = { 0x1b,'[','0',';','3','0','m',0 };
static char red[] = { 0x1b,'[','0',';','3','1','m',0 };
static char green[] = { 0x1b,'[','0',';','3', '2','m',0 };
static char yellow[] = { 0x1b,'[','0',';','3', '3', 'm',0 };
static char blue[] = { 0x1b,'[','0',';','3','4','m',0 };
static char Upurple[] = { 0x1b,'[','1',';','3','5','m',0 };
static char cyan[] = { 0x1b,'[','0',';','3','6','m',0 };
static char lgray[] = { 0x1b,'[','0',';','3','7','m',0 };
static char dgray[] = { 0x1b,'[','0',';','3','8','m',0 };
static char Bred[] = { 0x1b,'[','1',';','3','1','m',0 };

static void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}

#endif