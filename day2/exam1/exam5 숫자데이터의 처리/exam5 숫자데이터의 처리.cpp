// exam5 숫자데이터의 처리.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num, num2;
	printf("이몽룡의 본봉과 보너스를 각각 입력하시오 : ");
	scanf_s("%d \n %d", &num, &num2);

	int total = num + num2;
	double tex = total * 0.09;
	printf("이몽룡의 실 입금액은 \n %lf만원입니다", total*0.91);

	//total * 0.91은 왜 안될까. lf로 하니까 바로 되네
    return 0;
}

