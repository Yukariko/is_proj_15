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
    
    textcolor(0x0004);
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
	
	system("cls");
}

int main()
{
	start();
	
	system("pause");
	return 0;
}

