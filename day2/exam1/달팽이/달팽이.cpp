// 달팽이.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"



int main()
{
	int height;
	int days;

	height = 0;
	days = 0;

	height = height + 55;

	while (height < 300) 
	
	{
		height = height - 13;
		days = days + 1;
		height = height + 55;
	}

	printf("몇 일 걸렸습니까? \n");
		printf("%d일입니다. \n", days);

    return 0;
}

