// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 1,2,3,4,5 }; //배열이 가르키는 주소는 변할 수 없다, 포인터가 가르키는 주소는 변할 수 있다.

	int *ap = ary;

	printf_s("%d \n", *(ap + 2));
	printf_s("%d \n", ap[2]);

	// ary = ap + 2; - 이렇게 쓰면 안됨. 
	ary[0] = 6;
	printf_s("%d \n", *(ary + 0));
    return 0;
}

