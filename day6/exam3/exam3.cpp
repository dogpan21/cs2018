// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() //각 데이터형 별로, 기억공간의 범위 확인하기.
{
	char ch;
	int num;
	double db;

	printf_s("%d %d %d\n", &ch, &num, &db); //11794615 11794600 11794584 책과는 값이 다르다. 주소를 일렬로 못가져오게, 보안책이 심어져있기 때문.




    return 0;
}

