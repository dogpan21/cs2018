// exam6 배열의 크기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nums[] = { 1, 2 ,3, 4, 5, 6, 7, 8, 9 };

	// int int_size = sizeof(nums[0]);
	int array_size = sizeof(nums) / sizeof(nums[0]);

	for (int i = 0; i < array_size; i++)
	{
		printf_s("%5d", nums[i]);
	}

	printf_s("\n");


		return 0;
}

