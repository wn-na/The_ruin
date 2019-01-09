#include "Stage.h"
void drowNumber(int x, int y, int num, char background, char font) {
	switch (num) {
	case 0:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "■　　　■", background, font);
		gotoPrint("string", x, y + 2, "■　　　■", background, font);
		gotoPrint("string", x, y + 3, "■　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;
	case 1:
		gotoPrint("string", x, y, "　　■　　", background, font);
		gotoPrint("string", x, y + 1, "　■■　", background, font);
		gotoPrint("string", x, y + 2, "　　■　　", background, font);
		gotoPrint("string", x, y + 3, "　　■　　", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;

	case 2:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "　　　　■", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "■　　　　", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;

	case 3:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "　　　　■", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "　　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;

	case 4:
		gotoPrint("string", x, y, "　　  ■　", background, font);
		gotoPrint("string", x, y + 1, "    ■■　", background, font);
		gotoPrint("string", x, y + 2, "  ■  ■　", background, font);
		gotoPrint("string", x, y + 3, "■■■■■", background, font);
		gotoPrint("string", x, y + 4, "　　　■　", background, font);
		break;

	case 5:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "■　　　　", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "　　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;

	case 6:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "■　　　　", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "■　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;
	case 7:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "　　　　■", background, font);
		gotoPrint("string", x, y + 2, "　　　　■", background, font);
		gotoPrint("string", x, y + 3, "　　　　■", background, font);
		gotoPrint("string", x, y + 4, "　　　　■", background, font);
		break;
	case 8:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "■　　　■", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "■　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;
	case 9:
		gotoPrint("string", x, y, "■■■■■", background, font);
		gotoPrint("string", x, y + 1, "■　　　■", background, font);
		gotoPrint("string", x, y + 2, "■■■■■", background, font);
		gotoPrint("string", x, y + 3, "　　　　■", background, font);
		gotoPrint("string", x, y + 4, "■■■■■", background, font);
		break;
	}
}

void showCard(int mycard, int aicard, int type) {
	int i;
	clock_t times = clock();

		eraseingEffect(46, 23, 20, type ? Aqua : Red, White, 20);

		times = clock();
		while (!timeCheck(times, 50));

		eraseingEffect(46, 23, 20, Black, White, 10);
		
		gotoPrint("string", 7, 7, "플레이어", Black, White);
		gotoPrint("string", 23, 7, "ＶＳ", Black, White);
		gotoPrint("string", 34, 7, "컴 퓨 터", Black, White);

		drowNumber(6, 9, mycard, Black, type ? Aqua : Red);
		drowNumber(33, 9, aicard, Black, type ? Red : Aqua);

	times = clock();
	i = 0;
	while (!timeCheck(times, 600)) {
		if (_kbhit())
			return;
	}
}

void drowCard(int card[], int ch) {
	int i;
	for (i = 0; i < 4; i++) {

		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 12 : 2, "┏━━━━━┓", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 13 : 3, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 14 : 4, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 15 : 5, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 16 : 6, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 17 : 7, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 18 : 8, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 19 : 9, "┃          ┃", Black, ch == i ? Aqua : White);
		gotoPrint("string", i % 2 ? 27 : 9, i > 1 ? 20 : 10, "┗━━━━━┛", Black, ch == i ? Aqua : White);
		drowNumber(i % 2 ? 29 : 11, i > 1 ? 14 : 4, card[i], Black, ch == i ? Aqua : White);
	}

}


