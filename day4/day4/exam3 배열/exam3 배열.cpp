// exam3 배열.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nTot;
		double nAvg;
	int ages[5];
	scanf_s("%d %d %d %d %d", &ages[0], &ages[1], &ages[2], &ages[3], &ages[4]); //입력은 엔터오류로 힘듬
	nTot = ages[0] + ages[1] + ages[2] + ages[3] + ages[4];//규칙적이므로 루프문으로 가능

	for (int i = 0; i < 5; i++) {
		nTot += ages[i]; 
	}

	nAvg = (double)nTot / 5.0;

	printf_s("평균 : %0.2lf \n", nAvg);

    return 0;
}

