// exam12 주요 문자열 처리 함수.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h> ////이걸 해줘야 확장팩 함수가 뜬다! 341p


int main()
{
	const char *str1 = "apple";

	char buf[64];

	strcpy_s(buf, 64, str1);

	printf_s("%s \n", buf);

	printf_s("%d \n", strnlen_s(buf, sizeof(buf)));

	printf_s("같은 문자열 일때 : | %d \n", strcmp("cat", "cat")); //345페이지 참조.
	printf_s("다른 문자열 일때 : | %d \n", strcmp("cat", "bat"));
	printf_s("다른 문자열 일때 : | %d \n", strcmp("cat", "dog"));

	
    return 0;
}

