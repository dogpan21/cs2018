// 190p exercise 6-4 2번.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()

{
	int a, b;
	char _op = '+';
	int nSolve = 0;

	printf("어떤 수식으로 계산할까요 :");
	scanf_s("%c", &_op, sizeof(_op));

	printf("계산하려는 두 수는 :");
	scanf_s("%d %d", &a,  &b);

	
	
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

	//scanf_s("%d%c%d", &a, &_op, &b, 4+4+1);

	printf("연산결과는 %d %c %d = %d 입니다. \n", a, _op, b, nSolve);




	return 0;
}

