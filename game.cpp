#include "Team.h"

//-------------------------------------------------
// menu �ҽ��� ���� ����
extern int num; // �޴��� �����ϱ� ���� ����
extern int num1; // ���Ӽ����� �����ϱ� ���� ����
//-------------------------------------------------

//-------------------------------------------------
// game�� ��������
Bricks * top_brick[5][5]; // ������ �迭����
int score=0; // ����
int life=3; // ���
int speed=0; // ���Ӽӵ�
char m[] = "����"; // �����
char s[] = "��"; // ��
//-------------------------------------------------

void print_shape() // ������ �����Ű�� �����Լ�
{
   char key; // Ű�� �޴� ����
   int x1=19, y1=20; // ����� x, y��ǥ ����
   int x,y,temp; // �� x, y��ǥ ����

   bricks();
   gotoxy(21,19);
   printf("��");
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
         if(AllBrickDestroyed()) // ��� ������ ��������
   {
	   END_message(); // ���� �� �޽���
	   getch();
	   system("cls"); // ���� ���α׷�
	   print_frame(); // ȭ����� Ʋ
	   menu_display(); // �޴���
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
        printf("* ��ϱ��� ���� *");

        gotoxy(51,5);
        textcolor(9);
        printf("�ââ�");
        gotoxy(58,5);
        textcolor(15);
        printf(": 100 ��");

        gotoxy(51,7);
        textcolor(10);
        printf("�ââ�");
        gotoxy(58,7);
        textcolor(15);
        printf(": 200 ��");

        gotoxy(51,9);
        textcolor(11);
        printf("�ââ�");
        gotoxy(58,9);
        textcolor(15);
        printf(": 300 ��");

        gotoxy(51,11);
        textcolor(12);
        printf("�ââ�");
        gotoxy(58,11);
        textcolor(15);
        printf(": 400 ��");

        gotoxy(51,13);
        textcolor(13);
        printf("�ââ�");
        gotoxy(58,13);
        textcolor(15);
        printf(": 500 ��");
                
          gotoxy(51,15);
          printf("���� : %d",score);
          gotoxy(51,17);
          printf("��� : %d", life);
      }
   }while(key!=27);

}

void move_arrow(char key, int *x, int *y, int x_b, int y_b) // ����⸦ �����̴� �Լ�
{
   switch(key)
   {
   case LEFT: // ��Ű�� ������ �������� �̵�
      *x=*x-1;
      if(*x<1)   *x=1;
      if(*x==1)
         *x=*x+1;
      break;
   case RIGHT: // ��Ű�� ������ ���������� �̵�   
      *x=*x+1;
      if(*x>x_b)   *x=x_b;
      if(*x==37)
         *x=*x-1;
      break;
   default:
      return;
   }
}
void print(char *s,int x,int y) // ��µ� ���� �����ϴ� �Լ�
{
   gotoxy(x,y);
   printf("%s",s);
   Sleep(100-speed);
   printf("\b\b  ");
}
void move(int *x,int *y,int *t, int *x1, int *y1) // ���� �����̴� �Լ�
{
   
   switch(*t)
   {
   case 0:
      *x = *x; *y = *y;
      case 1: // ���� ������ Ʋ�� �ε��϶� ������ ������ �ٲ۴�.
      (*x)-=2; (*y)--; 
      if(*x<2) { *x=2; *t=2; } 
      if(*y<1) { *y=2; *t=4; }
      break;
      case 2: // ���̢����� Ʋ�� �ε��϶� ������ ������ �ٲ۴�.
         (*x)+=2; (*y)--; 
      if(*x>40) { *x=40; *t=1; }
      if(*y<1) { *y=2; *t=3; }
      break;
   case 3: // ���� ������ Ʋ�̳� ����⿡ �ε��϶� ������ ������ �ٲ۴�.
      (*x)+=2; (*y)++;
      if(*x>40) { *x=40; *t=4; }
      if(*y>22) // ���� ����� ���� y��ǥ �ؿ� �� ��� ����Ǵ� ����
     {
		 gotoxy(21,19);
		 printf("��");
		 gotoxy(19,20);
		 printf("%s",m);
		 gotoxy(1, 1);
		 gotoxy(*x1, *y1);
		 printf("      ");
		 *x1 = 19; *y1 = 20;
		 *x = 21; *y = 19; *t = 0;
		 life--;
   

   if(life==0) // ����� 0�϶�
   {
	   dead_message(); // ���� �޽���
	   getch();
	   system("cls"); // ���� ���α׷�
	   print_frame(); // ȭ����� Ʋ
	   menu_display(); // �޴���
   }
	  }
	  if(*x1-1 <= *x && *x <= *x1+5 && *y==*y1) // ���� ����⿡ �ε��϶� ������ ���� ����
     { *x=*x;*y=*y1-1;  *t=2; }
	  break;
   case 4: // ���� ������ Ʋ�̳� ����⿡ �ε��϶� ������ ������ �ٲ۴�.
      (*x)-=2; (*y)++; 
	  if(*x<2) { *x=2; *t=3; }
      if(*y>22) // ���� ����� ���� y��ǥ �ؿ� �� ��� ����Ǵ� ����
	  {
		  gotoxy(21,19);
		  printf("��");
		  gotoxy(19,20);
		  printf("%s",m);
		  gotoxy(1, 1);
		  gotoxy(*x1, *y1);
		  printf("      ");
		  *x1 = 19; *y1 = 20;
		  *x = 21; *y = 19; *t = 0;
		  life--;
  
		  if(life==0) // ����� 0�϶�
		  {
			  dead_message(); // ���� �޽���
			  getch();
			  system("cls"); // ���� ���α׷�
			  print_frame(); // ȭ����� Ʋ
			  menu_display(); // �޴���
		  }
	  }
	  if( *x1-1 <= *x && *x <= *x1+5 && *y==*y1) // ���� ����⿡ �ε��϶� ������ ���� ����
	  {*x=*x;*y=*y-1; *t=1; }
	  break;
   }
}
void END_message() // ������ ������ ����ϴ� �޽��� �Լ�
{
   gotoxy(3,7);
   printf("��������������������������������������");
   gotoxy(3,8);
   printf("����������   GAME����END��������    ��");
   gotoxy(3,9);
   printf("����������   �����մϴ�!!��������   ��");
   gotoxy(3,10);
   printf("����������   ��������               ��");
   gotoxy(3,11);
   printf("����������   �� �� : %5d����      ��",score);
   gotoxy(3,12);
   printf("����������   ��������               ��");
   gotoxy(3,13);
   printf("���������� �ƹ�Ű�� ��������        ��");
   gotoxy(3,14);
   printf("����������   ��������               ��");
   gotoxy(3,15);
   printf("���������� �޴��� �̵��մϴ�. ����  ��");
   gotoxy(3,16);
   printf("��������������������������������������");
   life=3; // ��� �ʱ�ȭ
   score=0; // ���� �ʱ�ȭ
   num=1; // �޴��� ������ ���� �ʱ�ȭ
   num1=1; // ���Ӽ��� ������ ���� �ʱ�ȭ
}
void dead_message() // ������ ����ϴ� �޽��� �Լ�
{
   gotoxy(3,7);
   printf("��������������������������������������");
   gotoxy(3,8);
   printf("����������   GAME����OVER��������   ��");
   gotoxy(3,9);
   printf("����������   ��������               ��");
   gotoxy(3,10);
   printf("����������   ��������               ��");
   gotoxy(3,11);
   printf("����������   �� �� : %5d����      ��",score);
   gotoxy(3,12);
   printf("����������   ��������               ��");
   gotoxy(3,13);
   printf("���������� �ƹ�Ű�� ��������        ��");
   gotoxy(3,14);
   printf("����������   ��������               ��");
   gotoxy(3,15);
   printf("���������� �޴��� �̵��մϴ�. ����  ��");
   gotoxy(3,16);
   printf("��������������������������������������");
   life=3; // ��� �ʱ�ȭ
   score=0; // ���� �ʱ�ȭ
   num=1; // �޴��� ������ ���� �ʱ�ȭ
   num1=1; // ���Ӽ��� ������ ���� �ʱ�ȭ
}

