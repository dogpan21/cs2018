// exercise 9-2 배열의 데이터를 처리하는 프로그램.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int ary[] = { 2, 8, 15 ,1 ,8 ,10, 5, 19, 14, 16, 15, 15, 6, 7, 1, 4, 7, 8, 4, 1, 2, 3, 9, 8, 15, 20, 19, 11, 13, 12 };
	int nCount = 0;

	printf("배열 ary의 총 개수는 %d \n", sizeof(ary)/sizeof(ary[0]) );

	//20 안 넘나 검증하기. 최초 입력이 필요하므로 do while
	int seek = 1;
	do 
	{
		printf("찾기를 원하는 숫자를 입력하세요(1~20) : ");
		
		scanf_s("%d", &seek);

		if (seek > 20)
		{
			printf("숫자가 20을 넘었습니다. 다시 입력해주세요. \n \n");
		}

	} while (seek > 20);

	// 대조해가며 찾기
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
	{
		if (ary[i] == seek)
		{
			nCount = nCount + 1;
		}
		
	}
	

	printf("ary배열에서 찾는 숫자 %d는 %d개 있습니다!", seek, nCount);
	

    return 0;
}

