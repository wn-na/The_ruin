#include "GameUI.h"

char *npcname[] = { "독백",
"그리드 (나)",
"볼튼 (정보상인)",
"점쟁이 할멈",
"제이미(사냥꾼 협회)",
"종업원(머셔너리 펍)",
"험프리(용병 1)",
"바헨(용병 2)",
"스칼(용병 A)",
"제이브(용병 B)",
"인공지능",
"사회자",
"환관",
"자르반 4세",
"대마법사",
"",
"",
"",
"",
"",
" 주요 정보",
"          " };

void eraseBox(int x, int y, int xsize, int ysize) {
	int i, j;

	for (i = 0; i < xsize; i++) {
		for (j = 0; j < ysize; j++) {
			gotoPrint("string", x + i, y + j, " ", Black, White);
		}
	}

}
int printScriptbox(playscript story) {
	gotoPrint("string", story.npc > 1 && story.npc < 20 ? 56 : 4, 12, "                    ", Black, White);

	drowBox(story.npc > 1 && story.npc < 20 ? 54 : 2, 11, 24, 3, Black, White);
	drowBox(2, 13, 76, 6, Black, White);
	gotoPrint("string", story.npc > 1 && story.npc < 20 ? 54 : 2, 13, story.npc > 1 && story.npc < 20 ? "┛                    ┃" : "┃                    ┗", Black, White);
	eraseBox(4, 14, 72, 4);
	gotoPrint("string", (story.npc > 1 && story.npc < 20 ? 66 : 14) - (strlen(npcname[story.npc]) / 2), 12, npcname[story.npc], Black, White);

	if (gotoTyping(IDR_WAVE3 ,5, 14, story.script, Black, White, 1)) {
		return 1;
	}
	return 0;
}

void printLocation(int i) {
	gotoPrint("string", 1, 20, "현재위치 :                                                      진행도 :   / 5", Black, White);
	if (i == -1) gotoPrint("string", 12, 20, "로비", Black, White);
	if (i == 0) gotoPrint("string", 12, 20, "1 층", Black, White);
	else if (i == 1) gotoPrint("string", 12, 20, "2 층", Black, White);
	else if (i == 2) gotoPrint("string", 12, 20, "3 층", Black, White);
	else if (i == 3) gotoPrint("string", 12, 20, "4 층", Black, White);
	else if (i == 4) gotoPrint("string", 12, 20, "숨겨진 층", Black, White);

	i++;
	gotoPrint("int", 74, 20, &i, Black, White);
}

int showTitle() {
	uchar ch = 0, key = 0;
	playWav(IDR_WAVE5, 1, 0, 1);
	setWindowSize(54, 20);

	gotoPrint("string", 4, 2, "    □    □□  □      □  □□    □□□", Black, White);
	gotoPrint("string", 4, 3, "   □□□□    □       □         □    □", Black, White);
	gotoPrint("string", 4, 4, "  □□        □       □   □    □      □", Black, White);
	gotoPrint("string", 4, 5, " □          □       □   □    □       □", Black, White);
	gotoPrint("string", 4, 6, " □          □      □   □    □       □ ", Black, White);
	gotoPrint("string", 4, 7, "□           □    □    □    □       □", Black, White);
	gotoPrint("string", 4, 8, "□            □□□    □    □         □□", Black, White);

	while (1) {
		gotoPrint("string", 21, 13, ">> NEW GAME", Black, ch == 0 ? Aqua : White);
		gotoPrint("string", 23, 15, ">> EXIT", Black, ch == 1 ? Aqua : White);

		key = getKey();

		if (key == UP || key == DOWN)
			ch = (ch + 1) % 2;
		else if (key == ENTERKEY)
			break;
	}

	playWav(IDR_WAVE5, 0, 0, 0);
	return ch;
}

void drowBox(int x, int y, int xsize, int ysize, char back, char font) {
	int i;
	gotoPrint("string", x, y, "┏", Black, White);
	for (i = 1; i < (xsize / 2);i++) gotoPrint("string", x + (i * 2), y, "━", Black, White);
	gotoPrint("string", x + xsize - 2, y, "┓", Black, White);

	for (i = 1; i < ysize; i++) {
		gotoPrint("string", x, y + i, "┃", Black, White);
		gotoPrint("string", x + xsize - 2, y + i, "┃", Black, White);
	}
	gotoPrint("string", x, y + ysize - 1, "┗", Black, White);
	for (i = 1; i < (xsize / 2) - 1;i++) gotoPrint("string", x + (i * 2), y + ysize - 1, "━", Black, White);
	gotoPrint("string", x + xsize - 2, y + ysize - 1, "┛", Black, White);

}

