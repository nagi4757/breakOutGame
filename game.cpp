#include "Team.h"

//-------------------------------------------------
// menu 소스의 변수 공유
extern int num; // 메뉴를 조정하기 위한 변수
extern int num1; // 게임설정를 조정하기 위한 변수
//-------------------------------------------------

//-------------------------------------------------
// game의 전역변수
Bricks * top_brick[5][5]; // 벽돌의 배열선언
int score=0; // 점수
int life=3; // 목숨
int speed=0; // 게임속도
char m[] = "□□□"; // 막대기
char s[] = "○"; // 공
//-------------------------------------------------

void print_shape() // 게임을 실행시키는 메인함수
{
   char key; // 키를 받는 변수
   int x1=19, y1=20; // 막대기 x, y좌표 변수
   int x,y,temp; // 공 x, y좌표 변수

   bricks();
   gotoxy(21,19);
   printf("○");
   gotoxy(19,20);
   printf("%s",m);
   gotoxy(21,19);
   printf("  ");

   srand((unsigned)time(NULL));

   x=21; y=19;
   
   temp=rand()%4+1;
   
   do{
         key=getch();
         printf("");
         
       while(!kbhit()){
         if(AllBrickDestroyed()) // 모든 벽돌이 없어질때
   {
	   END_message(); // 게임 끝 메시지
	   getch();
	   system("cls"); // 삭제 프로그램
	   print_frame(); // 화면상의 틀
	   menu_display(); // 메뉴판
   }
          BumpBrick(&x, &y, &temp);
          move(&x,&y,&temp,&x1,&y1);
          print(s,x,y);
          gotoxy(x1,y1);
          move_arrow(key, &x1, &y1, X_MAX, Y_MAX);
          printf("%s",m);
          printf("");

        gotoxy(51,3);
        textcolor(15);
        printf("* 블록깨기 게임 *");

        gotoxy(51,5);
        textcolor(9);
        printf("▣▣▣");
        gotoxy(58,5);
        textcolor(15);
        printf(": 100 점");

        gotoxy(51,7);
        textcolor(10);
        printf("▣▣▣");
        gotoxy(58,7);
        textcolor(15);
        printf(": 200 점");

        gotoxy(51,9);
        textcolor(11);
        printf("▣▣▣");
        gotoxy(58,9);
        textcolor(15);
        printf(": 300 점");

        gotoxy(51,11);
        textcolor(12);
        printf("▣▣▣");
        gotoxy(58,11);
        textcolor(15);
        printf(": 400 점");

        gotoxy(51,13);
        textcolor(13);
        printf("▣▣▣");
        gotoxy(58,13);
        textcolor(15);
        printf(": 500 점");
                
          gotoxy(51,15);
          printf("점수 : %d",score);
          gotoxy(51,17);
          printf("목숨 : %d", life);
      }
   }while(key!=27);

}

