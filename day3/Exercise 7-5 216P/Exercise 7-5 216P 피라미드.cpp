// Exercise 7-5 216P.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//피라미드 만들기
	int i;
	int t;
	for (i = 1; i <= 5; i++) {
		for(t = i; t > 0; t--) {
			
			printf("*");
			
		}
		printf("\n");
	}
	


	


	return 0;
}