void showStageHelp(int stage) {
	eraseBox(2, 1, 46, 20);
	eraseBox(2, 23, 24, 2);

	if (stage == 1) {
		gotoPrint("string", 21, 2, "Stage 1", Black, White);
		gotoPrint("string", 15, 3, "===================", Black, Yellow);
		gotoPrint("string", 12, 5, "스토리의 내용을 기반으로", Black, White);
		gotoPrint("string", 14, 6, "스피드 퀴즈를 맞쳐라!", Black, White);
		gotoPrint("string", 8, 7, "한문제를 틀릴때마다 체력이 깍인다", Black, White);

		gotoPrint("string", 19, 11, "클리어 조건", Black, White);
		gotoPrint("string", 16, 12, "총 3문제를 맞쳐라", Black, White);

		gotoPrint("string", 19, 16, "조작  방법", Black, White);
		gotoPrint("string", 15, 17, "1 2 3 4 : 번호 입력", Black, White);
	}
	else if (stage == 2) {

		gotoPrint("string", 21, 4, "Stage 2", Black, White);
		gotoPrint("string", 15, 5, "===================", Black, Yellow);
		gotoPrint("string", 10, 7, "5개의 카드중 숫자 하나를 내서", Black, White);
		gotoPrint("string", 11, 8, "상대방을 한번 이라도 이겨라", Black, White);
		gotoPrint("string", 11, 9, "한번 질때마다 체력이 깍인다", Black, White);

		gotoPrint("string", 12, 12, "클리어 조건 : ", Black, White);
		gotoPrint("string", 26, 12, "26", Black, LightYellow);
		gotoPrint("string", 28, 12, "초 이하", Black, White);

		gotoPrint("string", 19, 16, "조작  방법", Black, White);
		gotoPrint("string", 15, 17, "1 2 3 4 5 : 번호 입력", Black, White);
		gotoPrint("string", 18, 18, "◀  ▶  : 이동", Black, White);
	}
	else if (stage == 3) {

		gotoPrint("string", 21, 2, "Stage 3", Black, White);
		gotoPrint("string", 15, 3, "===================", Black, Yellow);
		gotoPrint("string", 19, 4, "마물 죽이기", Black, White);
		gotoPrint("string", 22, 6, "설 명", Black, White);
		gotoPrint("string", 9, 7, "이 방에는 독사가 숨어있습니다", Black, White);
		gotoPrint("string", 7, 8, "방안에 숨어있는 뱀을 찾고 처리하세요", Black, White);
		gotoPrint("string", 11, 9, "모두 처리해야 클리어 됩니다", Black, White);
		gotoPrint("string", 8, 10, "뱀과 부딪치게 되면 피가 줄어듭니다", Black, White);
		gotoPrint("string", 10, 11, "시야 범위 : 플레이어 주위로 2칸", Black, White);
		gotoPrint("string", 12, 12, "클리어 조건 : ", Black, White);
		gotoPrint("string", 26, 12, "60", Black, LightYellow);
		gotoPrint("string", 28, 12, "초 이하", Black, White);
		gotoPrint("string", 19, 14, "조작  방법", Black, White);
		gotoPrint("string", 11, 15, "  ▲     플레이어", Black, White);
		gotoPrint("string", 11, 16, "◀◆▶   이동방법", Black, White);
		gotoPrint("string", 11, 17, "  ▼      조작키", Black, White);
		gotoPrint("string", 9, 18, "  S키  사격(총알 1개 소모)", Black, White);
		gotoPrint("string", 7, 20, "  ⓢ : 시야 확대  ⓣ : 5초 증가", Black, White);

	}
	else if (stage == 4) {
		gotoPrint("string", 32, 5, "===================", Black, LightYellow);
		gotoPrint("string", 38, 6, "Stage 4", Black, White);
		gotoPrint("string", 32, 7, "===================", Black, LightYellow);
		gotoPrint("string", 37, 9, "미로 탈출", Black, White);
		gotoPrint("string", 32, 11, "===================", Black, LightYellow);
		gotoPrint("string", 39, 12, "설 명", Black, White);
		gotoPrint("string", 32, 13, "===================", Black, LightYellow);
		gotoPrint("string", 9 + 16, 15, "마지막 층으로 가기위한 난간입니다.", Black, White);
		gotoPrint("string", 11 + 16, 16, "시간에 맞쳐서 클리어 해 주세요", Black, White);
		gotoPrint("string", 13 + 16, 17, "6초마다 체력이 줄어듭니다", Black, White);
		gotoPrint("string", 11 + 16, 18, "체력이 없으면 아사하게 됩니다", Black, White);
		gotoPrint("string", 13 + 16, 20, "클리어 조건 : ", Black, White);
		gotoPrint("string", 28 + 16, 20, "90", Black, LightYellow);
		gotoPrint("string", 30 + 16, 20, "초 이하", Black, White);
		gotoPrint("string", 32, 23, "===================", Black, LightYellow);
		gotoPrint("string", 21 + 16, 24, "조작  방법", Black, White);
		gotoPrint("string", 32, 25, "===================", Black, LightYellow);
		gotoPrint("string", 15 + 2 + 16, 27, "  ▲     플레이어", Black, White);
		gotoPrint("string", 15 + 2 + 16, 28, "◀◆▶   이동방법", Black, White);
		gotoPrint("string", 15 + 2 + 16, 29, "  ▼      조작키", Black, White);

		gotoPrint("string", 32, 31, "===================", Black, LightYellow);
		gotoPrint("string", 17 + 16 + 5, 32, "아 이 템", Black, White);
		gotoPrint("string", 32, 33, "===================", Black, LightYellow);
		gotoPrint("string", 16 + 16, 35, "  ⓗ : 허기 회복", Black, White);
		gotoPrint("string", 8 + 16, 36, "  ⓢ : 시야 확대  ⓣ : 5초 증가", Black, White);

	}

	getKey();

	eraseBox(2, 1, 46, 20);
}

