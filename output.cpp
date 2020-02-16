#include<stdio.h>
#include<string.h>
#include<math.h>
void output(int num)  
{
    char figure[10][4] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
    printf("%s", figure[num]);
}
void outputPlus(int num)
{
    int tensPlace, onesPlace;
    tensPlace = num / 10;
    onesPlace = num % 10;
    if ( tensPlace != 1 )
      output(tensPlace);
    printf("十");
    if ( onesPlace )
          output(onesPlace);
}
int main()
{
	int total;
    scanf("%d",&total);
    if (total < 0)
      printf("负");
    total = fabs(total);
	if (total < 10)
	  output(total);
	else
	  outputPlus(total);
	return 0;
}
