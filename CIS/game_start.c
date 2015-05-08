#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ENTER 13
#define SERO 24
#define GARO 50
#define HP 5
#define bullet 50
int gameover;

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_start()
{
	system("cls");					//게임 시작전 화면 초기화 
	
	one_blood(HP);                    //이 함수들이 필요한 것인가? 필요하면 어떤식으로 작석을 해야할 것인가 
	one_bullet(bullet);
	two_bllod(HP);
	two_bullet(bullet);
	
	print_map(map_select());  //현준이 메뉴이동을 리턴값으로 수정 요망  
	
	while(1) //개임 시작중  
	{
	print_status();
	printf_monster();             //시간조건필요 
	printf_player();
	printf_potion();              //시간조건필요  
	
	while (kbhit()) {   //키 받기 
     	c  = getch();
     	
     
     
 		}
 	
	effect_map();  //특수효과가 있는 맵처리에 관한 함수  
 	if(one_blood() == 0) printf_gameover();
 	else if (two_blood() == 0) printf_gameover();
 	
	}
	
	
	
}

void printf_player();
{
	gotoxy(1P_respon_x,1P_respon_y);
	puts("1P");
	
	gotoxy(2P_respon_x,2P_respon_y);
	puts("2P");
	

}
void printf_monster();
{
	gotoxy(monster_respon_x,monster_respon_y);
	puts("monster");
}






