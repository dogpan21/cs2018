// exercise 6-3 1번.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("문자를 입력하세요 :");
	char cGender = 'c';
	scanf_s("%c", &cGender);

	if (cGender == 'm' or cGender == 'f')
		if (cGender == 'm')
			printf("남자입니다.");
		else
			printf("여자입니다.");


	else
		printf("잘못 입력하였습니다.");



    return 0;
}

