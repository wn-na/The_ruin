#ifndef STAGE_H
#define STAGE_H

#include "Lib\Basic.h"
#include "GameUI.h"
#include "Lib\Music.h"
#include "Resource\resource.h"

#define BETA
#ifndef BETA
#define MONCOUNT 10
#else
#define MONCOUNT 3
#endif
void showStageHelp(int stage);
void drowCard(int card[], int ch);
void drowNumber(int x, int y, int num, char background, char font);
void showCard(int mycard, int aicard, int type);
int stage1();
int stage2();
int stage3();
int stage4();
#endif
