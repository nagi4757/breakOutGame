#include "Team.h"

void print_frame() // ȭ����� Ʋ�� �����ϱ� ���� �Լ�
{
   int a,b;
   for(a=0;a<74;a+=2)
      for(b=0;b<24;b++)
         if(a==0 || a==42 || a==72 || b==0 || b==23) // Ʋ
         {
            gotoxy(a,b);
            textcolor(11);
            printf("��");
            textcolor(15);
         }
       gotoxy(46,20);
        printf("Copyright �� 2014 By nagi");        

        gotoxy(46,21);
        printf("All Program cannot be");        

        gotoxy(46,22);
        printf("copied without permission");
}

void cursor_remove() // Ŀ���� �����ϴ� �Լ�
{
	CONSOLE_CURSOR_INFO CurInfo;
   CurInfo.dwSize=1;    
   CurInfo.bVisible=FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); 
}

void textcolor(int color_number) //���� �� ���� �Լ�
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void systemcls() // system("cls")��� ���� Ʋ ���� ������ ���� ����� �Լ�
{
   int a,b; // ��������
   for(a=3;a<42;a++) // ����ȭ��
      for(b=3;b<23;b++)
      {
         gotoxy(a,b);
         printf(" ");
      }
}

void gotoxy(int x,int y) // ȭ����� ��ǥ�� �̿��ϱ� ���� �Լ�
{ 
   COORD pos={x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
