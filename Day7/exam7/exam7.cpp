// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


//맨끝에 합을 추가하기


int main()
{
	int score_ary[3][4] = { { 1,2,3,4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 } };

	int sum = 0;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++) {
			printf_s("%4d", score_ary[i][j]);
			
			sum = sum + score_ary[i][j];
		}
		printf_s("%4d", sum);
		printf_s("\n");
		sum = 0;
	}



return 0;
}

