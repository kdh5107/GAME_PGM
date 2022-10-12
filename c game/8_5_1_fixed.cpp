#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void intro_game(int* freq);
void horizontal_slide(int x, int y, char *c2);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count);
void game_control(int* r_c, int rnd, int count);
void gotoxy(int x, int y);
int calc_frequency(int octave, int inx);


int main(void)
{
   int count=0, rnd, i, freq[8];;
   int index[]={0, 2, 4, 5, 7, 9, 11, 12};
   for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]); // �ǾƳ���  
   int r_count=0;
   char *target="��";
   srand(time(NULL));
   intro_game(freq);
   	
   do
   {
      system("cls");
      draw_rectangle(20, 20);
      rnd=rand()%35+4;
      gotoxy(rnd, 2);
      printf("%s", target);
      count++;
	  display_text(count, r_count);
      game_control(&r_count, rnd, count);

   }while(count<10);
	if(r_count>=7){ // 7�� �̻� ���߸� �Ҹ��� �Բ� �޼���, �����߸� �׳� �޼��� 
		gotoxy(46, 9);
		printf("�����մϴ�! ����� ����.");
		int clear[8] = {3, 3, 5, 4, 6, 5, 7, 8};
		for(int i=0;i<8;i++)
		{
			Beep(freq[clear[i]], 300);
		}
	}
	else{
		gotoxy(46, 9);
		printf("���� �õ������.");
	}
   return 0;
}

void intro_game(int* freq)
{
	printf("��Ÿ�� ȭ����\n\n");
	printf("���� Ÿ�� �̵��ϸ鼭 \n");
	printf("��ǥ��(��)�� ���ߴ� �����Դϴ�. \n");
	printf("ȭ���� �����̽�Ű�� �߻��մϴ�. \n\n");
	printf("7���̻� ���߸� ����� ����\n");
	printf("�ƹ�Ű�� ������ �����մϴ�. ");
	int opening[5] = {1, 2, 3, 4, 5};
	for(int i=0;i<5;i++)
	{
		Beep(freq[opening[i]], 100);
	}
	getch();

}
void horizontal_slide(int x, int y, char *c2)
{
		gotoxy(x, y);
		printf("%s", c2);
		Sleep(50);
		printf("\b\b  "); // ���� �� �����̵��� ����  (�����̽��� ��ĭ �� �߰��ؼ� ���� �ٽ� ���������� ����) 
}
void draw_rectangle(int r, int c)
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   		b[i]=0xa0+i;

    printf("%c%c", a, b[3]);
    for(i=0;i<c;i++)
  		printf("%c%c ", a, b[1]); // �׸� ĭ ���� ("%c%c �ڿ� �����̽��� ��ĭ �߰�) 
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
		printf("%c%c", a, b[2]);
		for(j=0;j<c;j++)
			printf("  ");
		printf("%c%c",a, b[2]);
		printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
		printf("%c%c ", a, b[1]); // �׸� ĭ ����  
    printf("%c%c", a, b[5]);
    printf("\n");
}
void display_text(int count, int r_count)
{
	gotoxy(46, 2);
	printf("�����̽�Ű�� ������\n");
	gotoxy(46, 3);
	printf("ȭ���� �߻�˴ϴ�.\n");
	gotoxy(46, 5);
	printf("Ƚ�� : %d", count);
	gotoxy(46, 6);
	printf("���� : %d", r_count);
			
}

void game_control(int* r_c, int rnd, int count)
{
	int i=1, k=1, y;
	char *horse="��", chr;
	do
	{
		i+=k;
		if (i>38) // ���� ĭ�� ����� �� ����  
			k=-1;
		else if (i<3)
			k=+1;
		horizontal_slide(i+1, 21, horse);
	}while(!kbhit());
	chr=getch();
	y=21;
	if (chr==32)
	{
		while(y>2)
		{
			y-=1;
			gotoxy(i+1, y);
			printf("��");
			Sleep(50);
			printf("\b\b  "); // ȭ�� ���ư��� �� ����  (�����̽��� �߰�) 
		}
		if ((rnd-2<=i) && (i<=(rnd))) // ǥ���� ���ߵǴ� ���� ���� ���� 
		{
			gotoxy(rnd, 2);
			printf("��");
			int sound=calc_frequency(4, 5); // ���� �� �Ҹ� �߻�  
			Beep(sound, 300);
			gotoxy(46, 8);
			printf("�¾ҽ��ϴ�. ");
			Sleep(50);
			*r_c=*r_c+1;
		}
		else{
			gotoxy(i, 2); 
			printf(" ?"); // �������� �� ? ǥ��  
			int sound=calc_frequency(4, 0); // �������� �� �Ҹ� �߻�  
			Beep(sound, 300);
			gotoxy(46, 8);
			printf("�Ʊ��׿�.");
		}
		gotoxy(1, 24); // 10��°�� �˾Ƽ� ����ǵ��� ����  
		if(count<10){
			printf("�ƹ�Ű�� ������ ���� ����...");
			getch();
		}
	}

}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int calc_frequency(int octave, int inx) // �ǾƳ���  
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}