int stage1() { // 스피드 퀴즈

	clock_t times;
	char i, j, tmp = 0;
	int cl = 5, life = 2, ch = 0, cle = 0;
	uchar key, que[7];
	question quest[7] = { { "주인공이 머물던 도시의 이름은?","로얄 그레이브 시", "루인스 그레이브 시", "정글은 그레이브즈 시", "샤인즈 그레이브 시",'2' },
	{ "정보상의 이름은?","볼드","볼링","볼튼","볼트",'3' },
	{ "정보상의 머리 스타일은?", "대머리","투블럭","단발","장발",'1' },
	{ "점쟁이 할멈에게 낸 복채의 값은?","2골드","3골드","4골드","5골드",'2' },
	{ "4인가족 한달 평균 생활비는?","25실버","50실버","75실버","100실버",'4' },
	{ "주인공의 이름은?", "Greed","Desire","Pride","Envy",'1' },
	{ "현재 주인공의 사냥꾼 등급은?","C등급","B등급","A등급","S등급",'3' }
	};

	for (i = 0; i < 7; i++) {
		que[i] = rand() % 7;
		for (j = 0; j < i; j++) {
			if (que[i] == que[j]) {
				i--;
				break;
			}
		}
	}

	showStageHelp(1);
	
	gotoPrint("string", 44, 1, "ＨＰ", Black, White);
	gotoPrint("int", 44 - (int)log10((double)life), 2, &life, Black, White);
	gotoPrint("string", 45, 2, "/2", Black, White);
	gotoPrint("string", 43, 3, "Time", Black, White);
	gotoPrint("int", 44 - (int)log10((double)cl), 4, &cl, Black, White);
	gotoPrint("string", 45, 4, "/5", Black, White);
	gotoPrint("string", 43, 5, "Clear", Black, White);
	gotoPrint("int", 44 - (int)log10((double)cle), 6, &cle, Black, White);
	gotoPrint("string", 45, 6, "/3", Black, White);

	times = clock();

	while (1) {
		if (cle > 2) {
			playWav(0, 0, 0, 0);
			return 1;
		}
		if (ch == 0) {
			playWav(IDR_WAVE7, 1, 0, 0);

			gotoPrint("string", 22 - strlen(quest[que[tmp]].quest) / 2, 6, quest[que[tmp]].quest, Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[0]) / 2 - 2, 9, "1.", Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[0]) / 2, 9, quest[que[tmp]].answer[0], Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[1]) / 2 - 2, 11, "2.", Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[1]) / 2, 11, quest[que[tmp]].answer[1], Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[2]) / 2 - 2, 13, "3.", Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[2]) / 2, 13, quest[que[tmp]].answer[2], Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[3]) / 2 - 2, 15, "4.", Black, White);
			gotoPrint("string", 22 - strlen(quest[que[tmp]].answer[3]) / 2, 15, quest[que[tmp]].answer[3], Black, White);
			ch = 1;
		}
		if (_kbhit()) {
			key = getKey();

			if ((key == NUM1 || key == NUM2 || key == NUM3 || key == NUM4) && key == quest[que[tmp]].ans) {
				playWav(0, 0, 0, 0);
				playWav(IDR_WAVE6, 1, 0, 0);

				eraseingEffect(40, 20, 20, Aqua, White, 20);

				times = clock();
				while (!timeCheck(times, 50));

				eraseingEffect(40, 20, 20, Black, White, 10);

				cle++;
				cl = 5;
				times = clock();
				gotoPrint("int", 44 - (int)log10((double)cl), 4, &cl, Black, White);
				gotoPrint("int", 44 - (int)log10((double)life), 2, &life, Black, White);
				ch = 0;
				tmp++;
				gotoPrint("int", 44 - (int)log10((double)cle), 6, &cle, Black, White);

				playWav(0, 0, 0, 0);
				times = clock();
			}
			else if ((key == NUM1 || key == NUM2 || key == NUM3 || key == NUM4)) {
				playWav(0, 0, 0, 0);
				playWav(IDR_WAVE2, 1, 0, 0);

				eraseingEffect(40, 20, 20, LightRed, White, 20);
				times = clock();
				while (!timeCheck(times, 50));
				eraseingEffect(40, 20, 20, Black, White, 10);

				cl = 5;
				times = clock();
				if (life < 1) return 0;
				life--;
				gotoPrint("int", 44 - (int)log10((double)cl), 4, &cl, Black, White);
				gotoPrint("int", 44 - (int)log10((double)life), 2, &life, Black, White);
				ch = 0;
				tmp++;

				playWav(0, 0, 0, 0);
				times = clock();

			}

		}
		if (timeCheck(times, 998)) {
			times = clock();
			if (cl > 0) {
				cl--;
				gotoPrint("int", 44 - (int)log10((double)cl), 4, &cl, Black, White);
			} else {
				playWav(0, 0, 0, 0);
				playWav(IDR_WAVE2, 1, 0, 0);
				if (life < 1) return 0;
				life--;
				cl = 5;		
				
				eraseingEffect(40, 20, 20, Red, White, 20);
				times = clock();
				while (!timeCheck(times, 50));
				eraseingEffect(40, 20, 20, Black, White, 10);

				gotoPrint("int", 44 - (int)log10((double)cl), 4, &cl, Black, White);
				gotoPrint("int", 44 - (int)log10((double)life), 2, &life, Black, White);
				ch = 0;
				tmp++;

				playWav(0, 0, 0, 0);
				times = clock();
			}
		}
	}
}

