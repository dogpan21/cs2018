// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//반복문
	
	
		int nHeight = 0;
		int nDay = 0;

		do 
		{
			nHeight = nHeight + 55;
			nDay = nDay + 1;

			printf("%d일동안 %d 주파. \n", nDay, nHeight);
		} while (nHeight < 300);

	
    return 0;
}

