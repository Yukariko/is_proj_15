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
	system("cls");					//���� ������ ȭ�� �ʱ�ȭ 
	
	one_blood(HP);                    //�� �Լ����� �ʿ��� ���ΰ�? �ʿ��ϸ� ������� �ۼ��� �ؾ��� ���ΰ� 
	one_bullet(bullet);
	two_bllod(HP);
	two_bullet(bullet);
	
	print_map(map_select());  //������ �޴��̵��� ���ϰ����� ���� ���  
	
	while(1) //���� ������  
	{
	print_status();
	printf_monster();             //�ð������ʿ� 
	printf_player();
	printf_potion();              //�ð������ʿ�  
	
	while (kbhit()) {   //Ű �ޱ� 
     	c  = getch();
     	
     
     
 		}
 	
	effect_map();  //Ư��ȿ���� �ִ� ��ó���� ���� �Լ�  
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






