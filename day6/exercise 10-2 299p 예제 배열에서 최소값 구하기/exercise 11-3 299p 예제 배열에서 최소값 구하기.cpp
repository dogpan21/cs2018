// exercise 10-2 299p 예제 배열에서 최소값 구하기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double mini(double *ary)
{
	double _min = 9999999;

	for (int i = 0; i < 5; i++) {
		if (_min > ary[i]) {
			_min = ary[i];
		}
	}
	return  _min;
}

int main()
{
	double ary[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	printf_s("%lf \n", mini(ary));

    return 0;
}

