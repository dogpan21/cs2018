// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h> //문자열 비교 함수
//simple REPL 기본형

int main()
{
	char szCmd[32];
	char cBufStack[256];
	int nStackPointer = 0;

	while (1)
	{
		printf("원하는 명령어를 타이핑하세요 : ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) //해당 ""단어가 맞는지 대조함.
		{
			printf_s("프로그램을 종료합니다.");
			break;
		}

		else if (strcmp("push", szCmd) == 0) { //push
			printf_s("데이터를 입력하세요 :");
			char _tmp;
			scanf_s("%c", &_tmp, 1);  //자기멋대로 엔터를 입력받음.

			scanf_s("%c", &_tmp, 1);
			printf_s("입력값 : %c \n", _tmp);
			cBufStack[nStackPointer] = _tmp;
			nStackPointer++;
		}

		else if (strcmp("pop", szCmd) == 0) { //pop 끝에서 하나를 떼낸다.
			nStackPointer--;
			printf_s("성공적으로 팝 했습니다. 스탯포인터 위치는 (%d) 입니다. \n, nStackpointer");

		}

		else if (strcmp("dump", szCmd) == 0) { //dump
			cBufStack[nStackPointer] = 0x00; //첫번째 방법. 
		

		
			printf_s("%s\n", cBufStack); //1.뒤에다 0을 만들기 2.스택포인트만큼 찍어주기 (쓰레기값 안만드는 방법)
			

			
		}



		else{
			printf_s("입력하신 커맨드는 %s 입니다. \n", szCmd);

		}
		



		printf("\n");
	}


	return 0;
}

