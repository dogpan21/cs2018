// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//void ary_prn(int *ap) =========================================== 가장 많이 쓰는 방법=======================================================
//void ary_prn(int ap[])
void ary_prn(int ap[5])
{
	printf_s("%d \n", sizeof(ap)); //포인터만 써서는 함수에서는 해당 배열의 총 바이트 크기를 절대 알 수 없다. 껍데기만 받아오는 것이므로.
	for (int i = 0; i < 5; i++) {
		printf_s("%d  ", ap[i]);
	}


	printf_s("\n");
}


int main()
{
	int ary[5] = { 10, 20, 30, 40, 50 };

	printf_s("%d \n", sizeof(ary));              //sizeof는 해당 변수의 바이트 크기를 가져온다.
	ary_prn(ary);

    return 0;
}

