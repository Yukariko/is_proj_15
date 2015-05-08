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
void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int map_select()
{
	int menu=0,key,choice=0;
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

			if(menu==0)
			{
				gotoxy(30,26);
				printf("  ");
				gotoxy(30,23);
				printf("  ");
				gotoxy(30,20);
				printf("¢Â");
				gotoxy(40,26);
				printf("  ");
				gotoxy(40,23);
				printf("  ");
				gotoxy(40,20);
				printf("¢Â");
			}
			else if(menu==1)
			{
				gotoxy(30,20);
				printf("  ");
				gotoxy(30,26);
				printf("  ");
				gotoxy(30,23);
				printf("¢Â");
				gotoxy(40,20);
				printf("  ");
				gotoxy(40,26);
				printf("  ");
				gotoxy(40,23);
				printf("¢Â");
			}
			else if(menu==2)
			{
				gotoxy(30,20);
				printf("  ");
				gotoxy(30,23);
				printf("  ");
				gotoxy(30,26);
				printf("¢Â");
				gotoxy(40,20);
				printf("  ");
				gotoxy(40,23);
				printf("  ");
				gotoxy(40,26);
				printf("¢Â");
			}
			if(menu==0 && choice==1) // ¸Ê ½ÇÇà
			{
				
			}
			else if(menu==1 && choice==1)
			{
				
			}
			else if(menu==2 && choice==1)
			{
				
			}

		}

	}
}
int main()
{
	map_select();
}