// exam 11-1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("한 개의 단을 입력하세요 :");
	int num = 0;
	scanf_s("%d", &num);
	int i = 1;

	while (i <= 9)
	{
		printf("%d * %d = %d \n", num, i, num*i);
		i++;
	}

	return 0;
}

