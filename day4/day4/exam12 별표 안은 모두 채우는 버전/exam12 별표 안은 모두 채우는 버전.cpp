// exam12 별표 안은 모두 채우는 버전.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[300]; //처음에 길이 명시, 초기화를 안해주면 에러가 난다.

	printf("문자열을 입력해주세요 : \n");
	scanf_s("%s", word, sizeof(word));


	int nArray_size = sizeof(word) / sizeof(word[0]);

	int nCount = 0;

	for (int i = 0; i < nArray_size; i++) {
		if (word[i] == 0x00) {
			nCount = i;
			break;
		}


	}

	printf("문자열 크기 : %d \n", nCount);


	int nPoint = 0;
	//마지막 골뱅이 찾기
	for (int z = 0; z < nArray_size; z++)
	{
		if (word[z] == '@')
		{
			nPoint = z; //마지막 골뱅이위치
		}

	}

	///골뱅이작성

	int nFSM = 0;
	//0 ->문자출력 , 1 ->별표모드



	for (int i = 0; i < nPoint; i++)
	{

		if (word[i] == '@') //골뱅이 구간일때
		{
			printf_s("%c", word[i]);

			if (nFSM == 0)
			{
				nFSM = 1;
			}

			else //별표모드
			{
				nFSM == 0;
			}




		}

		else //일반단어
		{
			if (nFSM == 0)
			{
				printf_s("%c", word[i]);
			}

			else //별표모드
			{
				printf_s("%c", '*');
			}

		}





	}

	///마지막 골뱅이 이후로는 그대로
	for (int i = nPoint; i < nCount; i++)
	{

		printf_s("%c", word[i]);
	}


    return 0;
}

