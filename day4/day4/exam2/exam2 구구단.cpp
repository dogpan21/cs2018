// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void output_gugudan(int nDan)
{
	int a;
	for (a = 1; a <= 9; a++) {
		printf("%dx%d=%d \n", nDan, a, nDan*a); //내가 만든것
		//printf_s("%d * %d \n", a, nDan); //선생님이 보여주신 것. 
	}
}


int main()
{
	int dan;
	for (dan = 1; dan <= 9; dan++) {
		output_gugudan(dan);
		printf("\n");
	}
    return 0;
}

