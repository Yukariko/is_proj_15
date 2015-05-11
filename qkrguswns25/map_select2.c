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
#define SERO 16
#define GARO 24
#define GROUND 0
#define BUILDING1 1
#define BUILDING2 2
#define BUILDING3 3
#define BUILDING4 4
#define GRASS 5
#define BASE 3
#define XJSI 2
#define YISI 1

char map[SERO+1][GARO+1];

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void map_type() //?? ????
{
	gotoxy(26,26);
	printf("¸Ê 1");
	gotoxy(36,26);
	printf("¸Ê 2"); 
	gotoxy(46,26);
	printf("¸Ê 3");
}

const char *get_shape(char code)
{
	 if(code==GROUND)
		return "¢Ë";
	else if(code>=BUILDING1 && code<=BUILDING4)
		return "¡à";
	else if(code==GRASS)
		return "¢¿";
}

int get_x(int x)
{
	return BASE+j*XSI;
}
int get_y(int y)
{
	return BASE+i*YSI;
}
void print_map(int num)
{
	FILE *fp;
	if(num == 1)
		fp = fopen("./¸Ê1.txt","r");
	else if(num == 2)
		fp = fopen("./¸Ê2.txt","r");
	else
		fp = fopen("./¸Ê3.txt","r");
	
	for(int i=0;i<SERO;i++)
		for(int j=0;j<GARO;j++)
			fscanf(fp,"%d",&map[i][j]);
	fclose(fp);
	
	system("cls");					//°ÔÀÓ ½ÃÀÛÀü È­¸é ÃÊ±âÈ­ 
	
	for(int i=0;i<SERO;i++)
	{
		for(int j=0;j<GARO;j++)
		{
			gotoxy(BASE+j*XJSI, BASE+i*YISI);
			printf("%s",get_shape(map[i][j]));
		}
	}
}
int map_select() // ?? ????
{
	
	int menu=0,key;
	map_type();
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
	map_select();
	return 0;
}


