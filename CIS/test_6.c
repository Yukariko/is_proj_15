#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define P1_LEFT 97
#define P1_RIGHT 100
#define P1_UP 119
#define P1_DOWN 115
#define SPACE 32
#define ENTER 13
#define HP 5
#define P2_LEFT 75
#define P2_RIGHT 77
#define P2_UP 72
#define P2_DOWN 80
#define SERO 16
#define GARO 24
#define GROUND 0
#define BUILDING1 1
#define BUILDING2 2
#define BUILDING3 3
#define BUILDING4 4
#define GRASS 5
#define BASE 3
#define XSI 2
#define YSI 1
#define PLAYER_P1 20
#define PLAYER_P2 21
#define BULLET 13
#define BULLET_P1_UP 104 //h
#define BULLET_P1_DOWN 110 //n
#define BULLET_P1_RIGHT 109 //m
#define BULLET_P1_LEFT 98 //b
#define BULLET_P2_UP 56 //8
#define BULLET_P2_DOWN 50 //2
#define BULLET_P2_RIGHT 54 //6
#define BULLET_P2_LEFT 52 //4



/*
Sleep(1000); // 1 초

int k;
char map[101][101];
int timer = 1;
while(1) // 메뉴 키조작 
{
if(kbhit())
{
key = getch();
if(key == UP)menu-=1;
else if(key == DOWN)menu+=1;
else if(key == SPACE || key == ENTER)choice=1;
else choice=2;
}
if(timer == 1000)
{
move_bullet();	
}
timer++;
}
*/

struct player
{
	char origin;
	int bullet_count;
	int heart;
	int x,y;
};
struct bullet  //총알
{
	char origin;
	int x,y;
	int speed;
	int vector;
	int on;
	int count;

};

struct player p1,p2;
struct bullet bp1,bp2;
char map[SERO+1][GARO+1];

void gotoxy(int x, int y);
void textcolor(int color);
void start();
void end();
void init();
void game_start();
void print_monster();
void print_player();
int map_select();
void map_type();
void print_map(int num);
const char *get_shape(char code);
void textcolor(int color);

int main()
{
	//start();
	game_start();
	end();
	return 0;
}
int get_x(int x)
{
	return BASE+x*XSI;
}
int get_y(int y)
{
	return BASE+y*YSI;
}
void init()
{
	p1.heart=5;
	p2.heart=5;
	p1.x=2;
	p1.y=14;
	p2.x=22;
	p2.y=1;
	p1.origin=GROUND;
	p2.origin=GROUND; 
	bp1.origin=GROUND;
	bp2.origin=GROUND;
	bp1.on = bp2.on = 0;
}

void map_type() //맵 종류 
{
	gotoxy(26,26);
	printf("맵 1");
	gotoxy(36,26);
	printf("맵 2");
	gotoxy(46,26);
	printf("맵 3");
}

int map_select() // 맵 선택 
{
	int menu=0,key;
	map_type();
	while(1)  
	{
		if(kbhit())
		{
			key = getch();
			if(key == P1_LEFT ||key == P2_LEFT)
			{
				menu = menu? menu-1 : 2;
			}
			else if(key == P1_RIGHT || key == P2_RIGHT)
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
				printf("◈");
				gotoxy(41,26);
				printf("  ");
				gotoxy(51,26);
				printf("  ");
				gotoxy(31,26);
				printf("◈");
			}
			else if(menu == 1)
			{
				gotoxy(23,26);
				printf("  ");
				gotoxy(43,26);
				printf("  ");
				gotoxy(33,26);
				printf("◈");
				gotoxy(31,26);
				printf("  ");
				gotoxy(51,26);
				printf("  ");
				gotoxy(41,26);
				printf("◈");
			}
			else if(menu == 2)
			{
				gotoxy(23,26);
				printf("  ");
				gotoxy(33,26);
				printf("  ");
				gotoxy(43,26);
				printf("◈");
				gotoxy(31,26);
				printf("  ");
				gotoxy(41,26);
				printf("  ");
				gotoxy(51,26);
				printf("◈");
			}
		}

	}
}

const char *get_shape(char code) //모양 출력
{
	if(code==GROUND)
		return "▦";
	else if(code>=BUILDING1 && code<=BUILDING4)
		return "□";
	else if(code==GRASS)
		return "♧";
	else if(code==PLAYER_P1)
		return "●";
	else if(code==PLAYER_P2) 
		return "○";
	else if(code==BULLET)
		return "*";
}

void gaming_print_map(int y,int x) //게임중 맵 출력
{
	gotoxy(get_x(x),get_y(y) );
	printf("%s",get_shape(map[y][x]));
}
void print_map(int num) //맵 출력
{
	FILE *fp;
	if(num == 1)
		fp = fopen("./맵1.txt","r");
	else if(num == 2)
		fp = fopen("./맵2.txt","r");
	else
		fp = fopen("./맵3.txt","r");

	for(int i=0;i<SERO;i++)
		for(int j=0;j<GARO;j++)
			fscanf(fp,"%d",&map[i][j]);
	fclose(fp);

	system("cls");					//게임 시작전 화면 초기화 

	for(int i=0;i<SERO;i++)
	{
		for(int j=0;j<GARO;j++)
		{
			gaming_print_map(i,j);
		}
	}
}

