// exercise 5-2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a = 0;
	int b = 0;
	

	printf("두 정수를 입력하세요 :");
	scanf_s("%d %d", &a, &b);

	printf("\n");
    printf("=====================================\n");
	printf("        나눗셈 연산식은              \n");
	printf("=====================================\n");


	double end = (double) a / b;
	printf("=====================================\n");
	printf("      \"%d / %d = %lf\"입니다.       \n", a, b, end);
	printf("=====================================\n");
    return 0;
}

