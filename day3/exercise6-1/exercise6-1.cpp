// exercise6-1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("절대값을 구하고 싶은 정수를 입력하시오 :");
	int num = 0;
	scanf_s("%d", &num);

	if (num > 0)
		printf("구하는 절대값은 바로 %d입니다. \n", num);
	else
		printf("구하는 절대값은 바로 %d입니다. \n", -num);

    return 0;
}

