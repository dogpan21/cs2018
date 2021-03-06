// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma comment(lib, "winmm.lib")





int g_nCurrentPos = 1; //1번방부터 시작한다.
int cHp = 30; //체력
int cAtk = 1; //공격력 // 서리한8;  링크의 검 3;
int cDef = 1; //방어력 // 도란의 방패 3;
int bHp; //보스체력 //트롤20 파수견30

const char *strpWorldArea[32] = {
	"수호자: 너는 도달해서는 안 되는 곳에 도착했구나... \n 돌아가라... 너무...늦기 전에...\n ???: 아직도 이 검을 지키려고 하는건가 ? \n 수호자 : 아니... 너를 지키려는 것이다.이 검으로부터...! \n \n(w : 수호자의 말을 듣고 순순히 돌아간다. s : 왕위를 계승한다. a : 시공으로 갈 준비가 되었습니다.우서를 껴안습니다.)", //0번방 설명
	"큰방 한가운데 작은 탁자가 놓여있고 북쪽과 동쪽에 문이있다 \n 서쪽에는 기나긴 통로가 있다. 남쪽 문은 다가가지 않는게 좋을 듯 하다.", //1번방 설명
	"방에 들어오니, 북쪽에 출구가 보인다. 하지만 무섭게 생긴 개가 지키고있다.  \n 남쪽으로 가면 원래 방으로 돌아갈 수 있다.",   //2번방 설명
	"작은 정원 같은 곳이다. 누군가 파티를 했던 흔적이 남아있다. 동쪽 문에는 '창고'라고 적혀있다. \n 남쪽에는 개가 좋아할만한 뼈다귀들이 지저분하게 널부러져 있다. 서쪽으로 가면 원래 방으로 돌아갈 수 있다.", //3번방 설명
	"메스꺼움을 참고, 잔해를 뒤졌더니 쓸만한 뼈들을 구했다. 이제 어떻게 할까?\n \n d : 어딘가 쓸 곳이 있을 것 같다. 소지한다.   a : 뼈갑옷을 만든다.(방어력+1) \n s : 워트의 의족을 만든다.(There is no cow level)   w : 아무 일도 하지않고, 그냥 방을 나간다. ", //4번방 설명.
	"검을 줍는 방이다", //5번방 설명
	"커튼을 젖히니, 서쪽으로 기나긴 일자형 통로가 계속되고 있다. 다른 길은 없다. \n  통로의 끝에는 거대한 어두운 그림자가 보인다. 이제 어떻게 할까? (a: 돌파한다/ d : 다시 돌아간다)", //6번방 설명
	"방의 중앙에 거대한 트롤이 있다. 들고 있는 방패가 쓸만해 보인다. \n 다행히 아직 나를 눈치채지는 못했다. 어떻게 할까? \n(a: 기습한다/d: 아직 난 준비가 안됐다)", //7번방 설명
	"다행히 지금 개는 자고 있다. 남쪽으로 조용히 다시 나갈까. \n 아니면 위험을 감수하고, 개가 지키는 북쪽 문으로 탈출해볼까. ", //8번방 설명
	"출구에 도착했다. \n 수고하셨습니다.\n w : 나간다 s : 나간다 a : 나간다 d : 나간다", //9번방 설명
	//여기부터는 이벤트
	"", //10번방 설명
	"", //11번방 설명
	"",//12 서리한 이벤트
	"트롤과 교전 시작", //13
	"", //14
	"", //15
	"", //16
	"당신의 근처에 가자, 경비견은 바로 눈을 떴다. 방 절반을 가리는 녀석의 거대한 덩치에 등골이 서늘해진다. \n 그래도 태생이 개라 혹시 나의 말을 듣지는 않을까? \n w: 내게 말을 듣게 할 물건이 있다. s: 도망쳐본다. d: 싸운다. a: 죽는다. ", //17
	"", //18
};