int stage2() { // 스토쿠
	clock_t time;
	uchar key;
	char i, j;
	int life = 3, ch = 0, cle = 0, card[4], aicard, type = 0, times = 0, timer = 10;

	showStageHelp(2);

	playWav(IDR_WAVE8, 1, 0, 0);
	time = clock();

	while (1) {
		if (timeCheck(time, 998)) {
			timer--;
			if (timer < 0) {
				timer = 10;
				life--;
				if (life < 1) {
					playWav(0, 0, 0, 0);
					return 0;
				}
				gotoPrint("string", 2, 1, "ＨＰ   / 3      Timer    / 10    Time    / 26", Black, White);
				gotoPrint("int", 7, 1, &life, Black, White);
				gotoPrint("string", 24, 1, "  ", Black, White);
				gotoPrint("int", 25 - (int)log10((double)timer), 1, &timer, Black, White);
				gotoPrint("int", 41 - (int)log10((double)times), 1, &times, Black, White);
			}
			times++;				
			gotoPrint("string", 2, 1, "ＨＰ   / 3      Timer    / 10    Time    / 26", Black, White);
			gotoPrint("int", 7, 1, &life, Black, White);
			gotoPrint("string", 24, 1, "  ", Black, White);
			gotoPrint("int", 25 - (int)log10((double)timer), 1, &timer, Black, White);
			gotoPrint("int", 41 - (int)log10((double)times), 1, &times, Black, White);

			if (times > 25) {
				playWav(0, 0, 0, 0);
				return 0;
			}
			time = clock();
		}
		if (type == 0) {
			for (i = 0; i < 4; i++) {
				card[i] = rand() % 9 + 1;
				for (j = 0; j < i; j++) {
					if (card[i] == card[j]) {
						i--;
						break;
					}
				}
			}
			aicard = rand() % 3 + 7;
			type = 1;

			eraseBox(2, 1, 46, 20);
			gotoPrint("string", 2, 1, "ＨＰ   / 3      Timer    / 10    Time    / 26", Black, White);
			gotoPrint("int", 7, 1, &life, Black, White);
			gotoPrint("int", 24, 1, &timer, Black, White);
			gotoPrint("int", 41, 1, &times, Black, White);

			drowCard(card, ch);

		}

		if (_kbhit()) {
			key = getKey();
			if (key == UP) ch = (ch + 2) % 4;
			else if (key == DOWN) ch = (ch + 2) % 4;
			else if (key == LEFT) ch = (ch + 3) % 4;
			else if (key == RIGHT) ch = (ch + 1) % 4;

			drowCard(card, ch);

			if (key == ENTERKEY) {
				if (card[ch] >= aicard) {
					showCard(card[ch], aicard, 1);
					playWav(0, 0, 0, 0);
					return 1;

				} else {
					playWav(IDR_WAVE2, 1, 1, 0);
					showCard(card[ch], aicard, 0);
					timer = 10;
					life--;
					if (life < 1) {
						playWav(0, 0, 0, 0);
						return 0;
					}				
					gotoPrint("string", 2, 1, "ＨＰ   / 3      Timer    / 10    Time    / 26", Black, White);
					gotoPrint("int", 7, 1, &life, Black, White);
					gotoPrint("string", 24, 1, "  ", Black, White);
					gotoPrint("int", 25 - (int)log10((double)timer), 1, &timer, Black, White);
					gotoPrint("int", 41 - (int)log10((double)times), 1, &times, Black, White);
					time = clock();
					type = 0;

				}

			}
		}
	}
}

