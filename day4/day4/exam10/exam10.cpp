// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main() 


//문자를 입력받고, 알파벳만 모두 *화 시키기.
{

	char word[32]; //처음에 길이 명시, 초기화를 안해주면 에러가 난다.

	printf("문자열을 입력해주세요 : ");
	scanf_s("%s", word, sizeof(word));
	
	/*
	printf_s("입력한 크기는 : %d \n", sizeof(word) / sizeof(word[0]));
	*/

	int nArray_size = sizeof(word) / sizeof(word[0]);
	

	for (int i = 0; i < nArray_size; i++) {
		/*
		if (word[i] == 0x00) { //널 찾으면 강제 종료.
			break;
		}
		*/


		//알파벳인지 아닌지 구분부터.

		if ((word[i] >= 65 && word[i] <= 90) ||  //대문자
			(word[i] >= 97 && word[i] <= 122)) //소문자. 조건을 다시 하나로 묶어준다.
		{
		
			word[i] = '*';
		}

		

	}


	
	printf_s("입력한 문자열은 : %s \n", word);





    return 0;
}

