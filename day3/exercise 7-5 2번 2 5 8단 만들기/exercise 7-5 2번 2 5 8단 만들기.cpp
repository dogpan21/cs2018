// exercise 7-5 2번 2 5 8단 만들기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	// 2 5 8단 만들기
	int a = 0;
	int b = 0;

	for (b = 1; b <= 9; b++) {

		for (a = 1; a <= 3; a++) {
		
				printf("%d * %d = %d \t", 3*a-1, b, (3 * a - 1) * b);
				
		}
		printf("\n");
	}


    return 0;
}