int stage3() { // 1 = 클리어, 0 = 실패

	uchar player[2] = { 1, 1 }, playerback[2] = { 1, 1 }, monster[MONCOUNT][2], key, ch, pl = 0, timeup[4][2], scope[2][2];
	char gun = 10, hp = 5, i, j, t, tans = 2, sco = 0;
	int times = 0, count = MONCOUNT;
	clock_t  starttime = 0;

	showStageHelp(3);
	times = 0;

	gotoPrint("string", 43, 1, "Enemy", Black, White);
	gotoPrint("int", 44, 2, &count, Black, White);
	gotoPrint("string", 45, 2, "/3", Black, White);
	gotoPrint("string", 43, 3, "Time", Black, White);
	gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, White);
	gotoPrint("string", 45, 4, "/60", Black, White);
	gotoPrint("string", 2, 23, "ＨＰ■■■■■ 탄창 ■■", Black, White);
	gotoPrint("string", 2, 24, "Shot■■■■■■■■■■", Black, White);
	gotoPrint("string", player[0] * 2 + 2, player[1] + 1, "◆", Black, LightYellow);

	times = 0, starttime = clock();
	// 몬스터 초기화
	for (i = 0; i < 4; i++) {
		timeup[i][0] = rand() % 20;
		timeup[i][1] = rand() % 20;
	}
	for (i = 0; i < 2; i++) {

		scope[i][0] = rand() % 20;
		scope[i][1] = rand() % 20;

	}
	for (i = 0; i < count; i++) {
		monster[i][0] = rand() % 20;
		monster[i][1] = rand() % 20;
	}

	playWav(IDR_WAVE9, 1, 0, 1);
	
	while (1) {
		if (count == 0) {
			playWav(0, 0, 0, 0);
			return 1;
		}
		if (_kbhit()) {
			key = getKey();
			if (key == UP) {
				playerback[0] = player[0];
				playerback[1] = player[1];
				if (player[1] > 0) 	player[1]--;
				ch = 0;
			}
			else if (key == DOWN) {
				playerback[0] = player[0];
				playerback[1] = player[1];
				if (player[1] < 19) player[1]++;
				ch = 1;
			}
			else if (key == LEFT) {
				playerback[0] = player[0];
				playerback[1] = player[1];
				if (player[0] > 0) player[0]--;
				ch = 2;
			}
			else if (key == RIGHT) {
				playerback[0] = player[0];
				playerback[1] = player[1];
				if (player[0] < 19) player[0]++;
				ch = 3;
			}
			else if (key == SKEY) {
				for (t = 0; t < MONCOUNT; t++) {
					if (ch == 0) {
						if (monster[t][0] == player[0] && player[1] - monster[t][1] < 3 && player[1] - monster[t][1] >= 0) {
							count--;
							monster[t][0] = 50;
							gotoPrint("int", 44, 2, &count, Black, White);
						}
					}
					else 	if (ch == 1) {
						if (monster[t][0] == player[0] && monster[t][1] - player[1] < 3 && monster[t][1] - player[1] >= 0) {
							count--;
							monster[t][0] = 50;
							gotoPrint("int", 44, 2, &count, Black, White);
						}
					}
					else	if (ch == 2) {
						if (monster[t][1] == player[1] && player[0] - monster[t][0] < 3 && player[0] - monster[t][0] >= 0) {
							count--;
							monster[t][0] = 50;
							gotoPrint("int", 44, 2, &count, Black, White);
						}
					}
					else	if (ch == 3) {
						if (monster[t][1] == player[1] && monster[t][0] - player[0] < 3 && monster[t][0] - player[0] >= 0) {
							count--;
							monster[t][0] = 50;
							gotoPrint("int", 44, 2, &count, Black, White);
						}
					}


				}
				gun--;
				if (gun < 0 && tans <= 0) {
					playWav(0, 0, 0, 0);
					return 0;
				}
				if (gun < 0 && tans > 0) {
					gun = 10, tans--;
					gotoPrint("string", 2 + 20 + 2 * tans, 23, "□", Black, White);
					gotoPrint("string", 6, 24, "■■■■■■■■■■", Black, White);
				}
				else
					gotoPrint("string", 6 + 2 * gun, 24, "□", Black, White);
			}

			for (t = 0; t < 2; t++) {
				if (scope[t][0] == player[0] && scope[t][1] == player[1]) {
					scope[t][0] = 50;
					sco++;
				}
			}for (t = 0; t < 4; t++) {
				if (timeup[t][0] == player[0] && timeup[t][1] == player[1]) {
					timeup[t][0] = 50;
					if (times - 5 >= 0)	times -= 5;
					else times = 0;
					if (times > 50)
						gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, LightRed);
					else if (times > 40)
						gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, LightYellow);
					else
						gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, White);
				}
			}