void move_arrow(char key, int *x, int *y, int x_b, int y_b) // 막대기를 움직이는 함수
{
   switch(key)
   {
   case LEFT: // ←키를 누를시 왼쪽으로 이동
      *x=*x-1;
      if(*x<1)   *x=1;
      if(*x==1)
         *x=*x+1;
      break;
   case RIGHT: // →키를 누를시 오른쪽으로 이동   
      *x=*x+1;
      if(*x>x_b)   *x=x_b;
      if(*x==37)
         *x=*x-1;
      break;
   default:
      return;
   }
}
void print(char *s,int x,int y) // 출력된 공을 삭제하는 함수
{
   gotoxy(x,y);
   printf("%s",s);
   Sleep(100-speed);
   printf("\b\b  ");
}
void move(int *x,int *y,int *t, int *x1, int *y1) // 공을 움직이는 함수
{
   
   switch(*t)
   {
   case 0:
      *x = *x; *y = *y;
      case 1: // 공이 ↖으로 틀에 부딪일때 ↙으로 방향을 바꾼다.
      (*x)-=2; (*y)--; 
      if(*x<2) { *x=2; *t=2; } 
      if(*y<1) { *y=2; *t=4; }
      break;
      case 2: // 공이↗으로 틀에 부딪일때 ↘으로 방향을 바꾼다.
         (*x)+=2; (*y)--; 
      if(*x>40) { *x=40; *t=1; }
      if(*y<1) { *y=2; *t=3; }
      break;
   case 3: // 공이 ↘으로 틀이나 막대기에 부딪일때 ↗으로 방향을 바꾼다.
      (*x)+=2; (*y)++;
      if(*x>40) { *x=40; *t=4; }
      if(*y>22) // 공이 막대기 보다 y좌표 밑에 갈 경우 실행되는 조건
     {
		 gotoxy(21,19);
		 printf("○");
		 gotoxy(19,20);
		 printf("%s",m);
		 gotoxy(1, 1);
		 gotoxy(*x1, *y1);
		 printf("      ");
		 *x1 = 19; *y1 = 20;
		 *x = 21; *y = 19; *t = 0;
		 life--;
   

   if(life==0) // 목숨이 0일때
   {
	   dead_message(); // 죽음 메시지
	   getch();
	   system("cls"); // 삭제 프로그램
	   print_frame(); // 화면상의 틀
	   menu_display(); // 메뉴판
   }
	  }
	  if(*x1-1 <= *x && *x <= *x1+5 && *y==*y1) // 공이 막대기에 부딪일때 ↗으로 방향 적용
     { *x=*x;*y=*y1-1;  *t=2; }
	  break;
   case 4: // 공이 ↙으로 틀이나 막대기에 부딪일때 ↖으로 방향을 바꾼다.
      (*x)-=2; (*y)++; 
	  if(*x<2) { *x=2; *t=3; }
      if(*y>22) // 공이 막대기 보다 y좌표 밑에 갈 경우 실행되는 조건
	  {
		  gotoxy(21,19);
		  printf("○");
		  gotoxy(19,20);
		  printf("%s",m);
		  gotoxy(1, 1);
		  gotoxy(*x1, *y1);
		  printf("      ");
		  *x1 = 19; *y1 = 20;
		  *x = 21; *y = 19; *t = 0;
		  life--;
  
		  if(life==0) // 목숨을 0일때
		  {
			  dead_message(); // 죽음 메시지
			  getch();
			  system("cls"); // 삭제 프로그램
			  print_frame(); // 화면상의 틀
			  menu_display(); // 메뉴판
		  }
	  }
	  if( *x1-1 <= *x && *x <= *x1+5 && *y==*y1) // 공이 막대기에 부딪일때 ↖으로 방향 적용
	  {*x=*x;*y=*y-1; *t=1; }
	  break;
   }
}
void END_message() // 게임이 끝날때 출력하는 메시지 함수
{
   gotoxy(3,7);
   printf("┏━━━━━━━━━━━━━━━━━┓");
   gotoxy(3,8);
   printf("┃　　　　   GAME　　END　　　　    ┃");
   gotoxy(3,9);
   printf("┃　　　　   축하합니다!!　　　　   ┃");
   gotoxy(3,10);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,11);
   printf("┃　　　　   점 수 : %5d　　      ┃",score);
   gotoxy(3,12);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,13);
   printf("┃　　　　 아무키나 누르세요        ┃");
   gotoxy(3,14);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,15);
   printf("┃　　　　 메뉴로 이동합니다. 　　  ┃");
   gotoxy(3,16);
   printf("┗━━━━━━━━━━━━━━━━━┛");
   life=3; // 목숨 초기화
   score=0; // 점수 초기화
   num=1; // 메뉴판 정수형 변수 초기화
   num1=1; // 게임설정 정수형 변수 초기화
}
void dead_message() // 죽을때 출력하는 메시지 함수
{
   gotoxy(3,7);
   printf("┏━━━━━━━━━━━━━━━━━┓");
   gotoxy(3,8);
   printf("┃　　　　   GAME　　OVER　　　　   ┃");
   gotoxy(3,9);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,10);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,11);
   printf("┃　　　　   점 수 : %5d　　      ┃",score);
   gotoxy(3,12);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,13);
   printf("┃　　　　 아무키나 누르세요        ┃");
   gotoxy(3,14);
   printf("┃　　　　   　　　　               ┃");
   gotoxy(3,15);
   printf("┃　　　　 메뉴로 이동합니다. 　　  ┃");
   gotoxy(3,16);
   printf("┗━━━━━━━━━━━━━━━━━┛");
   life=3; // 목숨 초기화
   score=0; // 점수 초기화
   num=1; // 메뉴판 정수형 변수 초기화
   num1=1; // 게임설정 정수형 변수 초기화
}

