// exam12 오늘의 마지막.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()

	//abcde@dfsfddsfs@1234
    //abcde@*********@1234

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

		int nFSM = 0;//0 ->normal , 1 ->start
		for (int i = 0; i < nPoint; i++)
		{
			
			if (nFSM == 0)
			{
				if (word[i] == '@') 
				{ 
					nFSM = 1;
				}

				printf_s("%c", word[i]);
			}

			else if (nFSM == 1) 
			{
				if (word[i] == '@')
				{ 
					nFSM = 0;
					printf_s("%c", word[i]);
				}

				else

				printf_s("*");
			}
		}
	
		///마지막 골뱅이 이후로는 그대로
		for (int i = nPoint; i < nCount; i++)
		{

			printf_s("%c", word[i]);
		}






    return 0;
}

