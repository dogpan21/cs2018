// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() ///413페이지
{
	int *ptr_ary[3];
	int ary1[4] = { 1, 2, 3, 4 };
	int ary2[4] = { 5, 6, 7, 8};
	int ary3[4] = {9, 10, 11, 12 };

	ptr_ary[0] = ary1;
	ptr_ary[1] = ary2;
	ptr_ary[2] = ary3;

	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			//printf_s("%4d", ptr_ary[j][i]);
			//printf_s("%4d", (*(ptr_ary + i))[j]);
			printf_s("%4d", *(*(ptr_ary+i)+j));
		}
		printf_s("\n");
	}


	printf_s("%4d%4d\n", ptr_ary[1][4], ptr_ary[1][5]);
    return 0;
}

