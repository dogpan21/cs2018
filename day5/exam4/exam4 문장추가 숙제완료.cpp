// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char szCmd[32]; //명령어 저장
	char cBuf[256];
	char trash[5];
 	int nHead = 0; //초창기에는 헤드와 테일이 같다. 끝
	int nTail = 0; //시작
	int nCount = 0;

	printf("커맨드를 입력해주세요 : ex(ins, del, dump, quit, compact)");

	while (1)
	{
		
		scanf_s("%s", &szCmd, sizeof(szCmd));
		printf("\n");

		if (strcmp("quit", szCmd) == 0) //해당 ""단어가 맞는지 대조함.
		{
			printf_s("프로그램을 종료합니다.");
			break;
		}

		/* //한글자씩 추가하는 원본
		else if (strcmp("ins", szCmd) == 0) {
			char _;
			scanf_s("%c", &_, 1);
			scanf_s("%c", &_, 1);
			cBuf[nHead++] = _;
		}
		*/


		
		else if (strcmp("ins", szCmd) == 0) //삽입
		{
			
			char _[50];
			scanf_s("%s", _, sizeof(_));
			scanf_s("%c", &trash, 1); //오류방지
			printf_s("입력한 문자열은 : %s \n", _);
			//scanf_s("%c", &_, 1); //오류방지
		
			for (int i = 0; i < sizeof(_); i++) {
				
				
				if (_[i] == 0x00) { //길이재기
					nCount = i;
					printf("문자의길이 %d \n", nCount);
					break;
				}


			}
			for (int i = nTail; i <= nCount; i++)
			{
				cBuf[i] = _[i]; //반드시 후열증가. 그래야 0부터 채워짐. 
				nHead++;
				
			}

			printf_s("입력한 문자열은 : %s \n", cBuf);
		}
		

		else if (strcmp("del", szCmd) == 0)
		{
			nTail++;
		}



		else if (strcmp("dump", szCmd) == 0) { //불러내기
			//
			for (int i = nTail; i < nHead; i++)
			{
				printf_s("%c", cBuf[i]);
			}
			printf_s("\n");
		}

		else if (strcmp("del", szCmd) == 0) {
			nTail++;
		}


		else if (strcmp("compact", szCmd) == 0) {
			int _len = nHead - nTail;
			for (int i = 0; i < _len; i++) {
				cBuf[i] = cBuf[nTail + i];
			}
			nTail = 0;
			nHead = _len;
		}

		else {

			printf("존재하지 않는 명령어 %s입니다. \n", szCmd);
		}

		printf_s("입력하신 커맨드는 %s 입니다. \n", szCmd);
		
	}


	return 0;
}



