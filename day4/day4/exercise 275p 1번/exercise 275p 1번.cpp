// exercise 275p 1번.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	//배열명 ary

	double ary[5];
	
	printf("배열명 ary \n");
	printf("첫번째 배열요소 %lf \n", ary[0]);
	printf("마지막 배열요소의 자료형 : double \n");
	printf("배열요소의 개수 : %d \n", sizeof(ary) / sizeof(ary[5]));
	printf("사용 가능한 첨자의 범위 \n");
		printf("배열의 크기 : %d \n", sizeof(ary));

    return 0;
}

