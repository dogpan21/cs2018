// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void sum(int a, int b, int *c)
{
	//int c = a + b;
	//return c;

	*c = a + b;
}


int main() //함수에 어떤 값을 넣어서 다시 받아오고 싶을 때 = 포인터를 쓰는 핵심 사용처!!
{
	int c = 0;
sum(1, 2, &c);
	printf_s("%d\n", c);
    return 0;
}

