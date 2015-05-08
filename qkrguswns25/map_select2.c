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
void map_type()
{
	gotoxy(36,20);
	printf("¸Ê 1");
	gotoxy(36,23);
	printf("¸Ê 2"); 
	gotoxy(36,26);
	printf("¸Ê 3");
}
void print_map(int menu) //¸Ê Ãâ·Â
{
	int i,j;
	if(menu==0) map=map1();
	else if(menu==1) map=map2();
	else if(menu==2) map=map3();

	for(i=0;i<SERO;i++)
	{
		for(j=0;j<GARO;j++)
		{
			printf("%c",map[SERO][GARO]);
		}
	}
}
void print_status()
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
int map_select()
{
	int menu=-1,key,choice=0;
	while(1) // ¸Ê ¼±ÅÃ 
	{
		if(kbhit())
		{
			key = getch();
			if(key == UP)
				menu-=1;
			else if(key == DOWN)
				menu+=1;
			else if(key == SPACE || key == ENTER)
				choice=1;

			if((menu+100)%3==0)
			{
				gotoxy(33,26);
				printf("  ");
				gotoxy(33,23);
				printf("  ");
				gotoxy(33,20);
				printf("¢Â");
				gotoxy(41,26);
				printf("  ");
				gotoxy(41,23);
				printf("  ");
				gotoxy(41,20);
				printf("¢Â");
			}
			else if((menu+100)%3==1)
			{
				gotoxy(33,20);
				printf("  ");
				gotoxy(33,26);
				printf("  ");
				gotoxy(33,23);
				printf("¢Â");
				gotoxy(41,20);
				printf("  ");
				gotoxy(41,26);
				printf("  ");
				gotoxy(41,23);
				printf("¢Â");
			}
			else if((menu+100)%3==2)
			{
				gotoxy(33,20);
				printf("  ");
				gotoxy(33,23);
				printf("  ");
				gotoxy(33,26);
				printf("¢Â");
				gotoxy(41,20);
				printf("  ");
				gotoxy(41,23);
				printf("  ");
				gotoxy(41,26);
				printf("¢Â");
			}
			if(menu==0 && choice==1) // ¸Ê ½ÇÇà
			{
				return 1;
			}
			else if(menu==1 && choice==1)
			{
				return 2;
			}
			else if(menu==2 && choice==1)
			{
				return 3;
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