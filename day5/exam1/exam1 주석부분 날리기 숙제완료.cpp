// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char strTemp[300]; //처음에 길이 명시, 초기화를 안해주면 에러가 난다.

	printf("문자열을 입력해주세요 : \n");
	scanf_s("%s", strTemp, sizeof(strTemp));

	
	int i;
	int nFSM = 0;

	for (i = 1; i < sizeof(strTemp); i++) {

		if (nFSM == 0) {
			if (strTemp[i] == '/' && strTemp[i+1] == '*') {
				nFSM = 1;
				
			}
			//strTemp[i] = ' ';
		}
		else if (nFSM == 1) {
			if (strTemp[i] == '*' && strTemp[i+1] == '/') {
				nFSM = 0;
			}

			strTemp[i] = ' ';
		}
		
		

	}

	printf_s("%s\n", strTemp);

	return 0;
}
