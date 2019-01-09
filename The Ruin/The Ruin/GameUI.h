#ifndef GAMEUI_H
#define GAMEUI_H
#include "Lib\Basic.h"
#include "Lib\Music.h"
#include "Stage.h"

typedef struct {
	int npc;
	char *script;
}playscript;

typedef struct {
	char *quest;
	char *answer[4], ans;
}question;

void eraseBox(int x, int y, int xsize, int ysize);
int printScriptbox(playscript story);
void printLocation(int i);
int showTitle();
void happyEnding();
void badEnding();
void gameClear();
uchar gameOver();
uchar showEnding();
void eraseingEffect(int xWidth, int xsize, int ysize, char back, char font, int checktime);
void drowBox(int x, int y, int xsize, int ysize, char back, char font);
uchar showDisplay(uchar stage);
#ifdef MENU
void showMenu(uchar *ch, uchar stage);
#endif
#endif
