// exercise5-3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int guk = 0;
	int eng = 0;
	int math = 0;
	//char name[10];
	
	
		printf("국어, 영어, 수학 점수를 각각 입력하시오(빈칸으로 구분합니다.) :");
		scanf_s("%d %d %d", &guk, &eng, &math);
		
		printf(":----------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("----------:\n");

		printf(":   이름   :");
		printf("  국어  :");
		printf("  영어  :");
		printf("  수학  :");
		printf("  총점  :");
		printf("   평균   :\n");

		printf(":----------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("----------:\n");

		int final = guk + eng + math;
		double avg = (double)final / 3;
		printf(":  이준식  :");
		printf("%8d:", guk);
		printf("%8d:", eng);
		printf("%8d:", math);
		printf("%8d:", final);
		printf("%10.2lf:\n", avg);

		printf(":----------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("--------:");
		printf("----------:\n");




	return 0;
}

