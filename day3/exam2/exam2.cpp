// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf(" \x41  \n");
	// 1 + 16*4 = 65
	// 유니코드. 아스키 코드.
	printf("♭♩♪♬◆☆★◐◑○●◎⊙◈◇△▲▽▼□■◁◀▷▶◇◆♤♠♡♥♧♣ ");
	printf(" 부호 : %d, 부호없음:%u \n", -1, -1);

	printf(" 16을 각각 십진법 : %d, 팔진법 : %o, 16진법 %x \n", 16, 16, 16);

	printf("%x \n", '□');

	unsigned int a;
	unsigned char b; //0~255
	char c; //-128~127
	
	double _val = 0.0000000000001234;

	printf("pi : %lf, %le \n", _val, _val);

	printf(" %c %s \n", 'H', "Hello");



    return 0;
}

