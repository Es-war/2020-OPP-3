#include<stdio.h>
#include<string.h>
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
            if(!strcmp(copy,num[j]))
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
int main()
{
	char money[12]; 
	int total = 0;
	total = deal();
	printf("%d", total);
	return 0;
} 
