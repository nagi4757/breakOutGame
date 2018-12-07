#include "Team.h"

void print_frame() // 화면상의 틀을 구성하기 위한 함수
{
   int a,b;
   for(a=0;a<74;a+=2)
      for(b=0;b<24;b++)
         if(a==0 || a==42 || a==72 || b==0 || b==23) // 틀
         {
            gotoxy(a,b);
            textcolor(11);
            printf("※");
            textcolor(15);
         }
       gotoxy(46,20);
        printf("Copyright ⓒ 2014 By nagi");        

        gotoxy(46,21);
        printf("All Program cannot be");        

        gotoxy(46,22);
        printf("copied without permission");
}

void cursor_remove() // 커서를 제거하는 함수
{
	CONSOLE_CURSOR_INFO CurInfo;
   CurInfo.dwSize=1;    
   CurInfo.bVisible=FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); 
}

void textcolor(int color_number) //글자 색 변경 함수
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void systemcls() // system("cls")대신 왼쪽 틀 안의 공백을 덮어 씌우는 함수
{
   int a,b; // 지역변수
   for(a=3;a<42;a++) // 좌측화면
      for(b=3;b<23;b++)
      {
         gotoxy(a,b);
         printf(" ");
      }
}

void gotoxy(int x,int y) // 화면상의 좌표를 이용하기 위한 함수
{ 
   COORD pos={x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
