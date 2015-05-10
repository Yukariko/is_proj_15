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
#define p2_LEFT 97
#define p2_RIGHT 100
#define p2_UP 119
#define p2_DOWN 115

int gameover;

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

struct player
{
	int bullet_count;
	int heart;
	int x,y;
};


void game_start()
{
	system("cls");					//���� ������ ȭ�� �ʱ�ȭ 
	
	char c;
	struct player p1,p2;
	p1.heart=5;
	p2.heart=5;
	printf("%d %d \n",p1.heart,p2.heart);
	p1.x=10;
	p1.y=10;
	p2.x=5;
	p2.y=5;
	
	print_map(map_select());  //������ �޴��̵��� ���ϰ����� ���� ���  
	
	while(1) //���� ������  
	{
	print_status();
	printf_monster();             //�ð������ʿ� 
	printf_player();
	printf_potion();              //�ð������ʿ�  
	
	while (kbhit()) 
	{   //Ű �ޱ� 
		gotoxy(p1.x,p1.y);
			printf(" ");
			gotoxy(p2.x,p2.y);
			printf(" ");			
			c=getch();
			if(c==LEFT)
			{
				if(map[x][y]==00) --p1.x;
				
			}
			else if(c==RIGHT)
			{
				if(map[x][y]==00) ++p1.x;
			}
			else if(c==DOWN)
			{
			
				if(map[x][y]==00) ++p1.y;
		
			}
			else if(c==UP)
			{
				if(map[x][y]==00) --p1.y;
			}
			////////////////////////////////////////////
			if(c==p2_LEFT)
			{
				if(map[x][y]==00) --p2.x;
				
			}
			else if(c==p2_RIGHT)
			{
				if(map[x][y]==00) ++p2.x;
			}
			else if(c==p2_DOWN)
			{
			
				if(map[x][y]==00) ++p2.y;
		
			}
			else if(c==p2_UP)
			{
				if(map[x][y]==00) --p2.y;
			}
		}
		gotoxy(p1.x,p1.y);
		printf("��");
		gotoxy(p2.x,p2.y);
		printf("��");
     	
     
     
 		}
 	
	effect_map();  //Ư��ȿ���� �ִ� ��ó���� ���� �Լ�  
 
 	
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






