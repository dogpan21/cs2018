// day6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() //주소연산자
{
	int num;
	int *ptr; //주소값. 
	num = 3;
	ptr = &num;

	printf_s("%d %d \n", num, &num); //참조 연산자

	printf_s("%d %d \n", *ptr, ptr); //포인터 연산자. 3 /13629856 . *ptr은 주소에 저장된 값. ptr은 주소 위치 그 자체.

	*ptr = 5;
	printf_s("%d %d \n", *ptr, ptr); //주소값은 변화가 없다. 건들지 않으면 다 똑같음.
	printf_s("%d %d \n", num, &num); 


	int address;
	scanf_s("%d", &address); //주소 입력
	printf_s("%d %d\n", address, *((int *)address)); //(int*) 포인터형 변수로 타입캐스팅 / *() 그 안의 값을 가져와라.
	//주소 내용보기. 13893160 입력시 -> '5'가 나옴.



    return 0;
}

