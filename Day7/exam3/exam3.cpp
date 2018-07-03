// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void count()
{
	int a = 0;
	a++;
	printf_s("count %d \n", a);
}

void count2()
{
	static int a = 0; //지역적으로 쓰이긴하지만, 메모리 공간에 할당을 한다.
	a++;
	printf_s("count2 %d\n", a);
}

void count3(int a)
{
	a++;
	printf_s("count3 %d\n", a);
}

void pCount(int *a)
	{
	(*a)++; //괄호 안치면 연산자 우선순위 때문에 쓰레기값이 된다. -324243242이런거/ 우리가 증가시키려는건 *a잖아?
	printf_s("pCount %d\n", *a);


	}


int main()
{
	count();
	count();

	count2();
	count2();

	int a = 0;
	count3(a);
	count3(a);

	pCount(&a);

	pCount(&a);

    return 0;
}

