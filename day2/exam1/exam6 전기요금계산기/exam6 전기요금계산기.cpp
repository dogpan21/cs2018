// exam6 전기요금계산기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double use;
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf_s("%lf", &use);
	double total = 660 + use*88.5; //전체 요금
	double tax = total * 0.09; //세금
	
	printf("전기 사용 요금은 %lf원입니다.", total + tax);
    return 0;
}

