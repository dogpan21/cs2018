// exam8 문자배열.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	
	//char word[] = { 'l', 'o', 'v', 'e', '\x00'};
	char word[] = { 'love' }; //아래나 위나 똑같다. 자동으로 널값까지 마무리함.

	int nSize = sizeof(word) / sizeof(word[0]);
	for (int i = 0; i < 4; i++) {
		printf_s("%c", word[i]);
	}

	printf_s("\n");

    return 0;
}

