#include<stdio.h>
#include<string.h>

int a[26][2];
int zhan[1000][2];
int top;
int sum;
char str[1000];

int jin(int x)
{
    zhan[top][0]=a[x][0]; //a c
    zhan[top][1]=a[x][1]; //b d判斷b和c是否相等
    top++;
    return 0;
}

int chu()
{
    if(zhan[top-2][1]!=zhan[top-1][0]) //top-2更前面
        return 1;
    sum+=zhan[top-1][0]*zhan[top-1][1]*zhan[top-2][0]; //d*c*a
    zhan[top-2][1]=zhan[top-1][1]; //b=d其實都倒過來了，從最後開始往前面算
    top--;
    return 0;
}

int main()
{
    int n, i, j, x, y;
    char ch;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        getchar();
        scanf("%c %d %d", &ch, &x, &y);
        a[ch-'A'][0]=x;
        a[ch-'A'][1]=y;
    }
    while(scanf("%s", &str)!=EOF)
    {
        top=sum=0;
        int len=strlen(str);
        if(len==1)
        {
            printf("0\n");
            continue;
        }
        int flag=0;
        for(i=0; i<len&&!flag; i++)
        {
            if(str[i]=='(')
                continue;
            if(str[i]==')')
                flag=chu();
            else
                jin(str[i]-'A');
            if(flag)
                break;
        }
        if(flag)
            printf("error\n");
        else
            printf("%d\n", sum);
    }
    return 0;
}

