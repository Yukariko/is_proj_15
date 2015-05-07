#include <stdio.h>

#include <conio.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y)
{
  COORD Pos = { x-1, y-1 };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void textcolor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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

int main()
{
	start();
	while(1)
	{
		int select = map_select();
		init(select);
		game_start();
		if(!game_continue())
		{
			break;
		}
	}
	end();
	return 0;
}