int g_wayTable[32][4] = { //맵테이블   []방의 갯수 []해당 방커맨드 동서남북 0123
	{ -1,32,12,1 }, //더미 0번방
	{ 3,6,0,2 },//동서남북. 1번방     //시작의 방
   { -1,-1,1,8 }, //동서남북. . 2번방 // 출구가 있는 방. 9번 북쪽 경비견 이벤트
   { 5,1,4,-1 }, //동서남북. . 3번방 //작은 정원. 10번 서쪽 뼈다귀이벤트
{ 14,15,16,3 }, //동서남북. . 4번방 //뼈다귀 줍기
{ -1,3,-1,-1 }, //동서남북. . 5번방// 검줍기
{ 1,7,-1,-1 }, //동서남북. . 6번방 //통로
{ 6,13,-1,-1 }, //동서남북. . 7번방//트롤 13트롤전투이벤트.
{-1,-1, 2, 17 } ,//동서남북. . 8번방 //경비견 커맨드
{ 20,20, 20, 20 }, //동서남북. . 9번방 출구이벤트.

//여기부터는 이벤트
{ }, //10번방
{}, //11번방
{}, //12번방/ 서리한 이벤트
{}, //13트롤 이벤트
{}, //14뼈다귀 이벤트. 소지
{}, //15뼈다귀 이벤트. 뼈방패
{}, //16뼈다귀 이벤트. 워트의 의족
{19, 19, 19, 18}, //17경비견 조우이벤트. 
{-1, -1, -1, -1}, //18경비견 전투이벤트.
{ -1, -1, -1, -1 }, //19경비견 전투.
{ -1, -1, -1, -1 }, //20
};

char cTileMap[64] = { //1번이 스타트지점 //지도타일맵
	0,0,0,0,9,0,0,0,//0
	0,0,0,0,8,0,0,0,//1
	0,0,0,0,2,0,0,0,//2
	0,0,7,6,1,3,5,0,//3
	0,0,0,0,0,4,0,0,//4
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0


	/*
	"▦","▦","▦","▦","⑨","▦","▦","▦",//"▦"
	"▦","▦","▦","▦","⑧","▦","▦","▦",//1
	"▦","▦","▦","▦","②","▦","▦","▦",//2
	"▦","▦","⑦","⑥","①","③","⑤","▦",//3
	"▦","▦","▦","▦","▦","④","▦","▦",//4
	"▦","▦","▦","▦","▦","▦","▦","▦",
	"▦","▦","▦","▦","▦","▦","▦","▦",
	"▦","▦","▦","▦","▦","▦","▦","▦"
	*/

};

//서식
const char *TileSet[] = {
	"▦", //0
	"①", //1
	"②", //2
	"③", //3
	"④", //4
	"⑤ ", //5
	"⑥", //6
	"⑦", //7
	"⑧", //8
	"⑨" //9
};




// ▦①②③④⑤⑥⑦⑧⑨

/*
char cTileMap[64] = { //1번이 스타트지점 //지도타일맵
	0,0,0,0,9,0,0,0,//0
	0,0,0,0,8,0,0,0,//1
	0,0,0,0,2,0,0,0,//2
	0,0,7,6,1,3,5,0,//3
	0,0,0,0,0,4,0,0,//4
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};
*/



