// exercise 6-2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("나이를 입력하세요 :");
	int age;
	scanf_s("%d", &age);
	printf("\n");

	if (age <= 6 || age >=70)

		printf("무료입장입니다. \n");

	else
	printf("입장료는 3000원입니다. \n");

	
    return 0;
	
}

