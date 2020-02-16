#include<stdio.h>
#include<string.h> 
int charToNum(char oMoney[])
{
    char figure[11][4]={"零","一","二","三","四","五","六","七","八","九","十"};
    char copy[0];
    int i, j, sum = 0, flag = 1, x = 0;
    int len = strlen(oMoney);
    for(i = 0; i < len; i += 2)
    {
        strncpy(copy,oMoney+i,2); 
        if(!strcmp(copy,"负"))
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
int main()
{
	char money[16];
	scanf("%s",money);
	int total = charToNum(money);
	printf("%d",total);
	return 0;
}
