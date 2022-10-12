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
		freq[i]=calc_frequency(4, index[i]); // 피아노음  
   int r_count=0;
   char *target="□";
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
	if(r_count>=7){ // 7발 이상 맞추면 소리와 함께 메세지, 못맞추면 그냥 메세지 
		gotoxy(46, 9);
		printf("축하합니다! 당신은 명사수.");
		int clear[8] = {3, 3, 5, 4, 6, 5, 7, 8};
		for(int i=0;i<8;i++)
		{
			Beep(freq[clear[i]], 300);
		}
	}
	else{
		gotoxy(46, 9);
		printf("좋은 시도였어요.");
	}
   return 0;
}

void intro_game(int* freq)
{
	printf("말타며 화살쏘기\n\n");
	printf("말을 타고 이동하면서 \n");
	printf("목표물(□)을 맞추는 게임입니다. \n");
	printf("화살은 스페이스키로 발사합니다. \n\n");
	printf("7번이상 맞추면 당신은 명사수\n");
	printf("아무키나 누르면 시작합니다. ");
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
		printf("\b\b  "); // 말이 잘 움직이도록 수정  (스페이스바 한칸 더 추가해서 말이 다시 지워지도록 수정) 
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
  		printf("%c%c ", a, b[1]); // 네모 칸 수정 ("%c%c 뒤에 스페이스바 한칸 추가) 
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
		printf("%c%c ", a, b[1]); // 네모 칸 수정  
    printf("%c%c", a, b[5]);
    printf("\n");
}
void display_text(int count, int r_count)
{
	gotoxy(46, 2);
	printf("스페이스키를 누르면\n");
	gotoxy(46, 3);
	printf("화살이 발사됩니다.\n");
	gotoxy(46, 5);
	printf("횟수 : %d", count);
	gotoxy(46, 6);
	printf("성공 : %d", r_count);
			
}

void game_control(int* r_c, int rnd, int count)
{
	int i=1, k=1, y;
	char *horse="▲", chr;
	do
	{
		i+=k;
		if (i>38) // 말이 칸을 벗어나는 것 수정  
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
			printf("↑");
			Sleep(50);
			printf("\b\b  "); // 화살 날아가는 것 수정  (스페이스바 추가) 
		}
		if ((rnd-2<=i) && (i<=(rnd))) // 표적에 적중되는 판정 범위 변경 
		{
			gotoxy(rnd, 2);
			printf("☆");
			int sound=calc_frequency(4, 5); // 맞출 때 소리 발생  
			Beep(sound, 300);
			gotoxy(46, 8);
			printf("맞았습니다. ");
			Sleep(50);
			*r_c=*r_c+1;
		}
		else{
			gotoxy(i, 2); 
			printf(" ?"); // 못맞췄을 때 ? 표시  
			int sound=calc_frequency(4, 0); // 못맞췄을 때 소리 발생  
			Beep(sound, 300);
			gotoxy(46, 8);
			printf("아깝네요.");
		}
		gotoxy(1, 24); // 10번째에 알아서 종료되도록 수정  
		if(count<10){
			printf("아무키나 누르면 다음 진행...");
			getch();
		}
	}

}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int calc_frequency(int octave, int inx) // 피아노음  
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

