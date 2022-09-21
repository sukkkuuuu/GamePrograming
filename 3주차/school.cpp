#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

int calc_frequency(int octave, int inx);
void practice_piano(void);
void school_sound(void);
int main(void){
	printf("1���� 8���� ���� Ű�� ������\n");
	printf("�� ���� �Ҹ��� ��µ˴ϴ�.\n\n");
	printf("1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:�� 8:��\n");
	printf("���α׷� ����� EscŰ \n");
	school_sound();
	return 0;
}

void practice_piano(void) // ����Ű�� ���� ������ ���ļ��� ����Ŀ�� ��� �� �� 
{
   int index[] = {0,2,4,5,7,9,11,12};
   int freq[8], code, i;
   for(int i=0;i<8;i++)
      freq[i] = calc_frequency(4,index[i]);
   do
   {
      code = getch();
      if('1'<=code && code<='8')
      {
         code -= 49;
         Beep(freq[code],300);
      }
   }while(code!=27);
}
void school_sound(void){
	int code[] = {5,5,6,6,5,5,3,5,5,3,3,2,5,5,6,6,5,5,3,5,3,2,3,1};
	int freq[24];
	for(int i=0; i<24; i++){
		freq[i] = calc_frequency(4, code[i]);
	}
	for(int i=0; i<24;i++){
		Beep(freq[i], 500);
	}
}
int calc_frequency(int octave, int inx){
	double do_scale = 32.7032;
	double ratio = pow(2., 1/12.), temp;
	int i;
	temp = do_scale*pow(2,octave-1);
	for(int i=0; i<inx; i++){
		temp = (int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
