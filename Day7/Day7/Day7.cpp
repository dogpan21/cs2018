// Day7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{                                
	char _ch;
	printf_s("getchar로 입력받기 : "); //엔터필요

		_ch = getchar();
		putchar(_ch);

		printf_s("getch로 입력받기 :"); //엔터가 필요없다@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		_ch = _getch();
		putchar(_ch); 

		printf_s("추가적인 스트림 처리"); //네트워크 소켓 보내고 받기에 필수
		_ch = getchar();                   //직렬화. 시리얼라이제이션. 컴퓨터는하나하나 데이터를 받는다. c언어에서 데이터를 주고 받는 방식은 스트림이 중요하다.
		putchar(_ch);                    //프린트f는 단순히 스트림으로 보낸다. 그 다음 콘솔로 출력하라는거구나 반응함.

			printf_s("\n");

    return 0;
}

