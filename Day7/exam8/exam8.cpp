// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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

	char animal[5][16];
	int animal_num = 0;

	printf_s("명령어 >");
	char szCmdBuf[32];
	while (1)
	{
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0) {
			break;
		}

		else if (strcmp(szCmdBuf, "add") == 0) {
			printf_s("어떤 짐승을.. >");
			gets_s(animal[animal_num], 16);
			animal_num++;
			printf("\n");

		}

		else if (strcmp(szCmdBuf, "list") == 0) {
			printf_s("소유하신 짐승들은... >");
			for (int i=0; i < animal_num; i++) {
				printf_s("%8s", animal[i]);
				
			}
			printf("\n");
		}

		else if (strcmp(szCmdBuf, "del") == 0) {
			printf_s("%s 판매완료.. >", animal[animal_num-1]);
			//gets_s(animal[animal_num], 16);
			animal_num--;
			printf("\n");
		}

		else {
			printf_s("%s는 처리할 수 없는 명령어 입니다. \n", szCmdBuf);
		}
	}

	printf_s("프로그램을 종료합니다! \n");

	return 0;
}

