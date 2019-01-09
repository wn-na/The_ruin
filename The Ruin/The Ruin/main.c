#include "GameFile.h"

int main() {
	int type;
	uchar stage = 0;

	eraseCur();

	system("Title Ruin");
	srand((unsigned)time(NULL));

	setFont(L"µ¸¿òÃ¼", 12);

	while (1) {
		type = showTitle();
		if (type == 1) exit(0);
		while (1) {
			printScript(stage, &stage);
			stage++;
			if (stage == 5) {
				srand((unsigned)time(NULL));
				stage = 0;
				break;
			}
		}
	}
}