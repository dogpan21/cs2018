// 과제 피라미드 재도전.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"



int main()
{
	//피라미드 만들기
	int i; //층
	int t; // 빈칸
	int c; // 별
	for (i = 1; i <= 5; i++) { //층 1층씩 오른다.
		for (t = 5 - i; t > 0; t--) { //좌측 빈칸 채우기. 

			printf(" ");

		}

		for (c = i; c > 0; c--) { //층수만큼 별박기
			printf("*");
		}
		for (c = i; c > 0; c--) { //층수만큼 다시 별박기
			printf("*");
		}
		for (t = 5 - i; t > 0; t--) { //우측 빈칸 채우기. 

			printf(" ");

		}

		printf("\n"); //한층 올린다

	}
		return 0;
	}