void mapping()  //지도
{
	printf("\n");
	printf("\n");
	char _tempBuf[64];

	for (int i = 0; i < 64; i++) {
		_tempBuf[i] = cTileMap[i];
	}


	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf_s("%s", TileSet[_tempBuf[x + y * 8]]);
		}
		printf_s("\n");
	}
	printf("\n");
	printf_s("    지도를 보니, 지금 나는 %d번 방에 있다. \n", g_nCurrentPos); //해당 방의 설명 출력
	/*
	printf("\n"); printf("\n");
	printf("     ");
	for (int y = 1; y < 9; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	printf_s("    (/1번 : 시작의 방/2번 : 출구가 보이는 방/3번 : 작은 정원/9번 : 출구) \n");
	printf("     ");
	for (int y = 9; y < 17; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	printf_s("\n");
	printf("     ");
	for (int y = 17; y < 25; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	printf_s("\n");
	printf("     ");
	for (int y = 25; y < 33; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	printf_s("\n");
	printf("     ");
	for (int y = 33; y < 41; y++)
	{
		printf_s("%s", *TileSet[y]);
		

	}
	printf_s("    지도를 보니, 지금 나는 %d번 방에 있다. \n", g_nCurrentPos); //해당 방의 설명 출력
	
	printf("     ");
	for (int y = 41; y < 49; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	printf_s("\n");
	printf("     ");
	for (int y = 49; y < 57; y++)
	{
		printf_s("%s", *TileSet[y]);

	}

	
	printf_s("\n");
	printf("     ");
	for (int y = 57; y < 65; y++)
	{
		printf_s("%s", *TileSet[y]);

	}
	*/



	printf_s("\n"); printf("\n"); printf("\n");
} //맵출력데이터

void basicStatus() //최상단 기본데이터~체력방어도 표시까지 //초기화하면서 시작
{
	system("cls");
	printf("===========================주사위는 던져졌다====================================================================ver0.1 \n");
	printf_s("(명령일람 : /wasd : 화살표 방향이동/ r : 탐색 / t : 지도를 확인한다 /q : 종료) \n");
	printf_s("(현재체력 : ♥ x %d | 현재 타격보정치 : ψ %d | 현재 방어도 : ▣ %d) \n", cHp, cAtk, cDef);
	printf("\n");  printf("\n"); printf("\n");
}

void mapreading()
{
	printf("☞==============================================================================================================☜ver0.1 ");
	printf_s("%s \n", strpWorldArea[g_nCurrentPos]); //해당 방의 설명 출력
	printf("☞==============================================================================================================☜ver0.1 \n");

}




