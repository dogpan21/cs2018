// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char string[80];
	printf("글자를 최대 자유롭게 입력해보세요 : ");
	scanf_s ("%s", string);
	printf("입력한 글자가 다음이 맞나요?  %s", string);
	
    return 0;
}

