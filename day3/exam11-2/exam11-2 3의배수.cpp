// exam11-2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("\n <while문으로 하기> \n");
	int i = 1;
	int sum = 0;

	while (i <= 100) {
		if ((i % 3) == 0) {
			printf("3의 배수 : %d\n", i);
			//sum += i; 누적
			sum = sum + i;
		}
		
		i++;
	}

	printf("3의 배수들의 합은 %d이다. \n", sum);

	////////////////////////////////////////////////////
	////////////////////////////////////////////////////

	printf("\n<for문으로 하기> \n");

	int a = 1;
	int sum1 = 0;

	for (a = 1; a <= 100; a++) {
		if ((a % 3) == 0) {
			printf("3의 배수 : %d\n", a);
		
			sum1 = sum1 + a;
		}
	}


	printf("3의 배수들의 합은 %d이다. \n", sum);







	return 0;
}


