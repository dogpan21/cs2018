// exam14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() //357p 이해. 디버그로 확인해보는 연습!!!
{
	char szBuf[8];

	for (int i = 0; i < 8; i++) {
		szBuf[i] = getchar(); //getchar는 엔터를 치는 순간 스트링 버퍼에서 하나씩 하나씩 받아온다.


		printf("%s \n", szBuf);

			return 0;
	}
}

