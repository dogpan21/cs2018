// exercise 11-3 변형 최대값 찾기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double getMax(double *ary, int nLength)
{
	double _max = -9999999; //큰 값을 찾기 위해, 일단 작은 값으로 임시 값을 설정한다!!!

	for (int i = 0; i < nLength; i++) {
		if (_max < ary[i]) {
			_max = ary[i];
		}
	}
	return  _max;
}

int main()
{
	double ary[] = { 1.5, 20.1, 16.4, 2.3, 3.5, 0.7, 0.9 , 0.3 };
	printf_s("%lf \n", getMax(ary, sizeof(ary)/sizeof(double)));

	return 0;
}
