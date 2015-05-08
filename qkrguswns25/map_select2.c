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

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void print_map() //¸Ê Ãâ·Â
{
	int i,j;

	for(i=0;i<SERO;i++)
	{
		for(j=0;j<GARO;j++)
		{
			printf("%c",map[SERO][GARO]);
		}
	}
}
void print_status() //»óÅÂ Ãâ·Â
{
	int i,j;
	gotoxy(60,1);
	printf("1P");
	gotoxy(60,2);
	for(i=0;i<one_blood();i++)
		printf("¢¾");
	gotoxy(60,10);
	printf("2P");
	gotoxy(60,11);
	for(j=0;j<two_blood();j++)
		printf("¢¾");
}
void map_type() //¸Ê ¼±ÅÃ
{
	gotoxy(26,26);
	printf("¸Ê 1");
	gotoxy(36,26);
	printf("¸Ê 2"); 
	gotoxy(46,26);
	printf("¸Ê 3");
}
int map_select() // ¸Ê ¼±ÅÃ
{
	int menu=0,key;
	while(1)  
	{
		if(kbhit())
		{
			key = getch();
			if(key == LEFT)
			{
				menu = menu? menu-1 : 2;
			}
			else if(key == RIGHT)
			{
				menu = (menu + 1) % 3;
			}
			else if(key == SPACE || key == ENTER)
			{
				return menu + 1;
			}
			if(menu == 0)
			{
				gotoxy(33,26);
				printf("  ");
				gotoxy(43,26);
				printf("  ");
				gotoxy(23,26);
				printf("¢Â");
				gotoxy(41,26);
				printf("  ");
				gotoxy(51,26);
				printf("  ");
				gotoxy(31,26);
				printf("¢Â");
			}
			else if(menu == 1)
			{
				gotoxy(23,26);
				printf("  ");
				gotoxy(43,26);
				printf("  ");
				gotoxy(33,26);
				printf("¢Â");
				gotoxy(31,26);
				printf("  ");
				gotoxy(51,26);
				printf("  ");
				gotoxy(41,26);
				printf("¢Â");
			}
			else if(menu == 2)
			{
				gotoxy(23,26);
				printf("  ");
				gotoxy(33,26);
				printf("  ");
				gotoxy(43,26);
				printf("¢Â");
				gotoxy(31,26);
				printf("  ");
				gotoxy(41,26);
				printf("  ");
				gotoxy(51,26);
				printf("¢Â");
			}
		}

	}
}

int main()
{
	map_type();
	map_select();
	return 0;
}
