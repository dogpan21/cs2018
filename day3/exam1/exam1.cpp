// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int cm;
	int cf;
	int kg;
	int kr;
	printf("cm를 입력하세요. :");
	scanf_s("%d", &cm); 

	printf("현재 온도를 입력하세요. :");
		scanf_s("%d", &cf);

		printf("현재 무게를 입력하세요. :");
		scanf_s("%d", &kg);


		printf("현재 한화를 입력하세요 : ");
		scanf_s("%d", &kr);

		printf("\n");

		printf("==============================================================\n");
		printf("                       보고서                                 \n");
		printf("==============================================================\n");
	
	printf("%d cm는 \n%lf피트 입니다. \n", cm, cm*
		0.083333);
	printf("%d cm는 \n%lf인치 입니다. \n", cm, cm*
		0.393701);
	printf("%d cm는 \n%lf리 입니다. \n", cm, cm*
		0.000025);
	printf("%d cm는 \n%lf마일 입니다. \n", cm, cm*
		6.2137e-6);
	printf("%d cm는 \n%lf야드 입니다. \n", cm, cm*
		0.010936);

	printf("\n");
	printf("%d c는\n화씨 %lf F  입니다. \n", cf, cf*
		1.8 + 32);

	printf("\n");
	printf("%d kg는\n%lf 파운드(lb)  입니다. \n", kg, kg*
		2.204623);

	printf("\n");
	printf("%d kr는\n%lf 유로(EUR)  입니다. \n", kr, kr*
		1302.21);
	

    return 0;
}