void eraseingEffect(int xWidth, int xsize, int ysize, char back, char font, int checktime) {
	int i, j;
	clock_t times = clock();

	for (i = 0; i < xsize;) {
		for (j = 0; j < ysize; j++)
			gotoPrint("string", (j % 2) ? xWidth - i * 2 : 2 + i * 2, j + 1, "　", back, font);
		if (timeCheck(times, checktime)) {
			times = clock();
			i++;
		}
	}
}

void happyEnding() {
	uchar i, ch = 0;
	clock_t times = clock();
	char *happyend[] = { "■      ■　    ■      ■■■■■  ■■■■■  ■      ■",
		"■      ■     ■■     ■      ■  ■　    ■   ■    ■",
		"■■■■■    ■■■    ■■■■■  ■■■■■　   ■■",
		"■      ■   ■    ■   ■          ■              ■",
		"■      ■　■      ■　■          ■              ■",
		 "■■■■■  ■      ■  ■■■■  ",
		"■          ■■    ■  ■      ■",
		"■■■■■  ■  ■  ■  ■      ■",
		"■          ■    ■■  ■      ■",
		"■■■■■  ■　    ■  ■■■■  " };


	setWindowSize(62, 23);
	playWav(IDR_WAVE11, 1, 0, 0);
	drowBox(0, 0, 62, 22, Black, White);

	eraseingEffect(58, 29, 20, LightYellow, White, 20);

	times = clock();
	while (!timeCheck(times, 50));

	eraseingEffect(58, 29, 20, Black, White, 10);

	for (i = 0; i < 10;) {
		if (timeCheck(times, 70)) {
			times = clock();
			gotoPrint("string", i < 5 ? 2 : 14, i < 5 ? 5 + i : 7 + i, happyend[i], Black, White);
			i++;
		}
	}
	times = clock();
	while (!timeCheck(times, 998));
	playWav(IDR_WAVE11, 0, 0, 0);
}

void badEnding() {
	uchar i, ch = 0;
	clock_t times = clock();
	char *badend[] = { "■■■■■　    ■      ■■■■  ",
		"■      ■     ■■     ■      ■",
			"■■■■      ■■■    ■      ■",
			"■      ■   ■    ■   ■      ■",
			"■■■■■　■      ■　■■■■  ",
			"■■■■■  ■      ■  ■■■■  ",
			"■          ■■    ■  ■      ■",
			"■■■■■  ■  ■  ■  ■      ■",
			"■          ■    ■■  ■      ■",
			"■■■■■  ■　    ■  ■■■■  "
	};

	setWindowSize(62, 23);
	playWav(IDR_WAVE4, 1, 0, 0);
	drowBox(0, 0, 62, 22, Black, White);

	eraseingEffect(58, 29, 20, Purple, White, 20);

	times = clock();
	while (!timeCheck(times, 50));

	eraseingEffect(58, 29, 20, Black, White, 10);

	for (i = 0; i < 10;) {
		if (timeCheck(times, 70)) {
			times = clock();
			gotoPrint("string", 14, i < 5 ? 5 + i : 7 + i, badend[i], Black, White);
			i++;
		}
	}
	times = clock();
	while (!timeCheck(times, 998));
	playWav(IDR_WAVE4, 0, 0, 0);
}

void gameClear() {
	uchar i, ch = 0;
	clock_t times = clock();
	system("color 07");
	gotoPrint("string", 2, 23, "                        ", Black, White);
	gotoPrint("string", 2, 24, "                        ", Black, White);

	playWav(IDR_WAVE11, 1, 0, 0);
	eraseingEffect(46, 23, 20, Aqua, White, 20);

	times = clock();
	while (!timeCheck(times, 50));

	eraseingEffect(46, 23, 20, Black, White, 10);

	for (i = 0; i < 6;) {
		if (timeCheck(times, 70)) {
			times = clock();
			if (i == 0)		gotoPrint("string", 8, 7, "■  ■  ■　■■■■■  ■      ■", Black, White);
			else if (i == 1)gotoPrint("string", 8, 8, "■  ■  ■      ■      ■■　  ■", Black, White);
			else if (i == 2)gotoPrint("string", 8, 9, "■  ■  ■      ■      ■　■　■", Black, White);
			else if (i == 3)gotoPrint("string", 8, 10, "■  ■  ■      ■  　  ■    ■■", Black, White);
			else if (i == 4)gotoPrint("string", 8, 11, "■■■■■　■■■■■　■      ■", Black, White);
			else if (i == 5)gotoPrint("string", 9, 16, "계속하시려면 아무키나 눌러주세요", Black, White);
			i++;
		}
	}
	getKey();
}

