// 190p exercise 6-4 2번.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()

{
	//왜 순서를 바꾸면 오류가 날까?
	int a = 0;
	int b = 0;
	char _op = '+';
	int nSolve = 0;

	printf("어떤 수식으로 계산할까요 :");
	scanf_s("%c", &_op, sizeof(_op));

	printf("계산하려는 두 수는 :"); //숫자를 입력할때 엔터처리가 제대로 되지 않음.
	scanf_s("%d %d", &a, &b);


	//여기다가 다시 문자 추가해도 오류발생.
	//scanf 단순한 연습용. 

	
	
	switch (_op)
	{
	case '+':
		nSolve = a + b;
		break;

	case '&': //and
		nSolve = a & b;
		break;

	case '|': //or
		nSolve = a | b;
			break;

	case '-':
			nSolve = a - b;
			break;

	case '*':
		nSolve = a * b;
		break;

	case '/':
		nSolve = a / b;
			break;

	case '%':
		nSolve = a % b;
		break;

	default:
		break;

	}

	//

	printf("연산결과는 %d %c %d = %d 입니다. \n", a, _op, b, nSolve);




	return 0;
}

