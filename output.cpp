#include<stdio.h>
#include<string.h>
#include<math.h>
void output(int num)  
{
    char figure[10][4] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��"};
    printf("%s", figure[num]);
}
void outputPlus(int num)
{
    int tensPlace, onesPlace;
    tensPlace = num / 10;
    onesPlace = num % 10;
    if ( tensPlace != 1 )
      output(tensPlace);
    printf("ʮ");
    if ( onesPlace )
          output(onesPlace);
}
int main()
{
	int total;
    scanf("%d",&total);
    if (total < 0)
      printf("��");
    total = fabs(total);
	if (total < 10)
	  output(total);
	else
	  outputPlus(total);
	return 0;
}
