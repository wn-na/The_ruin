#include "Basic.h"

#ifdef GOTOXY
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	COORD c = { x, y };
	if (!h)	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, c);
}
#else
void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
#endif

void eraseCur() {
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void SetCursorType(CURSOR_TYPE Type) {
	CONSOLE_CURSOR_INFO CCI;

	switch (Type) {
	case NOCURSOR:
		CCI.dwSize = 1;
		CCI.bVisible = FALSE;
		break;

	case SOLIDCURSOR:
		CCI.dwSize = 100;
		CCI.bVisible = TRUE;
		break;

	case NORMALCURSOR:
		CCI.dwSize = 20;
		CCI.bVisible = TRUE;
		//break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}

void setWindowSize(int x, int y) {
	char buffer[5], command[30] = "mode con: cols=";
	system("cls");
	strncat(command, _itoa(x, buffer, 10), sizeof(char) * ((int)log10((double)x) + 1));
	strncat(command, " lines=", sizeof(char) * 8);
	strncat(command, _itoa(y, buffer, 10), sizeof(char) * ((int)log10((double)y) + 1));
	system(command);
	eraseCur();
}

char colorSet(Color back, Color font) {
	return (back << 4) + font;
}

void gotoPrint(const char *type, int x, int y, const void* text, char back, char font) {
	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back << 4) + font);
	if (strncmp(type, "int", 3) == 0) printf("%d", *(int*)text);
	else if (strncmp(type, "uint", 4) == 0) printf("%u", *(uint*)text);
	else if (strncmp(type, "string", 6) == 0) printf("%s", (char*)text);
	else if (strncmp(type, "char", 4) == 0) printf("%c", *(char*)text);
	else if (strncmp(type, "double", 6) == 0) printf("%lf", *(double*)text);
}

void setConsole(CONSOLE_PROFILE profile) {
	char buffer[5], command[30] = "mode con: cols=";
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = profile.fontSize;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, profile.fontName); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (profile.backColor << 4) + profile.fontColor);

	system("cls");
	strncat(command, _itoa(profile.width, buffer, 10), sizeof(char) * ((int)log10((double)profile.width) + 1));
	strncat(command, " lines=", sizeof(char) * 8);
	strncat(command, _itoa(profile.height, buffer, 10), sizeof(char) * ((int)log10((double)profile.height) + 1));
	system(command);
	CONSOLE_CURSOR_INFO CCI;

	switch (profile.curType) {
	case NOCURSOR:
		CCI.dwSize = 1;
		CCI.bVisible = FALSE;
		break;

	case SOLIDCURSOR:
		CCI.dwSize = 100;
		CCI.bVisible = TRUE;
		break;

	case NORMALCURSOR:
		CCI.dwSize = 20;
		CCI.bVisible = TRUE;
		//break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}

void setFont(const wchar_t *fontName, int fontSize) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = fontSize;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, fontName); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

uchar getKey() {
	uchar key = _getch();
	if (key == 224) {
		key = _getch();
		if (key == UP || key == DOWN || key == LEFT || key == RIGHT) return key;
		else return KEYERROR;
	}
	if (key == 13) return ENTERKEY;
	else if (key == TABKEY) return TABKEY;
	else if (key == ESCKEY) return ESCKEY;
	else if (key == SKEY || key == SKEY - 32) return SKEY;
	else if (key == NUM1) return NUM1;
	else if (key == NUM2) return NUM2;
	else if (key == NUM3) return NUM3;
	else if (key == NUM4) return NUM4;
	else return KEYERROR;
}

// 추후 보안하든지 해야할 소스
int isASCII(char text) {
	if (text < 128 && text >= 0) return 1;
	else return 0;
}

int gotoTyping(char sound, int x, int y, const char* text, char back, char font, int type) {
	int i, speed = 30;
	uchar key;
	char txt[3] = { 0, };

	playWav(sound, 1, 0, 0);
	for (i = 0; text[i] != '\0'; i++) {
		if (_kbhit()) {
			key = getKey();
			if (key == ESCKEY) {
				gotoPrint("string", x + i, y, text + i, back, font);
				playWav(0, 0, 0, 0);;
				if (type)
					system("pause > nul");
				return 1;
			}
			if (key == ENTERKEY) speed = 1;
		}
		if (isASCII(text[i])) {
			gotoPrint("char", x + i, y, &text[i], back, font);
		}
		else {
			txt[0] = text[i];
			txt[1] = text[i + 1];
			i++;
			gotoPrint("string", x + i - 1, y, txt, back, font);
		}
		Sleep(speed);
	}
	playWav(0, 0, 0, 0);
	if (type)
		system("pause > nul");
	return 0;
}

int timeCheck(clock_t times, int timesize) {
	if (clock() - times > timesize) return 1;
	return 0;
}