// exam6 이차원 배열.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*
1 4 7 10
2 5
3 6                    1234 5678 9 10 11 12 3n-2 3n-1 3n
*/  
int main()
{

	int num[4][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int num2[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//3개씩 4묶음
	{

	
	int i, j;
	for (i = 0; i< 3; i++)
	{    
		for (j = 0; j < 4; j++) {
			printf_s("%4d", num[i][j]);
		}
		printf_s("\n");
	}


	}


	{
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf_s("%4d")
			}
		}
	}







    return 0;
}

