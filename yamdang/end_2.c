#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
  COORD Pos = { x-1, y-1 };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void textcolor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void end()
{
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
		
		
		//game();
		//end();
		
	}
	
	
	
}

int main()
{
	end();
	
	return 0;
}
