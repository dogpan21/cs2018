// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
char cTileMap[64] = {
	1,1,1,5,8,1,1,1,//0
	1,2,1,0,0,1,7,1,//1
	1,0,1,0,0,1,0,1,//2
	1,0,0,0,0,0,0,4,//3
	1,1,1,0,0,0,0,4,//4
	1,0,0,0,0,0,0,1,
	1,6,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

const char *TileSet[] = {
	"  ", //0
	"▦", //1
	"♨", //2
	"▥", //3
	"▒", //4
	"〔 ", //5
	"♡", //6
	"ψ", //7
	" 〕", //8
	"㉦" //9
};

//플레이어 오브잭트 
int g_nPlayerPosX, g_nPlayerPosY;

int main()
{
	g_nPlayerPosX = 3;
	g_nPlayerPosY = 3;

	char szCmd[32];

	printf("=======================================♨준식의 미궁♨========================= \n");
	printf("\n");

	printf("=========================================== ver.Ⅸ =============================\n");
	printf("\n");
	printf("======================================== map server... on ======================\n");
	printf("\n");
	printf("======================================== chat server... on =====================\n");
	printf("\n");
	printf("======================================== char server... on =====================\n");
	printf("\n");
	printf("======================================== item server... on =====================\n");
	printf("\n");


	printf("\n");
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	//cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;
	char _tempBuf[64];

	for (int i = 0; i < 64; i++) {
		_tempBuf[i] = cTileMap[i];
	}
	//플레이어 출력
	_tempBuf[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf_s("%s", TileSet[_tempBuf[x + y * 8]]);
		}
		printf_s("\n");
	}
	printf("\n");

	while (1) {
		printf_s("이동할 방향을 입력하십시오 >");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("w", szCmd) == 0) { //위로 감
			g_nPlayerPosY--;
			//printf("플레이어가 %c쪽으로 이동했습니다.\n", szCmd);
		}
		else if (strcmp("s", szCmd) == 0) { //아래로 감
			g_nPlayerPosY++;
			//printf("플레이어가 %c쪽으로 이동했습니다.\n", szCmd);
		}
		else if (strcmp("a", szCmd) == 0) { //위로 감
			g_nPlayerPosX--;
			//printf("플레이어가 %c쪽으로 이동했습니다.\n", szCmd);
		}
		else if (strcmp("d", szCmd) == 0) { //위로 감
			g_nPlayerPosX++;
			//printf("플레이어가 %c쪽으로 이동했습니다.\n", szCmd);
		}
		printf("=======================================♨준식의 미궁♨========================= \n");
		printf("\n");

		printf("=========================================== ver.Ⅸ =============================\n");
		printf("\n");
		printf("======================================== map server... on ======================\n");
		printf("\n");
		printf("======================================== chat server... on =====================\n");
		printf("\n");
		printf("======================================== char server... on =====================\n");
		printf("\n");
		printf("======================================== item server... on =====================\n");
		printf("\n");


		printf("\n");
		printf("\n");

		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
			//cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;
			char _tempBuf[64];

			for (int i = 0; i < 64; i++) {
				_tempBuf[i] = cTileMap[i];
			}
			//플레이어 출력
			_tempBuf[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%s", TileSet[_tempBuf[x + y * 8]]);
				}
				printf_s("\n");
			}
		
		
	}

	return 0;
}