#ifndef TEST
			for (i = -2 - sco; i <= 2 + sco; i++) {
				for (j = -2 - sco; j <= 2 + sco; j++) {
					if (i == -2 - sco || i == 2 + sco) {
						if (j == -2 - sco) continue;
						else if (j == 2 + sco) break;
					}
					if (playerback[0] + i < 0 || playerback[0] + i > 19 || playerback[1] + j < 0 || playerback[1] + j > 19) continue;
					gotoPrint("string", 2 + playerback[0] * 2 + 2 * i, 1 + playerback[1] + j, "　", Black, White);
				}
			}
#endif
			for (i = -2 - sco; i <= 2 + sco; i++) {
				for (j = -2 - sco; j <= 2 + sco; j++) {
					if (i == -2 - sco || i == 2 + sco) {
						if (j == -2 - sco) continue;
						else if (j == 2 + sco) break;
					}
					pl = 0;
					if (player[0] + i < 0 || player[0] + i > 19 || player[1] + j < 0 || player[1] + j > 19) continue;
					gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "　", Gray, Gray);


					for (t = 0; t < 2; t++) {
						if (scope[t][0] == player[0] + i && scope[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "ⓢ", Gray, LightBlue);

					}
					for (t = 0; t < 4; t++) {
						if (timeup[t][0] == player[0] + i && timeup[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "ⓣ", Gray, LightGreen);
					}
					for (t = 0; t < MONCOUNT; t++) {
						if (monster[t][0] == player[0] + i && monster[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "★", Gray, LightRed);
						if (i == 0 && j == 0) {
							if (monster[t][0] == player[0] && monster[t][1] == player[1]) {
								if (ch == 0) gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▲", Gray, LightRed);
								else if (ch == 1)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▼", Gray, LightRed);
								else if (ch == 2)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◀", Gray, LightRed);
								else if (ch == 3)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▶", Gray, LightRed);
								else gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◆", Gray, LightRed);
								hp--;
								gotoPrint("string", 6 + 2 * hp, 23, "□", Black, White);
								if (hp <= 0) {
									playWav(0, 0, 0, 0);
									return 0;
								}
								pl = 1;
							}
							else if (pl == 0)
								if (ch == 0) gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▲", Gray, LightYellow);
								else if (ch == 1)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▼", Gray, LightYellow);
								else if (ch == 2)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◀", Gray, LightYellow);
								else if (ch == 3)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▶", Gray, LightYellow);
								else gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◆", Gray, LightYellow);
						}
					}
				}
			}
		}
		if (timeCheck(starttime,999) || times == 0) {
			starttime = clock();
			times++;
			if (times > 60) {

				playWav(0, 0, 0, 0);
				return 0;
			}

			if (times > 50)
				gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, LightRed);
			else if (times > 40)
				gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, LightYellow);
			else
				gotoPrint("int", 44 - (int)log10((double)times), 4, &times, Black, White);
			for (t = 0; t < MONCOUNT; t++) {
				i = rand() % 2;
				j = rand() % 2;

				if (rand() % 2) {
					if (monster[t][0] + i < 0 || monster[t][0] + i > 19 && monster[t][0] != 50) monster[t][0] += (-1) * (i * 2 - 1);
					else monster[t][0] += i * 2 - 1;
				}
				else {
					if (monster[t][1] + j < 0 || monster[t][1] + j > 19) monster[t][1] += (-1) * (j * 2 - 1);
					else monster[t][1] += j * 2 - 1;
				}
			}
