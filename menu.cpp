#include "Team.h"

//-------------------------------------------------
// game �ҽ��� ���� ����
extern int life; // ���
extern int speed; // ���Ӽӵ�
//-------------------------------------------------

//-------------------------------------------------
// menu�� ��������
int num=1; // �޴��� �����ϱ� ���� ����
int num1=1; // ���Ӽ����� �����ϱ� ���� ����
int arrow; // Ű�޴� ������ ����
//-------------------------------------------------

int menu_display() // �޴��� �����ϱ� ���� �Լ�
{

   gotoxy(16, 4);
   printf("��  ������Ʈ");
   gotoxy(13, 6);
   printf("<< �������� ���� >>");
   
   while(1)
   {
      gotoxy(15, 15);
      {
         if(num==1)
         {
            textcolor(11);
            printf("[[ ���ӽ��� ]]");
            textcolor(15);
         }
         else
            printf("[[ ���ӽ��� ]]");
      }
      gotoxy(15, 16);
      {
         if(num==2)
         {
            textcolor(11);
            printf("[[ ���Ӽ��� ]]");
            textcolor(15);
         }
         else
            printf("[[ ���Ӽ��� ]]");
      }
      gotoxy(15, 17);
      {
         if(num==3)
         {
            textcolor(11);
            printf("[[ ���Ӽ��� ]]");
            textcolor(15);
         }
         else
            printf("[[ ���Ӽ��� ]]");
      }
      gotoxy(15, 18);
      {
         if(num==4)
         {
            textcolor(11);
            printf("[[ �� �� �� ]]");
            textcolor(15);
         }
         else
            printf("[[ �� �� �� ]]");
      }
      gotoxy(15, 19);
      {
         if(num==5)
         {
            textcolor(11);
            printf("[[ �������� ]]");
            textcolor(15);
         }
         else
            printf("[[ �������� ]]");
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
A: // �ݺ��� while(1)�� ����� ���� ���
   if(num==1)
      game_start(); // ���ӽ���
   if(num==2)
      game_explain(); // ���Ӽ���
   if(num==3)
      game_set(); // ���Ӽ���
   if(num==4)
      game_maker(); // ������
   if(num==5)
	   exit(1); // ������ �����Ų��.
}
void game_start() // ���ӽ��� �Լ�
{
   systemcls(); // ���� Ʋ �ȿ� ���� �����
   print_shape(); // ������ �����Ű�� �����Լ�
}
void game_explain() // ���Ӽ��� �Լ�
{
   systemcls(); // ���� Ʋ �ȿ� ���� �����
   gotoxy(13,4);
   printf("�������� ���ӹ��");
   gotoxy(6,8);
   printf("����Ű ��,��� ����⸦ �����Ͽ�");
   gotoxy(3,9);
   printf("���� �ñ�鼭 ������ �μ��� �����Դϴ�.");
   gotoxy(6,11);
   printf("������ ���� �������� ������ �Ǹ�");
   gotoxy(8,12);
   printf("�� ��ϻ����� ������ �ٸ���");
   gotoxy(13,13);
   printf("��еǾ� �ֽ��ϴ�.");
   gotoxy(6,15);
   textcolor(9);
   printf("�ââ�");
   gotoxy(13,15);
   textcolor(15);
   printf(": 100 ��");
   gotoxy(6,15);
   textcolor(10);
   gotoxy(23,15);
   printf("�ââ�");
   gotoxy(30,15);
   textcolor(15);
   printf(": 200 ��");
   gotoxy(6,17);
   textcolor(11);
   printf("�ââ�");
   gotoxy(13,17);
   textcolor(15);
   printf(": 300 ��");
   gotoxy(6,17);
   textcolor(12);
   gotoxy(23,17);
   printf("�ââ�");
   gotoxy(30,17);
   textcolor(15);
   printf(": 400 ��");
   textcolor(13);
   gotoxy(6,19);
   printf("�ââ�");
   gotoxy(13,19);
   textcolor(15);
   printf(": 500 ��\n\n\n\n\n");
   gotoxy(4, 21);
   printf("�޴��� ���ư���: M\n\n\n");
   arrow=getch();
   if(arrow==109) // mŰ�� ������
   {
      systemcls(); // ���� Ʋ �ȿ� ���� �����
      menu_display(); // �޴���
   }
}
void game_set() // ���Ӽ��� �Լ�
{
   systemcls(); // ���� Ʋ �ȿ� ���� �����
   gotoxy(13,4);
   printf("���Ӽ���");
   while(1)
   {
      gotoxy(13,10);
      {
         if(num1==1)
         {
            textcolor(11); 
            printf("���     <  %2d  >", life);
            textcolor(15); 
         }
         else
            printf("���     <  %2d  >", life);
      }
     gotoxy(13,12);
      {
         if(num1==2)
         {
            textcolor(11);
            printf("��ü���� ���Ӽӵ�  <  %2d  >", speed);
            textcolor(15);
         }
         else
            printf("��ü���� ���Ӽӵ�  <  %2d  >", speed);
      }
      gotoxy(4, 21);
      {
         if(num1==3)
         {
            textcolor(11);
            printf("�޴��� ���ư���");
            textcolor(15);
         }
         else
            printf("�޴��� ���ư���");
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
A: // �ݺ��� while(1)�� ����� ���� ���
   if(num1==3)
      systemcls(); // ���� Ʋ �ȿ� ���� �����
      menu_display(); // �޴���
 }
void game_maker() // ������ �Լ�
{
   systemcls(); // ���� Ʋ �ȿ� ���� �����
   gotoxy(8, 4);
   printf("�ѳ����б� ��ǻ�Ͱ��а� 2�г�");
   gotoxy(9, 6);
   printf("���α׷��� ���� 02�й�<2��>");
   gotoxy(11, 12);
   printf("����: 20110751 ������");
   gotoxy(11, 14);
   printf("����: 20110748 ������");
   gotoxy(11, 16);
   printf("����: 20112728 �跮��");
   gotoxy(11, 18);
   printf("����: 20110739 ����ȣ");
   gotoxy(4, 21);
   printf("�޴��� ���ư���: M\n\n\n");
   arrow=getch();
   if(arrow==109) // mŰ�� ������
   {
      systemcls(); // ���� Ʋ �ȿ� ���� �����
      menu_display(); // �޴���
   }
}