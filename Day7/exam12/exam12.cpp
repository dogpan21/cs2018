// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h" //글자색 바꾸기


int main()
{
	printf_s("%c[%d;%dm \n", 0x1b, 1, 2);
	printf_s("hello \n");
	
    return 0;
}

