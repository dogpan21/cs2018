// exercise 알파벳 개수 다 세기.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32]; //처음에 길이 명시, 초기화를 안해주면 에러가 난다.

	printf("문자열을 입력해주세요 : ");
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	printf_s("입력한 크기는 : %d \n", sizeof(word) / sizeof(word[0]));

	int nCount = 0;
	int nArray_size = sizeof(word) / sizeof(word[0]);
	int nCount_alpah = 0;

	for (int i = 0; i < nArray_size; i++) {
		if (word[i] == 0x00) {
			break;
		}
		
		if ((word[i] >= 65 && word[i] <= 90) ||  //대문자
			(word[i] >= 97 && word[i] <= 122)) //소문자. 조건을 다시 하나로 묶어준다.
		{
			nCount_alpah++;
		}


		nCount++;
	}

	printf_s("입력한 단어길이는 : %d \n", nCount);
	printf_s("알파벳의 수 : %d \n", nCount_alpah);

	
	printf("단어를 뒤집으면");
	for (int t = nCount; t >= 0; t--) {
		printf("%c", word[t]);
	}
	printf("\n");





    return 0;
}

