// exercise 9-1 261p 가장 큰 배열요소 값 찾기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nums[5];
	

	printf("다섯 개의 숫자를 입력하세요 :");
	scanf_s("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
	int nMax = nums[0];

	for (int i = 1; i < 5; i++) {
		if (nMax > nums[i])
		{

		}
		else
		{
			nMax = nums[i];
		}
	}


	printf("가장 큰 값은 %d입니다. \n", nMax);
	
    return 0;
}

