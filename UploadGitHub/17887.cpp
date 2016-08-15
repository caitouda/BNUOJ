#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define END -1

using namespace std;

const int maxn=1001;
int BigNumber[maxn]={0};

void multiple(int a[], int n) //大整數相乘
{
    int i, j;
    int c=0; //進位
    for(i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*n+c;
        c=a[i]/10;
        a[i]%=10;
    }
    while(c)
    {
        a[i++]=c%10;
        c/=10;
    }
    a[0]=i-1; //a[0]儲存大整數位數
    return;
}

void output(int pos)
{
    int i, j;
    if(BigNumber[0]>pos) //有整數
    {
        for(j=0, i=BigNumber[0]; j<BigNumber[0]-pos; j++, i--) //有整數輸出小數點前的數字
            printf("%d", BigNumber[i]);
        for(j=1; BigNumber[j]==0; j++) //去零
            BigNumber[j]=END;
        if(BigNumber[i]==END||i==0) //整數的話
            return;
        printf(".");
        for(; BigNumber[i]!=END&&i>=1 ; i--) //輸出小數點後的數字
            printf("%d", BigNumber[i]);
    }
    else //無整數
    {
        printf(".");
        for(i=0; i<pos-BigNumber[0]; i++)
            printf("0");
        for(j=1; BigNumber[j]==0; j++) //去零
            BigNumber[j]=END;
        for(i=BigNumber[0]; BigNumber[i]!=END&&i>=1; i--)
            printf("%d", BigNumber[i]);
    }
    return ;
}

int main()
{
    char s[10];
    int n;
    int pos, num;
    while(~scanf("%s%d", s, &n))
    {
        int i, j;
        int l=strlen(s);
        num=0;
        memset(BigNumber, 0 ,sizeof(BigNumber));
        for(i=0, pos=5; i<l ; i++) //POS=5 ，萬一沒有小數點，則POS=5
        {
            if(s[i]=='.')
                pos=i;
            else
                num=num*10+s[i]-'0'; //將小數轉換為整數
        }
        BigNumber[0]=BigNumber[1]=1;
        pos=(5-pos)*n; //一共有幾位小數
        while(n--)
        {
            multiple(BigNumber, num); //大數相乘
        }
        output(pos); //輸出
        printf("\n");
    }
    return 0;
}

