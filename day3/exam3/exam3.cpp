// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("%10d\n", 1234);

	int a = 10;
	double b = 3.0;

	double c = a / b;

	printf("%lf\n", c);
	printf("%10lf\n", c);

	printf("%0.2lf\n", 3.141592);

	printf("%s######\n", "Hello");
	printf("%10s######\n", "Hello");
	printf("%-10s######\n", "Hello");




    return 0;
}

