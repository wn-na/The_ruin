#include "Music.h"

#ifdef RESOURCE_USE
void playWav(char code, char check, char checkNoStop, char checkLoop) {
	if (check == 0)	
		PlaySound(NULL, 0, 0);
	if (checkNoStop && checkLoop)
		PlaySound(MAKEINTRESOURCE(code), GetModuleHandle(NULL), SND_RESOURCE | SND_FILENAME | SND_ASYNC | SND_NOSTOP | SND_LOOP);
	else if (checkLoop)
		PlaySound(MAKEINTRESOURCE(code), GetModuleHandle(NULL), SND_RESOURCE | SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if (checkNoStop)
		PlaySound(MAKEINTRESOURCE(code), GetModuleHandle(NULL), SND_RESOURCE | SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	else
		PlaySound(MAKEINTRESOURCE(code), GetModuleHandle(NULL), SND_RESOURCE | SND_FILENAME | SND_ASYNC);
}
#else
void playWav(const char *file, char check, char checkNoStop, char checkLoop) {
	if (check == 0)
		PlaySound(NULL, 0, 0);
	if (checkNoStop && checkLoop)
		PlaySound(TEXT(file), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP | SND_LOOP);
	else if (checkLoop)
		PlaySound(TEXT(file), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else if (checkNoStop)
		PlaySound(TEXT(file), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	else
		PlaySound(TEXT(file), NULL, SND_FILENAME | SND_ASYNC);
}
#endif

