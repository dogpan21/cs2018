// exam15 무한반복문.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char cmd;

	while (1) {
		scanf_s("%c", &cmd, 1);

		printf("입력하신 명령어는 %c 입니다. \n", cmd);
		if (cmd == 'q')
			break;
	}

	printf("종료합니다. \n");
    return 0;
}

