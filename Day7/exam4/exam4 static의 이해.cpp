// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//count 입력시 count 명령어가 될 수 있도록

void count()
{
	int static a = 0;
	printf_s("a의 값은? : %d \n", a++);
}

void decount()
{
	static int a = 100;  //decount와 count의 a는 다르다!
	a--;
	printf("a의 값은? : %d \n", a);  //printf_s("a의 값은? : %d\n", a--); 
}

int main()
{
	printf_s("명령어 >");
	char szCmdBuf[32];
	while (1)
	{
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0) {
			break;
		}

		else if (strcmp(szCmdBuf, "count") == 0) {
			count();
			
		}

		else if (strcmp(szCmdBuf, "decount") == 0) {
			decount();

		}

		else {
			printf_s("%s는 처리할 수 없는 명령어 입니다. \n", szCmdBuf);
		}
	}

	printf_s("프로그램을 종료합니다! \n");

    return 0;
}

