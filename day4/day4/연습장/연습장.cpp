// 연습장.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//골뱅이가 두개일때
	//abcde@dfsfddsfs@1234
	//abcde@*********@1234

	{

		char word[50]; //처음에 길이 명시, 초기화를 안해주면 에러가 난다.

		printf("문자열을 입력해주세요 : ");
		scanf_s("%s", word, sizeof(word));


		int nArray_size = sizeof(word) / sizeof(word[0]);


		//골뱅이 큰그림 





		int sPoint1 = 0; //첫좌표
		int sPoint2 = 0; //두번쨰 좌표

		for (int i = 0; i < nArray_size; i++) { //첫좌표 저장

			if (word[i] == 64)
			{
				sPoint1 = i;
				break;
			}


		}

		for (int i = sPoint1 + 1; i < nArray_size; i++) { //두번째 좌표저장

			if (word[i] == 64)
			{
				sPoint2 = i;
				break;
			}

		}

		for (int i = sPoint1 + 1; i < sPoint2; i++) { // 해당 좌표 사이 자동변환

			word[i] = '*';
		}





		printf_s("입력한 문자열은 : %s \n", word);


    return 0;
}