uchar gameOver() {
	uchar i, ch = 0, key;
	clock_t times = clock();
	system("color 07");
	playWav(IDR_WAVE4, 1, 0, 0);
	gotoPrint("string", 2, 23, "                        ", Black, White);
	gotoPrint("string", 2, 24, "                        ", Black, White);

	eraseingEffect(46, 23, 20, Purple, White, 20);

	times = clock();
	while (!timeCheck(times, 50));

	eraseingEffect(46, 23, 20, Black, White, 10);

	for (i = 0; i < 11;) {
		if (timeCheck(times, 70)) {
			times = clock();
			if (i == 0)		gotoPrint("string", 2, 3, "■■■■■　    ■      ■■■■■  ■■■■■", Black, White);
			else if (i == 1)gotoPrint("string", 2, 4, "■             ■■　　 ■　■　■  ■", Black, White);
			else if (i == 2)gotoPrint("string", 2, 5, "■    ■■    ■■■　　■  ■  ■  ■■■■■", Black, White);
			else if (i == 3)gotoPrint("string", 2, 6, "■      ■   ■  　■　 ■　■  ■  ■", Black, White);
			else if (i == 4)gotoPrint("string", 2, 7, "■■■■■　■　　　■　■  ■  ■　■■■■■", Black, White);
			else if (i == 5)gotoPrint("string", 2, 9, "■■■■■　■      ■  ■■■■■  ■■■■■", Black, White);
			else if (i == 6)gotoPrint("string", 2, 10, "■      ■   ■    ■　 ■　        ■　    ■", Black, White);
			else if (i == 7)gotoPrint("string", 2, 11, "■      ■    ■  ■　　■■■■■  ■■■■■", Black, White);
			else if (i == 8)gotoPrint("string", 2, 12, "■      ■     ■■　   ■          ■    ■", Black, White);
			else if (i == 9)gotoPrint("string", 2, 13, "■■■■■　  　■　    ■■■■■　■      ■", Black, White);
			else if (i == 10)gotoPrint("string", 9, 16, "계속하시려면 아무키나 눌러주세요", Black, White);
			i++;
		}
	}
	while (1) {
		gotoPrint("string", 14, 18, "다시하기", Black, ch == 0 ? Aqua : White);
		gotoPrint("string", 28, 18, "건너뛰기", Black, ch == 1 ? Aqua : White);
		key = getKey();
		if (key == RIGHT)
			ch = (ch + 1) % 2;
		else if (key == LEFT)
			ch = (ch + 1) % 2;
		else if (key == ENTERKEY)
			break;
	}
	playWav(IDR_WAVE4, 0, 0, 0);
	return ch;
}

uchar showEnding() {
	char *text[] = {
		"Thanks to Play",
		"Director, Coding, Design, UI",
		"https://github.com/lecheln",
		"Maze Map, Story, Design",
		"J.M.S",
		"Design, Story",
		"K.C.W",
		"Music By OpenSource",
		"2017/11/1 ~ 11/21",
		"Thank You" };
	char *end[] = { "■■■■  ■    ■  ■■■  ",
				"■　      ■■  ■  ■   ■ ",
				"■■■■  ■ ■ ■  ■    ■",
				"■        ■  ■■　■   ■",
				"■■■■  ■    ■  ■■■ "
	};
	char i, ch = 0, t = 0;
	uchar key;
	clock_t times = clock();
	setWindowSize(40, 21);
	for (i = 0; i < 10; ) {
		if (timeCheck(times, 200)) {
			gotoTyping(IDR_WAVE3 ,38 - (strlen(text[i])), i * 2 + 1, text[i], Black, White, 0);
			times = clock();
			i++;
			t++;
		}
	}

	playWav(IDR_WAVE1, 1, 0, 1);

	eraseingEffect(40, 20, 19, Black, White, 20);
	eraseingEffect(40, 20, 19, Black, White, 20);

	for (i = 0; i < 5;) {
		if (timeCheck(times, 70)) {
			times = clock();
			gotoPrint("string", 6, 3 + i, end[i], Black, White);
			i++;
		}
	}

	while (1) {

		gotoPrint("string", 15, 12, "다시 하기", Black, ch == 0 ? Aqua : White);
		gotoPrint("string", 15, 15, "종료 하기", Black, ch == 1 ? Aqua : White);

		key = getKey();

		if (key == UP || key == DOWN)
			ch = (ch + 1) % 2;

		if (key == ENTERKEY) break;

	}
	if (ch == 1) exit(0);
	playWav(IDR_WAVE1, 0, 0, 0);
	return 1;

}

