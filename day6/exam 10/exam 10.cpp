// exam 10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{


	char *fruit = (char *) "strawberry"; //좌측 주소는 바꿀 수 있으나, 오른쪽 밸류를 바꿀 수는 없음.
	char fruit2[] = "strawberry";
	printf_s("%s \n", fruit);

	printf_s("%s \n", fruit + 2);
	printf_s("%s \n", &fruit[2]);

	fruit2[3] = 'o';
	printf_s("%s \n", fruit2);

    return 0;
}