void BricksInIt(Bricks * brick, int i, int j) // ������ �����ϴ� �Լ�
{
   brick->x = "�ââ�"; // ������ ���
   brick->xpos = i; // ���� x��ǥ 
   brick->ypos = j; // ���� y��ǥ
   brick->color = rand()%5+9; // ����� ������ �������� ����
   brick->score = (brick->color-8)*100; // ���򸶴� ������ ����
   brick->exist = 1; // ������ �����Ҷ� 1 ��ȯ
}

void bricks() // ���� �����Լ�
{
   int i, j; // ��������
   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         Bricks * nbricks = (Bricks * )malloc(sizeof(Bricks)); 
         BricksInIt(nbricks, 5+j*7, 2+i);
         top_brick[i][j] = nbricks; // �޸𸮸� �����Ҵ���� to_brick�迭�� ����
      }
   }

   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         gotoxy(5 + j*7, 2+i);
       textcolor(top_brick[i][j]->color); // ������ �� ����
         printf("%s", top_brick[i][j]->x); // ���� ���
       textcolor(WHITE);
      }
   }
}

void BumpBrick(int *x, int *y, int * temp) // ���� �ı� �� �ε�ĥ�� ������ �ٲٴ� �Լ�
{
   int i, j;// ��������

   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         if(*x >= top_brick[i][j]->xpos-1 && *x <= top_brick[i][j]->xpos+6 && *y == top_brick[i][j]->ypos)
         { // ���� ������ �ε�ĥ ���
            
            top_brick[i][j]->x = NULL; // ������ ��� ����
			top_brick[i][j]->exist = 0; // ������ �������� ���� ��� 0 ��ȯ
            gotoxy(top_brick[i][j]->xpos, top_brick[i][j]->ypos); 
            printf("      "); // ���� �����
            switch(*temp)
            {
            case 1: // �ع������� ���� ������ �ñ�� ������ ������ �ٲپ��ش�.
               *temp = 4;
               break;
            case 2: // �ֹ������� ���� ������ �ñ�� ������ ������ �ٲپ��ش�.
               *temp = 3;
               break;
            case 3: // �ٹ������� ���� ������ �ñ�� ������ ������ �ٲپ��ش�.
               *temp = 2;
               break;
            case 4: // �׹������� ���� ������ �ñ�� ������ ������ �ٲپ��ش�.
               *temp = 1;
               break;
            }
            top_brick[i][j]->xpos = NULL; // ���� x��ǥ ����
            top_brick[i][j]->ypos = NULL; // ���� y��ǥ ����

         score+=top_brick[i][j]->score; // ���򸶴� ���� ����

            return;
         }
      }
   }

}

int AllBrickDestroyed() // ��� ������ �������� ��츦 Ȯ���ϴ� �Լ�
{
   int i, j;// ��������

   for(i=0; i<5; i++)
    {
      for(j=0; j<5; j++)
       {
         if(top_brick[i][j]->exist == 1) // ������ �����ҽ� 
            return 0; // 0 ��ȯ
      }
   }
   return 1; // 1��ȯ
} 