#ifndef TEST
			for (i = -2 - sco; i <= 2 + sco; i++) {
				for (j = -2 - sco; j <= 2 + sco; j++) {
					if (i == -2 - sco || i == 2 + sco) {
						if (j == -2 - sco) continue;
						else if (j == 2 + sco) break;
					}
					pl = 0;
					if (player[0] + i < 0 || player[0] + i > 19 || player[1] + j < 0 || player[1] + j > 19) continue;
					gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "　", Black, White);
				}
			}
#endif
			for (i = -2 - sco; i <= 2 + sco; i++) {
				for (j = -2 - sco; j <= 2 + sco; j++) {
					if (i == -2 - sco || i == 2 + sco) {
						if (j == -2 - sco) continue;
						else if (j == 2 + sco) break;
					}
					if (player[0] + i < 0 || player[0] + i > 19 || player[1] + j < 0 || player[1] + j > 19) continue;
					gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "　", Gray, White);
					pl = 0;
					for (t = 0; t < 2; t++) {
						if (scope[t][0] == player[0] + i && scope[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "ⓢ", Gray, LightBlue);
					}
					for (t = 0; t < 4; t++) {
						if (timeup[t][0] == player[0] + i && timeup[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "ⓣ", Gray, LightGreen);
					}
					for (t = 0; t < MONCOUNT; t++) {
						if (monster[t][0] == player[0] + i && monster[t][1] == player[1] + j)
							gotoPrint("string", 2 + player[0] * 2 + 2 * i, 1 + player[1] + j, "★", Gray, LightRed);
						if (i == 0 && j == 0) {
							if (monster[t][0] == player[0] && monster[t][1] == player[1]) {
								if (ch == 0) gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▲", Gray, LightRed);
								else if (ch == 1)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▼", Gray, LightRed);
								else if (ch == 2)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◀", Gray, LightRed);
								else if (ch == 3)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▶", Gray, LightRed);
								else gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◆", Gray, LightRed);
								hp--;
								gotoPrint("string", 6 + 2 * hp, 23, "□", Black, White);
								if (hp <= 0) {
									playWav(0, 0, 0, 0);
									return 0;
								}
								pl = 1;
							}
							else if (pl == 0) {
								if (ch == 0) gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▲", Gray, LightYellow);
								else if (ch == 1)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▼", Gray, LightYellow);
								else if (ch == 2)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◀", Gray, LightYellow);
								else if (ch == 3)gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "▶", Gray, LightYellow);
								else gotoPrint("string", 2 + player[0] * 2, 1 + player[1], "◆", Gray, LightYellow);
							}
						}
					}
				}
			}
		}
	}

}

