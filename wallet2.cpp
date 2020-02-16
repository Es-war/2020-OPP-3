#include<stdio.h>
#include<string.h>
#include<math.h>
int charToNum(char oMoney[])
{
    char figure[11][4]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
    char copy[0];
    int i, j, sum = 0, flag = 1, x = 0;
    int len = strlen(oMoney);
    for(i = 0; i < len; i += 2)
    {
        strncpy(copy,oMoney+i,2); 
        if(!strcmp(copy,"��"))
          {
          	flag = -1;
          	x = 2;
		  }
        for(j = 0; j < 11; j++)
        {
            if(!strcmp(copy,figure[j]))
            {
                if(i==x&&j==10) sum += j;
                else if(i!=x&&j==10) sum = sum*10;
                else if(j!=10) sum += j; 
            }
        }
    }
    return (flag*sum);
}
int deal() 
{
	char wallet[10], sign[10], coin[16];
	int  sum = 0;
    for (;;)
      {
          scanf("%s", wallet);
          if ( !strcmp("Ǯ��", wallet) )   
            {
                scanf("%s%s", sign, coin);  
                if ( !strcmp("����", sign) )   
                  sum += charToNum(coin); 
                else if ( !strcmp("����", sign) )
                  sum -= charToNum(coin);
          }
        else if ( !strcmp("����", wallet) )
          {
              scanf("%s", wallet);  break; 
          } 
      }
    return sum;
}
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
	char document[20];
	char movement[16], wallet[16], sign[16], money[16];
	int total = 0;
	scanf("%s",document);
	freopen(document,"r",stdin);
	scanf("%s%s%s%s", movement, wallet, sign, money); 
	total = charToNum(money);  
	total += deal();   
	if (total < 0)
      printf("��");
    total = fabs(total);
	if (total < 10)
	  output(total);
	else
	  outputPlus(total);
	return 0;
}
