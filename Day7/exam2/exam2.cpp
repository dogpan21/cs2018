// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//변수가 여기있으면 전국구

int main()
{
	// 이 안에 있으면 지역구
	int a = 1;
	{
		//더 들어오면 소단위
		int a = 2;
		printf_s("%d \n", a);


	}

	{
		int a = 3;
		printf_s("%d \n", a);
	}
	printf_s("%d \n", a); //해당 지역구를 나오면 그 지역의 a값을 따른다, 자동변수

    return 0;
}