int stage4() {  // 미로찾기

	int currentRow = 1, currentColumn = 1;
	int moveRow = 1, moveColumn = 1;
	int map[41][41] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 5, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 5, 0, 1, 1, 1, 1, 1, 0, 1, 1, 5, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 4, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 4, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 6, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 5, 0, 1, 0, 1, 6, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 4, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 4, 1, 1, 1, 1, 0, 6, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 1, 6, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 6, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 5, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 4, 0, 1, 1, 1, 1, 1, 0, 1, 0, 5, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 5, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 1, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 6, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 1, 6, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 4, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 4, 1, 1, 0, 1, 1, 1, 1, 4, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 6, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 4, 0, 1, 1, 1, 0, 1, 1, 6, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 6, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 1, 0, 5, 1, 1, 0, 1, 1, 1, 1, 6, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 1, 5, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	int player[2] = { 1,1 }, i, j;
	uchar key;
	int times = 0, hp = 9, hptime = 6, sco = 2;
	clock_t starttime;

	showStageHelp(4);

	times = 0;

	gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, White);
	gotoPrint("string", 0, 44, "┃　 ＨＰ■■■■■■■■■■         Time    / 90      　ＨＰ Time 0 / 6　　　   　┃", Black, White);
	times = 0, starttime = clock();


	playWav(IDR_WAVE10, 1, 0, 1);
	while (1) {

		if (_kbhit()) {
			// 2가 시작지점, 3이 도달지점, 4는 시간 증가5초, 5는 허기, 6, 시야

			key = getKey();

			if (key == UP) {
				moveRow--;

			}
			if (key == DOWN) {
				moveRow++;

			}
			if (key == LEFT) {
				moveColumn--;

			}
			if (key == RIGHT) {
				moveColumn++;

			}
			if (map[moveRow][moveColumn] == 0)
			{
				moveRow = currentRow;
				moveColumn = currentColumn;
			}
			else {
				if (map[moveRow][moveColumn] == 3) {

					playWav(0, 0, 0, 0);
					return 1;
				}
				if (map[moveRow][moveColumn] == 4) {
					if (times < 5) {
						times = 0;
					}
					else times -= 5;
					gotoPrint("string", 43, 44, "  ", Black, LightRed);
					if (times > 70)
						gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, LightRed);
					else if (times > 50)
						gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, Yellow);
					else
						gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, White);
					map[moveRow][moveColumn] = 1;
				}
				if (map[moveRow][moveColumn] == 5) {
					if (hp < 9) {
						hp++;
						gotoPrint("string", 9 + hp * 2, 44, "■", Black, White);
					}
					map[moveRow][moveColumn] = 1;
				}
				if (map[moveRow][moveColumn] == 6) {
					sco++;
					map[moveRow][moveColumn] = 1;
				}

				map[currentRow][currentColumn] = 1;
				map[moveRow][moveColumn] = 1;

				currentRow = moveRow;
				currentColumn = moveColumn;
			}

			for (i = 1; i <= 41; i++)
				gotoPrint("string", 2, i, "　　　　                                  　　　　　　　　　 　　　　　 　　　　　", Black, White);

			for (j = -2 - sco; j <= 2 + sco; j++) {

				for (i = -2 - sco; i <= 2 + sco; i++) {
					if (moveColumn + i < 0 || moveColumn + i > 40 || moveRow + j < 0 || moveRow + j > 40) continue;
					if (j == 0 && i == 0)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "⊙", Gray, LightYellow);
					else if (map[moveRow + j][moveColumn + i] == 0)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "■", Gray, Black);
					else if (map[moveRow + j][moveColumn + i] == 1)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "  ", Gray, White);
					else if (map[moveRow + j][moveColumn + i] == 3)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "●", Gray, LightPurple);
					else if (map[moveRow + j][moveColumn + i] == 4)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓣ", Gray, LightBlue);
					else if (map[moveRow + j][moveColumn + i] == 5)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓗ", Gray, LightRed);
					else if (map[moveRow + j][moveColumn + i] == 6)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓢ", Gray, LightAqua);
				}
			}


		}

		if (clock() - starttime > 999 || times == 0) {
			if (hp < 0) {

				playWav(0, 0, 0, 0);
				return 0;
			}
			if (hptime <= 0) {
				hptime = 6;
				gotoPrint("string", 9 + hp * 2, 44, "□", Black, White);
				hp--;
			}
			else hptime--;
			gotoPrint("int", 68 - (int)log10((double)hptime), 44, &hptime, Black, White);


			starttime = clock();
			times++;
			gotoPrint("string", 43, 44, "  ", Black, LightRed);
			if (times > 90) {

				playWav(0, 0, 0, 0);
				return 0;
			}
			if (times > 70)
				gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, LightRed);
			else if (times > 50)
				gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, Yellow);
			else
				gotoPrint("int", 44 - (int)log10((double)times), 44, &times, Black, White);

			for (i = 1; i <= 41; i++)
				gotoPrint("string", 2, i, "　　　　                                  　　　　　　　　　 　　　　　 　　　　　", Black, White);
			for (j = -2 - sco; j <= 2 + sco; j++) {

				for (i = -2 - sco; i <= 2 + sco; i++) {
					if (moveColumn + i < 0 || moveColumn + i > 40 || moveRow + j < 0 || moveRow + j > 40) continue;
					if (j == 0 && i == 0)
						gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "⊙", Gray, LightYellow);
					else
						if (map[moveRow + j][moveColumn + i] == 0)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "■", Gray, Black);
						else if (map[moveRow + j][moveColumn + i] == 1)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "  ", Gray, White);
						else if (map[moveRow + j][moveColumn + i] == 3)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "●", Gray, LightPurple);
						else if (map[moveRow + j][moveColumn + i] == 4)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓣ", Gray, LightBlue);
						else if (map[moveRow + j][moveColumn + i] == 5)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓗ", Gray, LightRed);
						else if (map[moveRow + j][moveColumn + i] == 6)
							gotoPrint("string", 2 + moveColumn * 2 + 2 * i, 1 + moveRow + j, "ⓢ", Gray, LightAqua);
				}
			}
		}
	}

}
