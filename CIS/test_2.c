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
#define HP 5
#define bullet 50
#define p2_LEFT 97
#define p2_RIGHT 100
#define p2_UP 119
#define p2_DOWN 115
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
int swap(int *before,int *after)
{
	int temp;
	temp=*before;
	*before=*after;
	*after=temp;
}
struct player
{
	int bullet_count;
	int heart;
	int x,y;
};

struct player p1,p2;
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

void init()
{
	p1.heart=5;
	p2.heart=5;
	p1.x=10;
	p1.y=10;
	p2.x=5;
	p2.y=5;
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
}

int get_x(int x)
{
	return BASE+x*XSI;
}
int get_y(int y)
{
	return BASE+y*YSI;
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
			gotoxy(get_x(j),get_y(i) );
			printf("%s",get_shape(map[i][j]));
		}
	}
}
void gaming_print_map(int y,int x)
{
	printf("%s",get_shape(map[y][x]));
}
void game_start()
{
	system("cls");					//게임 시작전 화면 초기화 

	char c;

	init();

	print_map(map_select());  //현준이 메뉴이동을 리턴값으로 수정 요망  
	gotoxy(get_x(1),get_y(SERO-2));
	printf("●");
	while(1) //개임 시작중  
	{
		//print_status();
		//print_monster();             //시간조건필요 
		//print_player();
		//print_potion();              //시간조건필요  

		while (kbhit()) 
		{   //키 받기 
			//gotoxy(get_x(p1.x),get_y(p1.y));
			//printf("%s",get_shape(GROUND));
			c=getch();
			if(c==UP)
			{
				if(map[p1.y][p1.x]==GROUND && map[p1.y-1][p1.x]==GROUND0 || map[p1.y][p1.x]==GRASS && map[p1.y-1][p1.x]==GRASS)
				{
					swap(&map[p1.y-1][p1.x],&map[p1.y][p1.x]);
					map[p1.y-1][p1.x]=PLAYER_P1;
					--p1.y;
				}
				else if(map[p1.y][p1.x]==GROUND && map[p1.y-1][p1.x]==GRASS)
				{
					map[p1.y-1][p1.x]=GRASS;
					map[p1.y][p1.x]=GROUND;
					--p1.y;
				}
				else if(map[p1.y][p1.x]==GRASS && map[p1.y-1][p1.x]==GROUND)
				{
					map[p1.y-1][p1.x]=PLAYER_P1;
					map[p1.y][p1.x]=GRASS;
					--p1.y;
				}

				gaming_print_map(p1.y,p1.x);
				gaming_print_map(p1.y-1,p1.x);

			}
			else if(c==DOWN)
			{
				if(map[p1.y][p1.x]==GROUND && map[p1.y+1][p1.x]==GROUND || map[p1.y][p1.x]==GRASS && map[p1.y+1][p1.x]==GRASS)
				{
					swap(&map[p1.y+1][p1.x],&map[p1.y][p1.x]);
					map[p1.y+1][p1.x]=PLAYER_P1;
					++p1.y;
				}
				else if(map[p1.y][p1.x]==GROUND && map[p1.y+1][p1.x]==GRASS)
				{
					map[p1.y+1][p1.x]=GRASS;
					map[p1.y][p1.x]=GROUND;
					++p1.y;
				}
				else if(map[p1.y][p1.x]==GRASS && map[p1.y+1][p1.x]==GROUND)
				{
					map[p1.y+1][p1.x]=PLAYER_P1;
					map[p1.y][p1.x]=GRASS;
					++p1.y;
				}

				gaming_print_map(p1.y,p1.x);
				gaming_print_map(p1.y+1,p1.x);
			}
			else if(c==RIGHT)
			{

				if(map[p1.y][p1.x]==GROUND && map[p1.y][p1.x+1]==GROUND || map[p1.y][p1.x]==GRASS && map[p1.y][p1.x+1]==GRASS)
				{
					swap(&map[p1.y][p1.x+1],&map[p1.y][p1.x]);
					map[p1.y][p1.x+1]=PLAYER_P1;
					++p1.x;
				}
				else if(map[p1.y][p1.x]==GROUND && map[p1.y][p1.x+1]==GRASS)
				{
					map[p1.y][p1.x+1]=GRASS;
					map[p1.y][p1.x]=GROUND;
					++p1.x;
				}
				else if(map[p1.y][p1.x]==GRASS && map[p1.y][p1.x+1]==GROUND)
				{
					map[p1.y][p1.x+1]=PLAYER_P1;
					map[p1.y][p1.x]=GRASS;
					++p1.x;
				}

				gaming_print_map(p1.y,p1.x);
				gaming_print_map(p1.y,p1.x+1);
			}
			else if(c==LEFT)
			{
				if(map[p1.y][p1.x]==GROUND && map[p1.y][p1.x-1]==GROUND || map[p1.y][p1.x]==GRASS && map[p1.y][p1.x-1]==GRASS)
				{
					swap(&map[p1.y][p1.x-1],&map[p1.y][p1.x]);
					map[p1.y][p1.x-1]=PLAYER_P1;
					--p1.x;
				}
				else if(map[p1.y][p1.x]==GROUND && map[p1.y][p1.x-1]==GRASS)
				{
					map[p1.y][p1.x-1]=GRASS;
					map[p1.y][p1.x]=GROUND;
					--p1.x;
				}
				else if(map[p1.y][p1.x]==GRASS && map[p1.y][p1.x-1]==GROUND)
				{
					map[p1.y][p1.x-1]=PLAYER_P1;
					map[p1.y][p1.x]=GRASS;
					--p1.x;
				}

				gaming_print_map(p1.y,p1.x);
				gaming_print_map(p1.y,p1.x-1);
			}
			gotoxy(get_x(p1.x),get_y(p1.y));
			printf("●");
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
