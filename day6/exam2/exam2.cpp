// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
int nums[5] = { 1, 2, 3, 4, 5 }; //char nums[5]로 할 경우, &nums의 값이 1바이트 씩 차이난다. 메모리의 최소 단위는 1바이트 이므로!
//배열은 주소를 쭉 나열한 것.

printf_s("%d\n%d\n%d\n%d\n%d\n", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
printf_s("%d\n%d\n%d\n%d\n%d\n", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]); //nums가 int 인티저형이기 때문에 각 주소 위치가 4씩 차이가 난다.

    return 0;
}