void game_start() //게임 실행
{
	system("cls");					//게임 시작전 화면 초기화 

	char c;

	init();

	print_map(map_select());  //현준이 메뉴이동을 리턴값으로 수정 요망  

	while(1) //개임 시작중  
	{
		if (kbhit()) 
		{   //키 받기 
			//gotoxy(get_x(p1.x),get_y(p1.y));
			//printf("%s",get_shape(GROUND));

			c=getch();
			if(c==P1_UP) 
			{
				if(map[p1.y-1][p1.x]==GROUND || map[p1.y-1][p1.x]==GRASS)
				{
					map[p1.y][p1.x]=p1.origin;
					gaming_print_map(p1.y,p1.x);
					p1.origin=map[p1.y-1][p1.x];
					--p1.y;
					map[p1.y][p1.x]=PLAYER_P1;
					if(p1.origin!=GRASS) gaming_print_map(p1.y,p1.x);
				}


			}
			else if(c==P1_DOWN)
			{
				if(map[p1.y+1][p1.x]==GROUND ||   map[p1.y+1][p1.x]==GRASS)
				{
					map[p1.y][p1.x]=p1.origin;
					gaming_print_map(p1.y,p1.x);
					p1.origin=map[p1.y+1][p1.x];
					++p1.y;
					map[p1.y][p1.x]=PLAYER_P1;
					if(p1.origin!=GRASS) gaming_print_map(p1.y,p1.x);
				}

			}
			else if(c==P1_RIGHT)
			{

				if(map[p1.y][p1.x+1]==GROUND ||  map[p1.y][p1.x+1]==GRASS)
				{
					map[p1.y][p1.x]=p1.origin;
					gaming_print_map(p1.y,p1.x);
					p1.origin=map[p1.y][p1.x+1];
					++p1.x;
					map[p1.y][p1.x]=PLAYER_P1;
					if(p1.origin!=GRASS) gaming_print_map(p1.y,p1.x);
				}

			}
			else if(c==P1_LEFT)
			{
				if( map[p1.y][p1.x-1]==GROUND ||  map[p1.y][p1.x-1]==GRASS)
				{
					map[p1.y][p1.x]=p1.origin;
					gaming_print_map(p1.y,p1.x);
					p1.origin=map[p1.y][p1.x-1];
					--p1.x;
					map[p1.y][p1.x]=PLAYER_P1;
					if(p1.origin!=GRASS) gaming_print_map(p1.y,p1.x);
				}

			}
			else if(c==P2_UP)
			{
				if(map[p2.y-1][p2.x]==GROUND || map[p2.y-1][p2.x]==GRASS)
				{
					map[p2.y][p2.x]=p2.origin;
					gaming_print_map(p2.y,p2.x);
					p2.origin=map[p2.y-1][p2.x];
					--p2.y;
					map[p2.y][p2.x]=PLAYER_P2;
					if(p2.origin!=GRASS) gaming_print_map(p2.y,p2.x);
				}


			}
			else if(c==P2_DOWN)
			{
				if(map[p2.y+1][p2.x]==GROUND ||   map[p2.y+1][p2.x]==GRASS)
				{
					map[p2.y][p2.x]=p2.origin;
					gaming_print_map(p2.y,p2.x);
					p2.origin=map[p2.y+1][p2.x];
					++p2.y;
					map[p2.y][p2.x]=PLAYER_P2;
					if(p2.origin!=GRASS) gaming_print_map(p2.y,p2.x);
				}

			}
			else if(c==P2_RIGHT)
			{

				if(map[p2.y][p2.x+1]==GROUND ||  map[p2.y][p2.x+1]==GRASS)
				{
					map[p2.y][p2.x]=p2.origin;
					gaming_print_map(p2.y,p2.x);
					p2.origin=map[p2.y][p2.x+1];
					++p2.x;
					map[p2.y][p2.x]=PLAYER_P2;
					if(p2.origin!=GRASS) gaming_print_map(p2.y,p2.x);
				}

			}
			else if(c==P2_LEFT)
			{
				if( map[p2.y][p2.x-1]==GROUND ||  map[p2.y][p2.x-1]==GRASS)
				{
					map[p2.y][p2.x]=p2.origin;
					gaming_print_map(p2.y,p2.x);
					p2.origin=map[p2.y][p2.x-1];
					--p2.x;
					map[p2.y][p2.x]=PLAYER_P2;
					if(p2.origin!=GRASS) gaming_print_map(p2.y,p2.x);
				}
			}
			else if(c==BULLET_P1_UP)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_UP;
				bp1.on=1;
				bp1.x = p1.x;
				bp1.y = p1.y-1;
			}
			else if(c==BULLET_P1_DOWN)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_DOWN;
				bp1.on=1;
				bp1.x = p1.x;
				bp1.y = p1.y+1;
			}
			else if(c==BULLET_P1_LEFT)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_LEFT;
				bp1.on=1;
				bp1.x = p1.x-1;
				bp1.y = p1.y;
			}
			else if(c==BULLET_P1_RIGHT)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_RIGHT;
				bp1.on=1;
				bp1.x = p1.x+1;
				bp1.y = p1.y;
			}
			else if(c==BULLET_P2_UP)
			{
				bp2.count = 0;
				bp2.vector=BULLET_P2_UP;
				bp2.on=1;
				bp2.x = p2.x;
				bp2.y = p2.y-1;
			}
			else if(c==BULLET_P2_DOWN)
			{
				bp2.count = 0;
				bp2.vector=BULLET_P2_DOWN;
				bp2.on=1;
				bp2.x = p2.x;
				bp2.y = p2.y+1;
			}
			else if(c==BULLET_P2_LEFT)
			{
				bp2.count = 0;
				bp2.vector=BULLET_P2_LEFT;
				bp2.on=1;
				bp2.x = p2.x-1;
				bp2.y = p2.y;
			}
			else if(c==BULLET_P2_RIGHT)
			{
				bp2.count = 0;
				bp2.vector=BULLET_P2_RIGHT;
				bp2.on=1;
				bp2.x = p2.x+1;
				bp2.y = p2.y;
			}

		}
		if(bp1.on == 1 )
		{
			bp1.count++;
			if(bp1.count==100)
			{
				bp1.count = 0;
				if(bp1.vector==BULLET_P1_UP)
				{
					if(map[bp1.y][bp1.x]==BUILDING1)
						continue;
					else if(map[bp1.y-1][bp1.x]==GROUND || map[bp1.y-1][bp1.x]==GRASS)
					{
						bp1.origin=map[bp1.y-1][bp1.x];
						--bp1.y;
						map[bp1.y][bp1.x]=BULLET;
						map[bp1.y+1][bp1.x]=bp1.origin;
						gaming_print_map(bp1.y,bp1.x);
						gaming_print_map(bp1.y+1,bp1.x);
						if(map[bp1.y-1][bp1.x]==PLAYER_P2)
							end();
						else if(map[bp2.y-1][bp2.x]==PLAYER_P1) 
							end();
						else if(map[bp1.y-1][bp1.x]==BUILDING1)
						{
							bp1.on=0;
							map[bp1.y][bp1.x]=bp1.origin;
							gaming_print_map(bp1.y,bp1.x);
						}
					}
				}
				else if(bp1.vector==BULLET_P1_DOWN)
				{
					if(map[bp1.y][bp1.x]==BUILDING1)
						continue;
					else if(map[bp1.y+1][bp1.x]==GROUND || map[bp1.y+1][bp1.x]==GRASS)
					{
						bp1.origin=map[bp1.y+1][bp1.x];
						++bp1.y;
						map[bp1.y][bp1.x]=BULLET;
						map[bp1.y-1][bp1.x]=bp1.origin;
						gaming_print_map(bp1.y,bp1.x);
						gaming_print_map(bp1.y-1,bp1.x);
						if(map[bp1.y+1][bp1.x]==PLAYER_P2) 
							end();
						else if(map[bp2.y+1][bp2.x]==PLAYER_P1) 
							end();
						else if(map[bp1.y+1][bp1.x]==BUILDING1)
						{
							bp1.on=0;
							map[bp1.y][bp1.x]=bp1.origin;
							gaming_print_map(bp1.y,bp1.x);
						}
					}

				}
				else if(bp1.vector==BULLET_P1_LEFT)
				{
					if(map[bp1.y][bp1.x]==BUILDING1)
						continue;
					if(map[bp1.y][bp1.x-1]==GROUND || map[bp1.y][bp1.x-1]==GRASS)
					{
						bp1.origin=map[bp1.y][bp1.x-1];
						--bp1.x;							
						map[bp1.y][bp1.x]=BULLET;
						map[bp1.y][bp1.x+1]=bp1.origin;
						gaming_print_map(bp1.y,bp1.x);
						gaming_print_map(bp1.y,bp1.x+1);
						if(map[bp1.y][bp1.x-1]==PLAYER_P2)
							end();
						else if(map[bp2.y][bp2.x-1]==PLAYER_P1) 
							end();
						else if(map[bp1.y][bp1.x-1]==BUILDING1)
						{
							bp1.on=0;
							map[bp1.y][bp1.x]=bp1.origin;
							gaming_print_map(bp1.y,bp1.x);
						}
					}
				}
				else if(bp1.vector==BULLET_P1_RIGHT)
				{
					if(map[bp1.y][bp1.x]==BUILDING1)
						continue;
					else if(map[bp1.y][bp1.x+1]==GROUND || map[bp1.y][bp1.x+1]==GRASS)
					{
						map[bp1.y][bp1.x]=map[bp1.y][bp1.x+1];
						gaming_print_map(bp1.y,bp1.x);
						bp1.origin=map[bp1.y][bp1.x+1];
						++bp1.x;							
						map[bp1.y][bp1.x]=BULLET;
						map[bp1.y][bp1.x-1]=bp1.origin;
						gaming_print_map(bp1.y,bp1.x-1);
						gaming_print_map(bp1.y,bp1.x);
						if(map[bp1.y][bp1.x+1]==PLAYER_P2) 
							end();
						if(map[bp2.y][bp2.x+1]==PLAYER_P1) 
							end();
						if(map[bp1.y][bp1.x+1]==BUILDING1)
						{
							bp1.on=0;
							map[bp1.y][bp1.x]=bp1.origin;
							gaming_print_map(bp1.y,bp1.x);
						}
					}

				}


			}
		}
		else if(bp2.on == 1) 
		{
			bp2.count++;
			if(bp2.count==100)
			{
				bp2.count = 0;

				if(bp2.vector==BULLET_P2_UP)
				{
					if(map[bp2.y][bp2.x]==BUILDING1)
						continue;
					else if(map[bp2.y-1][bp2.x]==GROUND || map[bp2.y-1][bp2.x]==GRASS)
					{
						bp2.origin=map[bp2.y-1][bp2.x];
						--bp2.y;							
	
						map[bp2.y][bp2.x]=BULLET;
						map[bp2.y+1][bp2.x]=bp2.origin;
						gaming_print_map(bp2.y,bp2.x);
						gaming_print_map(bp2.y+1,bp2.x);
						if(map[bp2.y-1][bp2.x]==PLAYER_P1) 
							end();
						else if(map[bp1.y-1][bp1.x]==PLAYER_P2) 
							end();
						else if(map[bp2.y-1][bp2.x]==BUILDING1)
						{
							bp2.on=0;
							map[bp2.y][bp2.x]=bp2.origin;
							gaming_print_map(bp2.y,bp2.x);
						}
					}
				}
				else if(bp2.vector==BULLET_P2_DOWN)
				{
					if(map[bp2.y][bp2.x]==BUILDING1)
						continue;
					else if(map[bp2.y+1][bp2.x]==GROUND || map[bp2.y+1][bp2.x]==GRASS)
					{
						bp2.origin=map[bp2.y+1][bp2.x];
						++bp2.y;							
	
						map[bp2.y][bp2.x]=BULLET;
						map[bp2.y-1][bp2.x]=bp2.origin;
						gaming_print_map(bp2.y,bp2.x);
						gaming_print_map(bp2.y-1,bp2.x);
						if(map[bp2.y+1][bp2.x]==PLAYER_P1) 
							end();
						else if(map[bp1.y+1][bp1.x]==PLAYER_P2) 
							end();
						else if(map[bp2.y+1][bp2.x]==BUILDING1)
						{
							bp2.on=0;
							map[bp2.y][bp2.x]=bp2.origin;
							gaming_print_map(bp2.y,bp2.x);
						}
					}

				}
				else if(bp2.vector==BULLET_P2_LEFT)
				{
					if(map[bp2.y][bp2.x]==BUILDING1)
						continue;
					else if(map[bp1.y][bp2.x-1]==GROUND || map[bp2.y][bp2.x-1]==GRASS)
					{
						bp2.origin=map[bp2.y][bp2.x-1];
						--bp2.x;	
						map[bp2.y][bp2.x]=BULLET;
						map[bp2.y][bp2.x+1]=bp2.origin;
						gaming_print_map(bp2.y,bp2.x+1);
						gaming_print_map(bp2.y,bp2.x);
						if(map[bp2.y][bp2.x-1]==PLAYER_P1) 
							end();
						else if(map[bp1.y][bp1.x-1]==PLAYER_P2) 
							end();
						else if(map[bp2.y][bp2.x-1]==BUILDING1)
						{
							bp2.on=0;
							map[bp2.y][bp2.x]=bp2.origin;
							gaming_print_map(bp2.y,bp2.x);
						}
					}
				}
				else if(bp2.vector==BULLET_P2_RIGHT)
				{
					if(map[bp2.y][bp2.x]==BUILDING1)
						continue;
					else if(map[bp2.y][bp2.x+1]==GROUND || map[bp2.y][bp2.x+1]==GRASS)
					{
						bp2.origin=map[bp2.y][bp2.x+1];
						++bp2.x;							
						map[bp2.y][bp2.x]=BULLET;
						map[bp2.y][bp2.x-1]=bp2.origin;
						gaming_print_map(bp2.y,bp2.x-1);
						gaming_print_map(bp2.y,bp2.x);
						if(map[bp2.y][bp2.x+1]==PLAYER_P1) 
							end();
						else if(map[bp1.y][bp1.x+1]==PLAYER_P2)
							end();
						else if(map[bp2.y][bp2.x+1]==BUILDING1)
						{
							bp2.on=0;
							map[bp2.y][bp2.x]=bp2.origin;
							gaming_print_map(bp2.y,bp2.x);
						}
					}
				}
			}
		}
	}
}
void start()
{
	int x, y, i;
	char c;

	textcolor(0x0005);
	for(i=0;i<8;i+=2) // C
	{
		Sleep(30);
		gotoxy(12-i,2);
		printf("◆");
	}
	for(i=0;i<1;i++)
	{
		Sleep(30);
		gotoxy(4,3);
		printf("◆");
	}
	for(i=0;i<3;i++)
	{
		Sleep(30);
		gotoxy(3,4+i);
		printf("◆");
	}
	for(i=0;i<1;i++)
	{
		Sleep(30);
		gotoxy(4,7);
		printf("◆");
	}
	for(i=0;i<8;i+=2) 
	{
		Sleep(30);
		gotoxy(6+i,8);
		printf("◆");
	}

	for(i=0;i<7;i++) // R
	{
		Sleep(30);
		gotoxy(16,2+i);
		printf("◆");
	}
	for(i=0;i<6;i+=2)
	{
		Sleep(30);
		gotoxy(18+i,2);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		Sleep(30);
		gotoxy(23,3+i);
		printf("◆");
	}
	for(i=0;i<6;i+=2)
	{
		Sleep(30);
		gotoxy(22-i,5);
		printf("◆");
	}
	for(i=0;i<3;i++)
	{
		Sleep(30);
		gotoxy(23+i,6+i);
		printf("◆");
	} 

	for(i=0;i<1;i++) // A
	{
		Sleep(30);
		gotoxy(33,2);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		Sleep(30);
		gotoxy(32-i,3+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		Sleep(30);
		gotoxy(29,7+i);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		Sleep(30);
		gotoxy(34+i,3+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		Sleep(30);
		gotoxy(37,7+i);
		printf("◆");
	}
	for(i=0;i<5;i+=2)
	{
		Sleep(30);
		gotoxy(31+i,6);
		printf("◆");
	}

	for(i=0; i<10; i+=2) //Z
	{
		Sleep(30);
		gotoxy(41+i,2);
		printf("◆");
	}

	for(i=0; i<5; i++)
	{
		Sleep(30);
		gotoxy(47-i,3+i);
		printf("◆");
	}

	for(i=0; i<10; i+=2)
	{
		Sleep(30);
		gotoxy(41+i,8);
		printf("◆");
	}

	for(i=0;i<4;i++) // Y
	{
		Sleep(30);
		gotoxy(53+i,2+i);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		Sleep(30);
		gotoxy(61-i,2+i);
		printf("◆");
	}
	for(i=0;i<3;i++)
	{
		Sleep(30);
		gotoxy(57,6+i);
		printf("◆");
	}

	textcolor(0x000C);
	Sleep(400);

	for(i=0;i<1;i++) // A
	{
		gotoxy(14,12);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		gotoxy(13-i,13+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		gotoxy(10,17+i);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		gotoxy(15+i,13+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		gotoxy(18,17+i);
		printf("◆");
	}
	for(i=0;i<7;i+=2)
	{
		gotoxy(10+i,16);
		printf("◆");
	}

	Sleep(400);

	for(i=0;i<10;i+=2) // T
	{
		gotoxy(22+i,12);
		printf("◆");
	}
	for(i=0;i<6;i++)
	{
		gotoxy(26,13+i);
		printf("◆");
	}

	Sleep(400);

	for(i=0;i<10;i+=2) // T
	{
		gotoxy(34+i,12);
		printf("◆");
	}
	for(i=0;i<6;i++)
	{
		gotoxy(38,13+i);
		printf("◆");
	}

	Sleep(400);

	for(i=0;i<1;i++) // A
	{
		gotoxy(49,12);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		gotoxy(48-i,13+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		gotoxy(45,17+i);
		printf("◆");
	}
	for(i=0;i<4;i++)
	{
		gotoxy(50+i,13+i);
		printf("◆");
	}
	for(i=0;i<2;i++)
	{
		gotoxy(53,17+i);
		printf("◆");
	}
	for(i=0;i<7;i+=2)
	{
		gotoxy(45+i,16);
		printf("◆");
	}

	Sleep(400);

	for(i=0;i<8;i+=2) // C
	{
		gotoxy(66-i,12);
		printf("◆");
	}
	for(i=0;i<1;i++)
	{
		gotoxy(58,13);
		printf("◆");
	}
	for(i=0;i<3;i++)
	{
		gotoxy(57,14+i);
		printf("◆");
	}
	for(i=0;i<1;i++)
	{
		gotoxy(58,17);
		printf("◆");
	}
	for(i=0;i<8;i+=2) 
	{
		gotoxy(60+i,18);
		printf("◆");
	}

	Sleep(400);

	for(i=0; i<7; i++) //K
	{
		gotoxy(70,12+i);
		printf("◆");
	}
	for(i=0; i<4; i++)
	{
		gotoxy(77-i,12+i);
		printf("◆");
	}
	for(i=0; i<1; i++)
	{
		gotoxy(72,15);
		printf("◆");
	}
	for(i=0; i<3; i++)
	{
		gotoxy(75+i,16+i);
		printf("◆");
	}

	textcolor(0x0007);
	for(i=0; i<5; i++) printf("\n");
	printf("                                press any key...\n");
	while(1){
		if(kbhit())
		{
			c=getch();
			system("cls");
			return;
		}



		//어두운 회색으로 바꾸기 

		textcolor(0x0008);
		Sleep(200);

		for(i=0;i<1;i++) // A
		{
			gotoxy(33,2);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(32-i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(29,7+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(34+i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(37,7+i);
			printf("◆");
		}
		for(i=0;i<5;i+=2)
		{
			gotoxy(31+i,6);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<7;i++) // R
		{
			gotoxy(16,2+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(18+i,2);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(23,3+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(22-i,5);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(23+i,6+i);
			printf("◆");
		} 

		for(i=0; i<10; i+=2) //Z
		{
			gotoxy(41+i,2);
			printf("◆");
		}

		for(i=0; i<5; i++)
		{
			gotoxy(47-i,3+i);
			printf("◆");
		}

		for(i=0; i<10; i+=2)
		{
			gotoxy(41+i,8);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<8;i+=2) // C
		{
			gotoxy(12-i,2);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,3);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(3,4+i);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,7);
			printf("◆");
		}
		for(i=0;i<8;i+=2) 
		{
			gotoxy(6+i,8);
			printf("◆");
		}

		for(i=0;i<4;i++) // Y
		{
			gotoxy(53+i,2+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(61-i,2+i);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(57,6+i);
			printf("◆");
		}

		//밝은 회색으로 바꾸기 

		textcolor(0x0007);
		Sleep(200);

		for(i=0;i<1;i++) // A
		{
			gotoxy(33,2);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(32-i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(29,7+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(34+i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(37,7+i);
			printf("◆");
		}
		for(i=0;i<5;i+=2)
		{
			gotoxy(31+i,6);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<7;i++) // R
		{
			gotoxy(16,2+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(18+i,2);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(23,3+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(22-i,5);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(23+i,6+i);
			printf("◆");
		} 

		for(i=0; i<10; i+=2) //Z
		{
			gotoxy(41+i,2);
			printf("◆");
		}

		for(i=0; i<5; i++)
		{
			gotoxy(47-i,3+i);
			printf("◆");
		}

		for(i=0; i<10; i+=2)
		{
			gotoxy(41+i,8);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<8;i+=2) // C
		{
			gotoxy(12-i,2);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,3);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(3,4+i);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,7);
			printf("◆");
		}
		for(i=0;i<8;i+=2) 
		{
			gotoxy(6+i,8);
			printf("◆");
		}

		for(i=0;i<4;i++) // Y
		{
			gotoxy(53+i,2+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(61-i,2+i);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(57,6+i);
			printf("◆");
		}
		//보라색으로 바꾸기

		textcolor(0x0005);
		Sleep(200);

		for(i=0;i<1;i++) // A
		{
			gotoxy(33,2);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(32-i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(29,7+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(34+i,3+i);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(37,7+i);
			printf("◆");
		}
		for(i=0;i<5;i+=2)
		{
			gotoxy(31+i,6);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<7;i++) // R
		{
			gotoxy(16,2+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(18+i,2);
			printf("◆");
		}
		for(i=0;i<2;i++)
		{
			gotoxy(23,3+i);
			printf("◆");
		}
		for(i=0;i<6;i+=2)
		{
			gotoxy(22-i,5);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(23+i,6+i);
			printf("◆");
		} 

		for(i=0; i<10; i+=2) //Z
		{
			gotoxy(41+i,2);
			printf("◆");
		}

		for(i=0; i<5; i++)
		{
			gotoxy(47-i,3+i);
			printf("◆");
		}

		for(i=0; i<10; i+=2)
		{
			gotoxy(41+i,8);
			printf("◆");
		}

		Sleep(300);

		for(i=0;i<8;i+=2) // C
		{
			gotoxy(12-i,2);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,3);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(3,4+i);
			printf("◆");
		}
		for(i=0;i<1;i++)
		{
			gotoxy(4,7);
			printf("◆");
		}
		for(i=0;i<8;i+=2) 
		{
			gotoxy(6+i,8);
			printf("◆");
		}

		for(i=0;i<4;i++) // Y
		{
			gotoxy(53+i,2+i);
			printf("◆");
		}
		for(i=0;i<4;i++)
		{
			gotoxy(61-i,2+i);
			printf("◆");
		}
		for(i=0;i<3;i++)
		{
			gotoxy(57,6+i);
			printf("◆");
		}

	}
}
void end()
{
	system("cls");
	int x, y, i, j;
	char answer;
	
	//화면 채우기 
	textcolor(0x0006);
	for(i=1; i<26; i++)
	{
		for(j=0; j<39; j++) printf("◆");
		
		printf("\n");
		
		if(i%13==0) textcolor(0x0008);
	}
	
	Sleep(500);
	
	//화면 줄무늬
	for(i=0; i<72; i++)//첫번째 줄 
	{
		textcolor(0);
		Sleep(7);
		gotoxy(4+i,2);
		printf("◆");
	}
	
	for(i=0; i<23; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(75,2+i);
		printf("◆");
	}
	
	for(i=0; i<72; i++)
	{
		textcolor(0);
		Sleep(7);
		gotoxy(75-i,24);
		printf("◆");
	}
	
	for(i=0; i<23; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(3,24-i);
		printf("◆");
	}
	
	for(i=0; i<65; i++)//두번째 줄 
	{
		textcolor(0);
		Sleep(7);
		gotoxy(7+i,4);
		printf("◆");
	}
	
	for(i=0; i<19; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(71,4+i);
		printf("◆");
	}
	
	for(i=0; i<65; i++)
	{
		textcolor(0);
		Sleep(7);
		gotoxy(71-i,22);
		printf("◆");
	}
	
	for(i=0; i<19; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(7,22-i);
		printf("◆");
	}
	
	for(i=0; i<57; i++)//세번째 줄 
	{
		textcolor(0);
		Sleep(7);
		gotoxy(11+i,6);
		printf("◆");
	}
	
	for(i=0; i<15; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(67,6+i);
		printf("◆");
	}
	
	for(i=0; i<57; i++)
	{
		textcolor(0);
		Sleep(7);
		gotoxy(67-i,20);
		printf("◆");
	}
	
	for(i=0; i<15; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(11,20-i);
		printf("◆");
	}
	
	for(i=0; i<49; i++)//네번째 줄 
	{
		textcolor(0);
		Sleep(7);
		gotoxy(15+i,8);
		printf("◆");
	}
	
	for(i=0; i<11; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(63,8+i);
		printf("◆");
	}
	
	for(i=0; i<49; i++)
	{
		textcolor(0);
		Sleep(7);
		gotoxy(63-i,18);
		printf("◆");
	}
	
	for(i=0; i<11; i++)
	{
		textcolor(0);
		Sleep(15);
		gotoxy(15,18-i);
		printf("◆");
	}
	
	//공간 만들기
	textcolor(0);
	for(i=0; i<7; i++)
	{
		Sleep(70);
		for(j=0; j<40; j++) {gotoxy(20+j,10+i); printf("◆"); }
	}
	
	textcolor(0x0007); //It is interesting..?
	gotoxy(30,13);
	printf("I");
	Sleep(100);
 	gotoxy(31,13);
	printf("t");
	Sleep(300);
	
	gotoxy(33,13);
	printf("i");
	Sleep(100);
	gotoxy(34,13);
	printf("s");
	Sleep(300);
	
	gotoxy(36,13);
	printf("i");
	Sleep(100);
	gotoxy(37,13);
	printf("n");
	Sleep(100);
	gotoxy(38,13);
	printf("t");
	Sleep(100);
	gotoxy(39,13);
	printf("e");
	Sleep(100);
	gotoxy(40,13);
	printf("r");
	Sleep(100);
	gotoxy(41,13);
	printf("e");
	Sleep(100);
	gotoxy(42,13);
	printf("s");
	Sleep(100);
	gotoxy(43,13);
	printf("t");
	Sleep(100);
	gotoxy(44,13);
	printf("i");
	Sleep(100);
	gotoxy(44,13);
	printf("n");
	Sleep(100);
	gotoxy(45,13);
	printf("g");
	Sleep(100);
	gotoxy(46,13);
	printf(".");
	Sleep(300);
	gotoxy(47,13);
	printf(".");
	Sleep(300);
	gotoxy(48,13);
	printf("?");
	Sleep(500);
	
	printf("(y/n)  ");
	
	scanf("%c", &answer);
	
	if(answer=='y')
	{
		system("cls");
		
			textcolor(0x000d);
 	
 			gotoxy(39,7);//하트 그리기 
 			printf("◆");
 	
		for(i=0; i<1; i++)
		{
			Sleep(50); 
			gotoxy(37,6);
			printf("◆");
		}
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(35-(2*i),5-i);
			printf("◆");
		}
		
		for(i=0; i<3; i++)
		{
			Sleep(50);
			gotoxy(28-(3*i), 2);
			printf("◆");
		}
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(20-(2*i), 3+i);
			printf("◆");
		}
		
		for(i=0; i<2; i++)
		{
			Sleep(50);
			gotoxy(13-i,7+i);		
			printf("◆");
		}
		
		gotoxy(12,9);
		printf("◆");
		
		gotoxy(12,10);
		printf("◆");
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(13+i,11+i);		
			printf("◆");
		}
		
		for(i=0; i<12; i++)// 한쪽 완성 
		{
			Sleep(50);
			gotoxy(17+(2*i), 15+i);
			printf("◆");
		}
		
		for(i=0; i<12; i++)
		{
			Sleep(50);
			gotoxy(41+(2*i), 26-i);
			printf("◆");
		}
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(64+i, 14-i);
			printf("◆");
		}
		
		gotoxy(68,10);
		printf("◆");
		
		gotoxy(68,9);
		printf("◆");
		
		for(i=0; i<2; i++)
		{
			Sleep(50);
			gotoxy(67-i, 8-i);
			printf("◆");
		}
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(64-(2*i),6-i);
			printf("◆");
		}
		
		for(i=0; i<3; i++)
		{
			Sleep(50);
			gotoxy(56-(3*i),2);
			printf("◆");
		}
		
		for(i=0; i<4; i++)
		{
			Sleep(50);
			gotoxy(48-(2*i),3+i);
			printf("◆");
		}
		
		gotoxy(30,13);//Thank you for have FUN!
		printf("T");
		Sleep(100);
 		gotoxy(31,13);
		printf("h");
		Sleep(100);
		gotoxy(32,13);
		printf("a");
		Sleep(100);
		gotoxy(33,13);
		printf("n");
		Sleep(100);
		gotoxy(34,13);
		printf("k");
		Sleep(300);
		
		gotoxy(36,13);
		printf("y");
		Sleep(100);
		gotoxy(37,13);
		printf("o");
		Sleep(100);
		gotoxy(38,13);
		printf("u");
		Sleep(300);
		
		gotoxy(40,13);
		printf("f");
		Sleep(100);
		gotoxy(41,13);
		printf("o");
		Sleep(100);
		gotoxy(42,13);
		printf("r");
		Sleep(300);
		
		gotoxy(44,13);
		printf("h");
		Sleep(100);
		gotoxy(45,13);
		printf("a");
		Sleep(100);
		gotoxy(46,13);
		printf("v");
		Sleep(100);
		gotoxy(47,13);
		printf("e");
		Sleep(300);
		
		textcolor(0x0007);
		gotoxy(49,13);
		printf("F");
		Sleep(100);
		gotoxy(50,13);
		printf("U");
		Sleep(100);
		gotoxy(51,13);
		printf("N");
		Sleep(100);
		
		textcolor(0x000d);
		gotoxy(52,13);
		printf("!");
		Sleep(200);
		gotoxy(53,13);
		printf("!");
		gotoxy(55,13);
		printf(":D");
		Sleep(500);
		
		for(i=0; i<20; i++)
		{
			printf("\n");
		}
	
	}
	
	else if(answer=='n')
	{
		system("cls");
		
		gotoxy(30,13);//Please enjoy one more time! :(
		printf("P");
		Sleep(100);
 		gotoxy(31,13);
		printf("l");
		Sleep(100);
		gotoxy(32,13);
		printf("e");
		Sleep(100);
		gotoxy(33,13);
		printf("a");
		Sleep(100);
		gotoxy(34,13);
		printf("s");
		Sleep(100);
		gotoxy(35,13);
		printf("e");
		Sleep(300);
		
		gotoxy(37,13);
		printf("e");
		Sleep(100);
		gotoxy(38,13);
		printf("n");
		Sleep(100);
		gotoxy(39,13);
		printf("j");
		Sleep(100);
		gotoxy(40,13);
		printf("o");
		Sleep(100);
		gotoxy(41,13);
		printf("y");
		Sleep(300);
		
		gotoxy(43,13);
		printf("o");
		Sleep(100);
		gotoxy(44,13);
		printf("n");
		Sleep(100);
		gotoxy(45,13);
		printf("e");
		Sleep(300);
		
		gotoxy(47,13);
		printf("m");
		Sleep(100);
		gotoxy(48,13);
		printf("o");
		Sleep(100);
		gotoxy(49,13);
		printf("r");
		Sleep(100);
		gotoxy(50,13);
		printf("e");
		Sleep(300);

		gotoxy(52,13);
		printf("t");
		Sleep(200);
		gotoxy(53,13);
		printf("i");
		gotoxy(54,13);
		printf("m");
		Sleep(100);
		gotoxy(55,13);
		printf("e");
		Sleep(100);
		gotoxy(56,13);
		printf("!");
		Sleep(100);
		gotoxy(58,13);
		printf(":(");
		Sleep(500);
		
		
		game_start();
		end();
		
	}	
}
void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void textcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