void BricksInIt(Bricks * brick, int i, int j) // 벽돌을 생성하는 함수
{
   brick->x = "▣▣▣"; // 벽돌의 모양
   brick->xpos = i; // 벽돌 x좌표 
   brick->ypos = j; // 벽돌 y좌표
   brick->color = rand()%5+9; // 블록의 색깔을 랜덤으로 지정
   brick->score = (brick->color-8)*100; // 색깔마다 점수를 지정
   brick->exist = 1; // 벽돌이 존재할때 1 반환
}

void bricks() // 벽돌 메인함수
{
   int i, j; // 지역변수
   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         Bricks * nbricks = (Bricks * )malloc(sizeof(Bricks)); 
         BricksInIt(nbricks, 5+j*7, 2+i);
         top_brick[i][j] = nbricks; // 메모리를 동적할당시켜 to_brick배열에 저장
      }
   }

   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         gotoxy(5 + j*7, 2+i);
       textcolor(top_brick[i][j]->color); // 벽돌의 색 변경
         printf("%s", top_brick[i][j]->x); // 벽돌 출력
       textcolor(WHITE);
      }
   }
}

void BumpBrick(int *x, int *y, int * temp) // 벽돌 파괴 및 부딪칠때 움직을 바꾸는 함수
{
   int i, j;// 지역변수

   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         if(*x >= top_brick[i][j]->xpos-1 && *x <= top_brick[i][j]->xpos+6 && *y == top_brick[i][j]->ypos)
         { // 공이 벽돌을 부딪칠 경우
            
            top_brick[i][j]->x = NULL; // 벽돌의 모양 제거
			top_brick[i][j]->exist = 0; // 벽돌이 존재하지 않을 경우 0 반환
            gotoxy(top_brick[i][j]->xpos, top_brick[i][j]->ypos); 
            printf("      "); // 공백 씌우기
            switch(*temp)
            {
            case 1: // ↖방향으로 공이 벽돌에 팅길시 ↙으로 방향을 바꾸어준다.
               *temp = 4;
               break;
            case 2: // ↗방향으로 공이 벽돌에 팅길시 ↘으로 방향을 바꾸어준다.
               *temp = 3;
               break;
            case 3: // ↘방향으로 공이 벽돌에 팅길시 ↗으로 방향을 바꾸어준다.
               *temp = 2;
               break;
            case 4: // ↙방향으로 공이 벽돌에 팅길시 ↖으로 방향을 바꾸어준다.
               *temp = 1;
               break;
            }
            top_brick[i][j]->xpos = NULL; // 벽돌 x좌표 제거
            top_brick[i][j]->ypos = NULL; // 벽돌 y좌표 제거

         score+=top_brick[i][j]->score; // 색깔마다 점수 배정

            return;
         }
      }
   }

}

int AllBrickDestroyed() // 모든 벽돌이 없어지는 경우를 확인하는 함수
{
   int i, j;// 지역변수

   for(i=0; i<5; i++)
    {
      for(j=0; j<5; j++)
       {
         if(top_brick[i][j]->exist == 1) // 벽돌이 존재할시 
            return 0; // 0 반환
      }
   }
   return 1; // 1반환
} 