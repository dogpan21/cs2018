// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void user_strvpy(char *des, const char *src) //원문이 변하면 안되므로 const
{
	while (*src != '\0') { //널문자를 만날때까지 돌아감.
		*des = *src;
		src++;
		des++;
	}
	*des = 0x00; //널문자가 안들어갔으므로 마지막에 넣어줌.
}

int main()
{
	char str[80];

	
	user_strvpy(str, "strawberry"); //반복문으로 문장 넣기.
	//str = "strawberry"; c언어에서는 이것이 되지 않는다. 다른 언어와 다르게. 굳이 하고 싶다면 반복문으로 복사.
	printf_s("%s \n", str);

    return 0;
}

