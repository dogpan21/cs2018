// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h> 

int main()
{
	char szCmd[32];
	char cBuf[256];
	int nLength = 0;

	// add 문자열을 버퍼에 입력
	// del 특정 위치 문자 삭제
	// ins 특정위치 문자 삽입

	while (1)
	{

		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) //해당 ""단어가 맞는지 대조함.
		{
			printf_s("프로그램을 종료합니다.");
			break;
		}

		else if (strcmp("add", szCmd) == 0) //입력받은 문자열을 
		{
			char _[32];
			char __;
			scanf_s("%c", &__, 1);
			scanf_s("%s", &_, sizeof(_));
			char _add_size = 0;

			//사이즈 구하기
			for (int i = 0; i < sizeof(_); i++)
			{
				if (_[i] == 0x00) break;
				_add_size++;
			}
			//카피
			for (int i = 0; i < _add_size; i++)
			{
				cBuf[i + nLength] = _[i]; //차곡차곡 쌓인다
			}


			printf_s("%s을 추가했습니다. \n", _);


		}

		else if (strcmp("dump", szCmd) == 0) {
			//
			for (int i = 0; i < nLength; i++)
			{
				printf_s("%c", cBuf[i]);
			}

			printf_s("\n");

		}

		else if (strcmp("del", szCmd) == 0)
		{
			char _;
			scanf_s("%c", &_, 1);



			printf("몇 번째 단어를 지울까요 :"); //입력을 받으면 특정위치에서 삭제
			int nPos;
			scanf_s("%d", &nPos);

			for (int i = nPos; i < nLength - 1; i++)
			{
				cBuf[i] = cBuf[i + 1];
			}
			nLength--;
		}

		else if (strcmp("ins", szCmd) == 0)
		{
			char _;
			scanf_s("%c", &_, 1);



			printf("몇 번째 순서에 넣을까요? :"); //
			int nPos;
			scanf_s("%d", &nPos);

			for (int i = nPos; i < nLength + 1; i++)
			{
				cBuf[i + 1] = cBuf[i];
			}


}







		else
		{ 
		printf_s("입력하신 커맨드는 %s 입니다. \n", szCmd);
		}
	}









    return 0;
}

