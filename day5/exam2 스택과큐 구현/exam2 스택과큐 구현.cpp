// exam2 스택과큐 구현.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h> //문자열 비교 함수
//simple REPL 기본형

int main()
{
	char szCmd[32];

	while (1) 
	{
		printf("원하는 단어를 타이핑하세요 : ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) //해당 ""단어가 맞는지 대조함.
		{
			printf_s("프로그램을 종료합니다.");
			break;
		}


			printf_s("입력하신 커맨드는 %s 입니다. \n", szCmd);
			printf("\n");
	}

	
    return 0;
}

