// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() //배열명은 포인터!!
{
	int ary[5] = { 10, 20, 30, 40, 50 }; //[0, 1, 2, 3, 4] 칸
	int *ap;
	ap = ary;

	for (int i = 0; i < 5; i++) {
		//printf_s("%d \n", *(&ary[0]+ i)); //컴파일러가 int를 인식해서 자동으로 4씩 증가한다. *을 빼면 주소들이 나옴.
		//printf_s("%d \n", ary[i]);
		//printf_s("%d \n", *(ary + i));

		printf_s("%d \n", *(ap + i)); //모두다 똑같은 값이다. 똑같이 10~50을 출력한다.
		printf("\n");
	}

	ap = &ary[2]; //3칸부터 시작합니다.
	for (int i = 0; i < 3; i++) {
		printf_s("%d \n", *(ap + i)); //3칸부터 차근차근 증가합니다.
	}

    return 0;
}