/////////////
int main()
{

	///데미지 테스트기
	/*
	while (1)

	{
		int atk = -(rand() % 7) - cAtk;
		int def = -(rand() % 7) + cDef;

		printf("데미지 테스트 %d \n", (rand() % 7));
		printf("공격 테스트 %d \n", -(rand() % 7) - cAtk);
		printf("방어 테스트 %d \n", -(rand() % 7) + cDef);
		printf("\n");
		Sleep(1000);
		
	}
	*/
		
		

	char _ch;
	int itemBorn = 0; //뼈다귀 이벤트 3; 워트의 의족 2; 소지이벤트 1; 써버림.
	int itemS = 0; //검 이벤트
	int itemD = 0; //쉴드 이벤트
	int itemF = 0; //서리한 이벤트

	////기본셋
	basicStatus(); //기본 데이터 출력
	mapreading();
	printf("\n");
	mapping();


	///기본셋


	while (1) //계속 돌아감
	{
		// 게임종료.
		if (cHp <= 0)
		{
			printf(" 게임을 종료합니다 \n");
			break;
		}

		//이벤트페이지/////////////////////////////////////////////////////////////////

		//서리한 이벤트
		{
			if (g_nCurrentPos == 0)
			{
				if (itemBorn == 3) //뼈다귀 이벤트)
				{

				}

				else if (itemBorn == 4)
				{
					g_nCurrentPos = 1; //1방으로 내보냄

					basicStatus(); //기본 데이터 출력
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //글자색 변경

					printf("당신은 이미 세상을 파멸시킬 힘을 얻었다. \n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("'여기 힘이 있었노라.그리고 여기 절망 또한 있었노라.'\n");
					PlaySound(TEXT("./music/warning.wav"), NULL, SND_SYNC);
					PlaySound(NULL, 0, 0);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					mapreading();
					printf("\n");
					mapping();
				}

				else
				{
					g_nCurrentPos = 1; //1방으로 내보냄

					basicStatus(); //기본 데이터 출력
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //글자색 변경

					printf("음산한 기운에 소스라치며, 문으로부터 얼른 손을 뗍니다.\n");
					PlaySound(TEXT("./music/warning.wav"), NULL, SND_SYNC);
					PlaySound(NULL, 0, 0);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					mapreading();
					printf("\n");
					mapping();
				}

			}

			if (g_nCurrentPos == 12)
			{
				itemBorn = 4;
				g_nCurrentPos = 1; //1방으로 내보냄

				basicStatus(); //기본 데이터 출력
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //글자색 변경

				printf("'이 검을 집는 자는 무한한 힘을 얻게 될 것이다. 그러나 검이 육신을 베듯이, 이 힘은 영혼에 상처를 남기리라...'\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("\n");
				printf("\n");
				printf("\n");
				printf("당신은 저주받은 검을 왕좌에서 뽑습니다.\n");
				cAtk = cAtk + 8;
				PlaySound(TEXT("./music/warning.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				basicStatus(); //기본 데이터 출력
				printf("Succeeding You, father.\n");
				mapreading();
				mapping();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			}



		}

		///뼈다귀 이벤트
		{ //뼈다귀이벤트 처리
			if (g_nCurrentPos == 4) //뼈다귀방 진입
			{


				if (itemBorn == 0) //뼈다귀 이벤트)
				{

				}
				else
				{
					g_nCurrentPos = 3; //3방으로 내보냄

					basicStatus(); //기본 데이터 출력
					printf("쓰레기 더미는 이제 지긋지긋해. 작은 정원으로 돌아왔다. \n");
					mapreading();
					printf("\n");
					mapping();
				}
			}

			if (g_nCurrentPos == 14) //뼈다귀 소지
			{
				system("cls");
				basicStatus(); //기본 데이터 출력
				itemBorn = 2; //소지상태
				g_nCurrentPos = 3; // 정원으로 돌아감
				\
					printf("뼈다귀를 그냥 챙기기로 했다. 작은 정원으로 돌아가자. \n");
				PlaySound(TEXT("./music/fngrsnap.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				mapreading();
				printf("\n");
				mapping();
			}

			if (g_nCurrentPos == 15) //뼈다귀 뼈방패
			{
				system("cls");
				basicStatus(); //기본 데이터 출력
				itemBorn = 1; //뼈다귀 소멸
				cDef = cDef + 1;
				g_nCurrentPos = 3; // 정원으로 돌아감

				basicStatus(); //기본 데이터 출력
				printf("뼈갑옷을 착용했다. 작은 정원으로 돌아가자. \n");
				PlaySound(TEXT("./music/fngrsnap.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				mapreading();
				printf("\n");
				mapping();

			}

			if (g_nCurrentPos == 16) // 뼈다귀 워트의 의족
			{
				system("cls");
				basicStatus(); //기본 데이터 출력
				itemBorn = 3; //워트상태
				g_nCurrentPos = 3; // 정원으로 돌아감


				printf("워트의 의족을 만들었다. 작은 정원으로 돌아가자. \n");
				PlaySound(TEXT("./music/fngrsnap.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				mapreading();
				printf("\n");
				mapping();
			}

		} //뼈다귀

		///링크의 검 이벤트
		if (g_nCurrentPos == 5)
		{
			if (itemS == 0) //뼈다귀 이벤트)
			{
				system("cls");
				basicStatus(); //기본 데이터 출력
				itemS = 1; //검 장비
				cAtk = cAtk + 3; //공격력 상승


				printf("창고를 뒤졌더니, 희귀한 용사의 검을 손에 넣었다!(타격치 보정+3) \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("칼집에는  '내...이름은...젤다가...아니다...'라고 적혀있다.");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				PlaySound(TEXT("./music/weapon.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				mapreading();
				printf("\n");
				mapping();

			}
			else
			{
				g_nCurrentPos = 3; //1방으로 내보냄

				basicStatus(); //기본 데이터 출력
				printf("창고에는 더 이상 훔칠 것이 없습니다. \n");
				mapreading();
				printf("\n");
				mapping();
			}

		}
		//트롤입장 이벤트
		{
			if (g_nCurrentPos == 7)
			{
				if (itemD == 0) //방패가 없어야만 입장.
				{

				}
				else
				{
					g_nCurrentPos = 6; //6방으로 내보냄

					basicStatus(); //기본 데이터 출력

					printf("트롤의 시체가 쓰러져 일대가 폐허가 되어버렸다. 더 이상 이곳엔 접근할 수 없겠어. 돌아가자. \n");

					mapreading();
					printf("\n");
					mapping();
				}

			}
		}


		///13번 트롤전투이벤트

		if (g_nCurrentPos == 13)
		{

			bHp = 40;  //보스 체력

			basicStatus(); //기본 데이터 출력
			printf("\n");
			printf("\n"); printf("\n");
			printf("============================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("========= Warning!!!!! ===============================================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Warning!!!!! ========================================== Warning!!!!! ====================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("==============================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Battle VS troll ================ Warning!!!!! =====================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("=====================================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("================================================ Warning!!!!! ====================== Warning!!!!! ================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("===========================Warning!!!!!=====================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("======= Warning!!!!! ========================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("================================================================ Warning!!!!! ======================= Warning!!!!! ===============\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Battle VS troll =====================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("====== Warning!!!!! ============================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("================================================================ Warning!!!!! ==========================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("=========================== Battle VS troll =====================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("===========================================================================================================================\n");
			printf("\n"); printf("\n");
			printf("\n");
			///공격
			Sleep(1000);
			system("cls");

			while (1) //전투

			{



				printf("==========================강력한 일격을 날렸다!======================================================================== \n");
				Sleep(500);
				system("cls");

				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				{
					int dmg = (rand() % 7) + cAtk;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("==========================상대에게 입힌 피해 %d!======================================================================== \n", dmg);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					PlaySound(TEXT("./music/atk2.wav"), NULL, SND_SYNC);
					PlaySound(NULL, 0, 0);
					system("cls");
					bHp = bHp - dmg - cAtk;
				}

				if (bHp <= 0)
				{

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n");
					printf("================================================================================================\n");
					printf("=======================♨♨ 보스를 무찔렀다!!!!!! ♨♨==========================================\n");
					printf("================================================================================================\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("=========================보상으로 '도란의 방패(방어도+3)'를 얻습니다!!!!!!======================\n");
					printf("=========================보상으로 체력을 10 회복합니다!!!!!!==================================\n");
					itemD = 1;
					cDef = cDef + 3;
					cHp = cHp + 10;
					PlaySound(TEXT("./music/victory.wav"), NULL, SND_SYNC);
					PlaySound(NULL, 0, 0);
					g_nCurrentPos = 6; //이전 방으로 퇴장
					basicStatus(); //기본 데이터 출력
					printf("트롤의 시체가 쓰러져 일대가 폐허가 되어버렸다. 더 이상 이곳엔 접근할 수 없겠어. 돌아가자. \n");
					mapreading();
					printf("\n");
					mapping();

					break;
				}
				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("===============================보스의 남은 체력은%d!========================================== \n", bHp);
				Sleep(500);
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");




				///보스 공격
				int bDmg = (rand() % 7) + 2 - cDef;
				printf("=============================적의 공격으로부터 %d의 피해를 입었습니다! ============================\n", bDmg);
				Sleep(500);
				system("cls");
				cHp = cHp - bDmg;


				if (cHp <= 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("======================================= ♨사망하셨습니다♨ ===================================================\n");
					printf("===============================    멀리 배웅해드리지 않습니다. ===================================================\n");
					printf("======================================   다시 시작하세요.  ===================================================\n");
					break;
				}
				printf("\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("==============================이 공격은 많이 아프다.. 남은 체력은 %d =======================\n", cHp);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				PlaySound(TEXT("./music/cry.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				system("cls");
				printf("\n");
				printf("\n");
				printf("\n");


			}




		}


		///*경비견이벤트
		if (g_nCurrentPos == 18)
		{
			if (itemBorn == 2) //뼈다귀 이벤트)
			{

				basicStatus(); //기본 데이터 출력
				printf("당신은 주머니에서 뼈다귀를 찾아냈다. 경비견의 눈동자가 뼈다귀로 향한다.\n");
				Sleep(2000);
				system("cls");

				basicStatus(); //기본 데이터 출력
				printf("그것을 확인한 당신은 뼈다귀를 경비견에게 던졌다. \n");
				PlaySound(TEXT("./music/fngrsnap.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				Sleep(500);

				system("cls");
				basicStatus();

				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				printf("과연. \n");
				Sleep(100);
				system("cls");

				basicStatus(); //기본 데이터 출력
				printf("경비견은 슬쩍 날아가는 뼈다귀를 쳐다보더니, 결코 몸을 움직이지는 않는다.\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("녀석은 뼈보다는 살아있는 당신의 육체에 관심이 더 많은 눈치다. \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("전투를 준비하라.");
				PlaySound(TEXT("./music/cry3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				Sleep(2000);
				system("cls");

				g_nCurrentPos = 19;


			}
			else
			{
				g_nCurrentPos = 19; //19방으로 내보냄

				basicStatus(); //기본 데이터 출력
				printf("당신의 주머니에는 경비견의 흥미를 끌만한 것이 없다. 안타깝군요. \n전투를 준비하라. \n");
				PlaySound(TEXT("./music/cry3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				Sleep(1500);

			}

		}

		if (g_nCurrentPos == 19)
		{
			basicStatus(); //기본 데이터 출력
			printf("경비견은 당신의 예상보다 훨씬 빨랐다. 이글거리는 이빨이 코앞까지 들이닥친다.\n");
			PlaySound(TEXT("./music/cry2.wav"), NULL, SND_SYNC);
			PlaySound(NULL, 0, 0);






			bHp = 65;  //보스 체력

			basicStatus(); //기본 데이터 출력
			printf("\n");
			printf("\n"); printf("\n");
			printf("=============================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("========= Warning!!!!! ================================================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Warning!!!!! ========================================== Warning!!!!! =======================v=====\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("==============================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Battle VS Κέρβερος ================ Warning!!!!! ====================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("==============================================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("================================================ Warning!!!!! ====================== Warning!!!!! ============================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("===========================Warning!!!!!================================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("======= Warning!!!!! =========================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("================================================================ Warning!!!!! ======================= Warning!!!!! ============\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("=========================== Battle VS Κέρβερος ===================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("====== Warning!!!!! ===========================================================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("================================================================ Warning!!!!! =================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("=========================== Battle VS Κέρβερος ===================================================================ver0.1 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("================================================================================================================================\n");
			printf("\n"); printf("\n");
			printf("\n");
			PlaySound(TEXT("./music/cry2.wav"), NULL, SND_SYNC);
			PlaySound(NULL, 0, 0);
			///공격
			Sleep(1000);
			system("cls");

			while (1) //전투

			{



				printf("==========================강력한 일격을 날렸다!======================================================================== \n");
				Sleep(500);
				system("cls");

				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				int dmg = (rand() % 7) + cAtk;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("==========================상대에게 입힌 피해 %d!======================================================================== \n", dmg);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				PlaySound(TEXT("./music/atk2.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				system("cls");
				bHp = bHp - dmg;

				if (bHp <= 0)
				{

					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");

					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");
					printf("\n"); printf("\n");
					printf("\n");	printf("\n");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					system("cls");

					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("=======================♨♨ 최후의 보스를 무찔렀다!!!!!! ♨♨=================================\n");

					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("=========================드디어 세상으로 나가게 되었습니다!!!!!!==============================\n");
					printf("==============================================================================================\n");

					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");
					printf("==============================================================================================\n");

					PlaySound(TEXT("./music/ending2.wav"), NULL, SND_SYNC);



					g_nCurrentPos = 9; //엔딩방으로 퇴장
					system("cls");
					basicStatus(); //기본 데이터 출력
					printf("클로징멘트\n");
					mapreading();
					printf("\n");
					mapping();

					break;
				}
				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n"); printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("===============================보스의 남은 체력은%d!========================================== \n", bHp);
				Sleep(500);
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");	printf("\n");
				printf("\n");




				///보스 공격
				int bDmg = (rand() % 7) + 5 - cDef;
				printf("=============================적의 공격으로부터 %d의 피해를 입었습니다! ============================\n", bDmg);
				Sleep(500);
				system("cls");
				cHp = cHp - bDmg;


				if (cHp <= 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("======================================= ♨사망하셨습니다♨ ===================================================\n");
					printf("===============================    멀리 배웅해드리지 않습니다. ===================================================\n");
					printf("======================================   다시 시작하세요.  ===================================================\n");
					break;
				}
				printf("\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("==============================이 공격은 많이 아프다.. 남은 체력은 %d =======================\n", cHp);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				PlaySound(TEXT("./music/cry2.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				system("cls");
				printf("\n");
				printf("\n");
				printf("\n");


			}




		}


		if (g_nCurrentPos == 20) //
		{

			for (int i = 0; i < 100; i++)
			{ 
			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6));
			printf("================= E N D I N G =================================================================\n");
			printf("============================================================ E N D I N G ==================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 1);
			printf("===================  E N D I N G  ===============================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 2);
			printf("========================================================== E N D I N G  =========================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 3);
			printf("=========================  E N D I N G  ==============================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 4);
			printf("=====================================================  E N D I N G  =======================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 5);
			printf("============  E N D I N G  ===================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 6);
			printf("==========================================================  E N D I N G  ====================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 7);
			printf("=======  E N D I N G  ====================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 8);
			printf("======================================================  E N D I N G ======================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 9);
			printf("=========================================  E N D I N G  ===================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 10);
			printf("============  E N D I N G  ================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 9);
			printf("=================================================  E N D I N G  ================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 8);
			printf("=================  E N D I N G  ==============================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 7);
			printf("========================================================= E N D I N G ================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 6);
			printf("=============  E N D I N G  ===================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 5);
			printf("========================================================== E N D I N G  ======================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 4);
			printf("========================= : ==========================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 3);
			printf("=========== E N D I N G ===================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 2);
			printf("==========================================================  E N D I N G  ======================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 1);
			printf("============ E N D I N G ==================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 2);
			printf("===================================================== E N D I N G ==============================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 3);
			printf("============== E N D I N G =====================================================================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 4);
			printf("===== 제작자 : 이준식 ===================================== E N D I N G =====================\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 6) + 5);
			printf("=================== E N D I N G ================== Thanks to : gbox3d ==================\n");

			Sleep(2000);
			}
		}


	
			
				//for (int i = 0; i < 6; i++)
				//{
			

			//Sleep(500);

			//}

			

		

		////본문시작/////////////////////////////////////
		_ch = _getch();

		//널값 컨티뉴문 방지.
		if (_ch == '\0') { 
			continue;
			printf("\n");

		}

		basicStatus(); //기본 데이터출력

		// 게임종료.
		if (_ch == 'q')
		{
			printf(" 게임을 종료합니다 \n");
			break;
		}

		
		//주변탐색 명령어 r
		else if (_ch == 'r') {
			printf_s("%s \n", strpWorldArea[g_nCurrentPos]); //해당 방의 설명 출력
				
			printf("\n");
		}
		
		//지도확인
		else if (_ch == 't') {

			printf_s("\"지도는 많이 낡았지만, 지금 이것 저것 가릴 처지는 아니군.\" \n"); //
			printf("\n");

			mapping();
			
		}




		else if (_ch == 'w') { //w 북쪽으로 이동
			int nDir = 3;


			int new_pos = g_wayTable[g_nCurrentPos][nDir]; //가야할 방향 검증 [현재방][갈수있는좌표]
			if (new_pos == -1) //-1은 막힌 곳. g_nCurrentPos값의 변동은 없다.
			{
				printf_s("그쪽으로는 갈 수 없습니다.\n");

				printf("\n");

				mapreading();
				printf("\n");

				mapping();
			}
			else {
				printf_s("북쪽으로 이동중... \n"); //0,1,2 .... 방 번호 맞을 시 해당 위치로 이동
				PlaySound(TEXT("./music/foot3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				printf("\n"); printf("\n");
				g_nCurrentPos = new_pos; //갈 수 있다면 현재위치를 새로운 위치로 덮는다.
				mapreading();
				printf("\n");

				mapping();
				
			}
		}


		else if (_ch == 'a') {  //w 서쪽 방향을 입력하세요 동서남북(0,1,2,3)
			int nDir = 1;


			int new_pos = g_wayTable[g_nCurrentPos][nDir]; //가야할 방향 검증 [현재방][갈수있는좌표]
			if (new_pos == -1) //-1은 막힌 곳. g_nCurrentPos값의 변동은 없다.
			{
				printf_s("그쪽으로는 갈 수 없습니다.\n");

				printf("\n");

				mapreading();
				printf("\n");

				mapping();
			}
			else {
				printf_s("서쪽으로 이동중...\n"); //0,1,2 .... 방 번호 맞을 시 해당 위치로 이동
				PlaySound(TEXT("./music/foot3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				printf("\n"); printf("\n");
				g_nCurrentPos = new_pos; //갈 수 있다면 현재위치를 새로운 위치로 덮는다.
				mapreading();
				printf("\n");

				mapping();
				
			}

		}

		else if (_ch == 's') { //w 남쪽으로 이동
			int nDir = 2;


			int new_pos = g_wayTable[g_nCurrentPos][nDir]; //가야할 방향 검증 [현재방][갈수있는좌표]
			if (new_pos == -1) //-1은 막힌 곳. g_nCurrentPos값의 변동은 없다.
			{
				printf_s("그쪽으로는 갈 수 없습니다.\n");

				printf("\n");

				mapreading();
				printf("\n");

				mapping();
			}
			else {
				printf_s("남쪽으로 이동중...\n"); //0,1,2 .... 방 번호 맞을 시 해당 위치로 이동
				PlaySound(TEXT("./music/foot3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				printf("\n"); printf("\n");
				g_nCurrentPos = new_pos; //갈 수 있다면 현재위치를 새로운 위치로 덮는다.
				mapreading();
				printf("\n");

				mapping();
				
			}

		}


		else if (_ch == 'd') { //w 동쪽으로 이동
			int nDir = 0;


			int new_pos = g_wayTable[g_nCurrentPos][nDir]; //가야할 방향 검증 [현재방][갈수있는좌표]
			if (new_pos == -1) //-1은 막힌 곳. g_nCurrentPos값의 변동은 없다.
			{
				printf_s("그쪽으로는 갈 수 없습니다.\n");

				printf("\n");

				mapreading();
				printf("\n");

				mapping();
			}
			else {
				printf_s("동쪽으로 이동중...\n"); //0,1,2 .... 방 번호 맞을 시 해당 위치로 이동
				PlaySound(TEXT("./music/foot3.wav"), NULL, SND_SYNC);
				PlaySound(NULL, 0, 0);
				printf("\n"); printf("\n");
				g_nCurrentPos = new_pos; //갈 수 있다면 현재위치를 새로운 위치로 덮는다.
				mapreading();
				printf("\n");

				mapping();
				
			}
		}
	
		else
		{
			printf("\"그것은 알 수 없는 행동인걸.\" \n");
			printf("\n");

			printf("\n");

			mapreading();
			printf("\n");

			mapping();
		}
		
	}

	return 0;
}


//메모장

//문자 입력 후, 널문자가 등장함.



/*//플레이어 출력

for (int y = 0; y < 4; y++)
{
for (int x = 0; x < 5; x++)
{
printf_s("%s", g_wayTable[y][x]);
}
printf_s("\n");
}
*/

/*
printf_s("방향을 입력하세요 동서남북(0,1,2,3) -> ");
scanf_s("%d", &nDir); //방향지정
*/