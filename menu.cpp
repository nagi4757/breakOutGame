#include "Team.h"

//-------------------------------------------------
// game 소스의 변수 공유
extern int life; // 목숨
extern int speed; // 게임속도
//-------------------------------------------------

//-------------------------------------------------
// menu의 전역변수
int num=1; // 메뉴를 조정하기 위한 변수
int num1=1; // 게임설정를 조정하기 위한 변수
int arrow; // 키받는 정수형 변수
//-------------------------------------------------

int menu_display() // 메뉴를 구성하기 위한 함수
{

   gotoxy(16, 4);
   printf("팀  프로젝트");
   gotoxy(13, 6);
   printf("<< 벽돌깨기 게임 >>");
   
   while(1)
   {
      gotoxy(15, 15);
      {
         if(num==1)
         {
            textcolor(11);
            printf("[[ 게임시작 ]]");
            textcolor(15);
         }
         else
            printf("[[ 게임시작 ]]");
      }
      gotoxy(15, 16);
      {
         if(num==2)
         {
            textcolor(11);
            printf("[[ 게임설명 ]]");
            textcolor(15);
         }
         else
            printf("[[ 게임설명 ]]");
      }
      gotoxy(15, 17);
      {
         if(num==3)
         {
            textcolor(11);
            printf("[[ 게임설정 ]]");
            textcolor(15);
         }
         else
            printf("[[ 게임설정 ]]");
      }
      gotoxy(15, 18);
      {
         if(num==4)
         {
            textcolor(11);
            printf("[[ 제 작 자 ]]");
            textcolor(15);
         }
         else
            printf("[[ 제 작 자 ]]");
      }
      gotoxy(15, 19);
      {
         if(num==5)
         {
            textcolor(11);
            printf("[[ 게임종료 ]]");
            textcolor(15);
         }
         else
            printf("[[ 게임종료 ]]");
      }
      arrow=getch();
      if(arrow==UP)
      {
         if(num==1)
            num=5;
         else
            num--;
      }
      else if(arrow==DOWN)
      {
         if(num==5)
            num=1;
         else
            num++;
      }
      else if(arrow==ENTER)
      {
         switch(num)
         {
         case 1: 
            goto A;
            break;
         case 2: 
            goto A;
            break;
         case 3: 
            goto A;
            break;
         case 4: 
            goto A;
            break;
         default : 
            goto A;
            break;
         }
      }
   }
A: // 반복문 while(1)를 벗어나기 위해 사용
   if(num==1)
      game_start(); // 게임시작
   if(num==2)
      game_explain(); // 게임설명
   if(num==3)
      game_set(); // 게임설정
   if(num==4)
      game_maker(); // 제작자
   if(num==5)
	   exit(1); // 게임을 종료시킨다.
}
void game_start() // 게임시작 함수
{
   systemcls(); // 왼쪽 틀 안에 공백 씌우기
   print_shape(); // 게임을 실행시키는 메인함수
}
void game_explain() // 게임설명 함수
{
   systemcls(); // 왼쪽 틀 안에 공백 씌우기
   gotoxy(13,4);
   printf("벽돌깨기 게임방법");
   gotoxy(6,8);
   printf("향키 좌,우로 막대기를 조정하여");
   gotoxy(3,9);
   printf("공을 팅기면서 벽돌을 부수는 게임입니다.");
   gotoxy(6,11);
   printf("벽돌의 색은 랜덤으로 생성이 되며");
   gotoxy(8,12);
   printf("각 블록색마다 점수가 다르게");
   gotoxy(13,13);
   printf("배분되어 있습니다.");
   gotoxy(6,15);
   textcolor(9);
   printf("▣▣▣");
   gotoxy(13,15);
   textcolor(15);
   printf(": 100 점");
   gotoxy(6,15);
   textcolor(10);
   gotoxy(23,15);
   printf("▣▣▣");
   gotoxy(30,15);
   textcolor(15);
   printf(": 200 점");
   gotoxy(6,17);
   textcolor(11);
   printf("▣▣▣");
   gotoxy(13,17);
   textcolor(15);
   printf(": 300 점");
   gotoxy(6,17);
   textcolor(12);
   gotoxy(23,17);
   printf("▣▣▣");
   gotoxy(30,17);
   textcolor(15);
   printf(": 400 점");
   textcolor(13);
   gotoxy(6,19);
   printf("▣▣▣");
   gotoxy(13,19);
   textcolor(15);
   printf(": 500 점\n\n\n\n\n");
   gotoxy(4, 21);
   printf("메뉴로 돌아가기: M\n\n\n");
   arrow=getch();
   if(arrow==109) // m키를 누를시
   {
      systemcls(); // 왼쪽 틀 안에 공백 씌우기
      menu_display(); // 메뉴판
   }
}
void game_set() // 게임설정 함수
{
   systemcls(); // 왼쪽 틀 안에 공백 씌우기
   gotoxy(13,4);
   printf("게임설정");
   while(1)
   {
      gotoxy(13,10);
      {
         if(num1==1)
         {
            textcolor(11); 
            printf("목숨     <  %2d  >", life);
            textcolor(15); 
         }
         else
            printf("목숨     <  %2d  >", life);
      }
     gotoxy(13,12);
      {
         if(num1==2)
         {
            textcolor(11);
            printf("전체적인 게임속도  <  %2d  >", speed);
            textcolor(15);
         }
         else
            printf("전체적인 게임속도  <  %2d  >", speed);
      }
      gotoxy(4, 21);
      {
         if(num1==3)
         {
            textcolor(11);
            printf("메뉴로 돌아가기");
            textcolor(15);
         }
         else
            printf("메뉴로 돌아가기");
      }
     arrow=getch();
      if(arrow==UP)
      {
         if(num1==1)
            num1=3;
         else
            num1--;
      }
      else if(arrow==DOWN)
      {
         if(num1==3)
            num1=1;
         else
            num1++;
      }
     else if(arrow==ENTER)
      {
         switch(num1)
         {
         case 3: 
            goto A;
            break;
       }
     }
     else if(arrow==LEFT)
     {
        switch(num1)
        {
        case 1:
           if(life>0)
           life--;
           break;
        case 2:
           if(speed>0)
           speed-=10;
           break;
        }
     }

        else if(arrow==RIGHT)
        {
            
           switch(num1)
        {
           case 1:
              if(life<=6)
              life++;
              break;
           case 2:
              if(speed<=50)
              speed+=10;
              break;
           }
     }
   }
A: // 반복문 while(1)를 벗어나기 위해 사용
   if(num1==3)
      systemcls(); // 왼쪽 틀 안에 공백 씌우기
      menu_display(); // 메뉴판
 }
void game_maker() // 제작자 함수
{
   systemcls(); // 왼쪽 틀 안에 공백 씌우기
   gotoxy(4, 21);
   printf("메뉴로 돌아가기: M\n\n\n");
   arrow=getch();
   if(arrow==109) // m키를 누를시
   {
      systemcls(); // 왼쪽 틀 안에 공백 씌우기
      menu_display(); // 메뉴판
   }
}
