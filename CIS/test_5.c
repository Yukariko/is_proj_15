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
	int x,y;
};
//총알 구조체(원래위치,이동,스피드,)한발씩 
//총알 입력키 선택 
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
void end(){}
void init();
void game_start();
void print_monster();
void print_player();
int map_select();
void map_type();
void print_map(int num);
const char *get_shape(char code);

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

void map_type() //?? ????
{
	gotoxy(26,26);
	printf("맵 1");
	gotoxy(36,26);
	printf("맵 2");
	gotoxy(46,26);
	printf("맵 3");
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
			if(key == P2_LEFT)
			{
				menu = menu? menu-1 : 2;
			}
			else if(key == P2_RIGHT)
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

const char *get_shape(char code)
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

void gaming_print_map(int y,int x)
{
	gotoxy(get_x(x),get_y(y) );
	printf("%s",get_shape(map[y][x]));
}
void print_map(int num)
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

void game_start()
{
	system("cls");					//게임 시작전 화면 초기화 

	char c;

	init();

	print_map(map_select());  //현준이 메뉴이동을 리턴값으로 수정 요망  

	while(1) //개임 시작중  
	{
		//print_status();
		//print_monster();             //시간조건필요 
		//print_player();
		//print_potion();              //시간조건필요  

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
				bp1.y = p1.y;

			}
			else if(c==BULLET_P1_DOWN)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_DOWN;
				bp1.on=1;
			}


			else if(c==BULLET_P1_LEFT)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_LEFT;
				bp1.on=1;
			}
			else if(c==BULLET_P1_RIGHT)
			{
				bp1.count = 0;
				bp1.vector=BULLET_P1_RIGHT;
				bp1.on=1;
			}
		}
		if(bp1.on == 1)
		{
			bp1.count++;
			if(bp1.count==1000)
			{
				bp1.count = 0;

				if(bp1.vector==BULLET_P1_UP)
				{
					--bp1.y;	
					map[bp1.y][bp1.x]=BULLET;
					if(map[bp1.y][bp1.x]==BUILDING1)
						map[bp1.y][bp1.x]=bp1.origin;
					gaming_print_map(bp1.y-1,bp1.x);
					gaming_print_map(bp1.y,bp1.x);
					
					
				}
			}
		}
	}
}

void print_player()
{
	//gotoxy(1P_respon_x,1P_respon_y);
	puts("1P");

	//gotoxy(2P_respon_x,2P_respon_y);
	puts("2P");


}
void print_monster()
{
	//gotoxy(monster_respon_x,monster_respon_y);
	puts("monster");
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

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void textcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
							
