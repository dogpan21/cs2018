// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() //exam9 문자상수열 331p
{
	char str[80] = "dream"; //80자리 확보
	char str2[] = "dream"; //딱, 6자리만 확보
	const char *str3 = "dream3"; //미묘하게 다 똑같은 명령어
	char *str4;
	//str3[0] = 'd';
	printf_s("%s \n", str3);

	str2[0] = 'D';
	//str2 = str1; 왜 안될까? = 거꾸로라서. 오늘의 핵심===========================================
	str3 = str2;
	str3 = str;
	str4 = (char *)str3; //타입캐스팅을 하여, 다른 형이지만 앞에 넣어준다.
	str4[0] = 'D';

	printf_s("%s \n", str3);


    return 0;
}

