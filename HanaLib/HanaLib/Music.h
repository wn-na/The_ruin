#ifndef MUSIC_H
#define MUSIC_H
#include "Basic.h"
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib")

#define RESOURCE_USE
#ifdef RESOURCE_USE
void playWav(char code, char check, char checkNoStop, char checkLoop);
#else
void playWav(const char *file, char check, char checkNoStop, char checkLoop);
#endif

#endif