// exercise 10-2 299p 예제.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void line_up(double *a, double *b, double *c)
{
	double *max, *mid, *min;

	if (a < b)
	{
		if (b < c)
		{
			a = c;
			b = b;
			c = a;
		}

		if (b > c)
		{
			a = b;
			if (a > c)
			{
				b = a;
				c = c;
			}

			if (a < c)
			{
				b = c;
				c = a;
			}



		}





	}



	if (a > b)
	{
		if (b > c)
		{
			a = a;
			b = b;
			c = c;
		}

		if (b < c)
		{
			c = b;

			if (a > c)
			{
				a = a;
				b = c;
			}
		}
	}


}

int main()
{
	double max, mid, min;

	printf("숫자 세 개를 입력하세요 : ");
	scanf_s("%lf %lf %lf", &max, &mid, &min);

	line_up(&max, &mid, &min);
	printf("큰 수부터 차례로 출력하면 : %lf, %lf, %lf \n", max, mid, min);
    return 0;
}