uchar showDisplay(uchar stage) {
	uchar menu = 0, game,  j = 1, ch = 0;
	clock_t times = clock();
	if (stage < 4) {
		setWindowSize(50, 27);
		drowBox(0, 0, 50, 22, Black, White);
		drowBox(0, 22, 30, 4, Black, White);
		drowBox(30, 22, 20, 4, Black, White);
		gotoPrint("string", 34, 23, "가방    저장", Black, White);
		gotoPrint("string", 34, 24, "지도    종료", Black, White);
	}
	else {
		setWindowSize(86, 47);
		drowBox(0, 0, 86, 43, Black, White);
		drowBox(0, 43, 86, 3, Black, White);
	}

	if (stage == 1) game = stage1();
	else if (stage == 2)  game = stage2();
	else if (stage == 3)  game = stage3();
	else if (stage == 4)  game = stage4();
	else if (stage == 5) showEnding();

	if (stage == 5) return 1;
	setWindowSize(50, 27);
	setWindowSize(50, 27);
	drowBox(0, 0, 50, 22, Black, White);
	drowBox(0, 22, 30, 4, Black, White);
	drowBox(30, 22, 20, 4, Black, White);
	gotoPrint("string", 34, 23, "가방    저장", Black, White);
	gotoPrint("string", 34, 24, "지도    종료", Black, White);
	if (game == 0) {
		ch = gameOver();
		return ch;
	}
	else {
		gameClear();
		return 1;
	}
}

#ifdef MENU
void showMenu(uchar *ch, uchar Stage) {
	uchar key;
	while (1) {
		if (Stage == 4) {


		}
		else {
			gotoPrint("string", 34, 23, "가방", Black, *ch == 0 ? Aqua : White);
			gotoPrint("string", 42, 23, "저장", Black, *ch == 1 ? Aqua : White);
			gotoPrint("string", 34, 24, "지도", Black, *ch == 2 ? Aqua : White);
			gotoPrint("string", 42, 24, "종료", Black, *ch == 3 ? Aqua : White);
		}
		key = getKey();
		if (key == UP) *ch = (*ch + 2) % 4;
		else if (key == DOWN) *ch = (*ch + 2) % 4;
		else if (key == LEFT) *ch = (*ch + 3) % 4;
		else if (key == RIGHT) *ch = (*ch + 1) % 4;

		if (key == ENTERKEY || key == ESCKEY) break;
	}
	gotoPrint("string", 34, 23, "가방", Black, White);
	gotoPrint("string", 42, 23, "저장", Black, White);
	gotoPrint("string", 34, 24, "지도", Black, White);
	gotoPrint("string", 42, 24, "종료", Black, White);
	if (key == ESCKEY) return;
	if (*ch == 0)  ShellExecute(NULL, TEXT("open"), TEXT("C:\\ruin\\beg.exe"), NULL, NULL, SW_SHOW);
	if (*ch == 1)
		gotoPrint("string", 5, 26, "베타 버전입니다. 일부 기능이 제한됩니다.", Black, White);
	if (*ch == 2) {
		if (Stage == 1)
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\ruin\\Map.exe"), "1", NULL, SW_SHOW);
		if (Stage == 2)
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\ruin\\Map.exe"), "2", NULL, SW_SHOW);
		if (Stage == 3)
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\ruin\\Map.exe"), "3", NULL, SW_SHOW);
		if (Stage == 4)
			ShellExecute(NULL, TEXT("open"), TEXT("C:\\ruin\\Map.exe"), "4", NULL, SW_SHOW);
	}
	if (*ch == 3) exit(0);
}
#endif