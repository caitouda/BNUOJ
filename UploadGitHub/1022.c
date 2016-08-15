#include<stdio.h>

int fun(char *str, int x)
{
    int i, num, ans, f, tn, k, j;
    ans=0;
    i=0;
    f=1;
    while(str[i])
    {
        if(str[i]=='-')
        {
            f=-1; //相當於減
            i++;
        }
        else if(str[i]=='+')
        {
            f=1; //相當於加
            i++;
        }
        num=0;
        tn=0;
        while(str[i]>='0'&&str[i]<='9') //整合中間的整數
        {
            num=10*num+str[i]-'0';
            i++;
            tn=1; //有整合的整數
        }
        if(str[i]!='x') //不是x則整合之前的加減，此時肯定為+或-，則回到大循環重新判斷
        {
            ans+=f*num;
        }
        else //是x
        {
            i++;
            if(tn==0) //沒有整數則為1
                num=1;
            k=1; //3x+5則不進入if，所以需要k為1
            if(str[i]=='^') //是x並且接下來是乘方，如3x^5
            {
                i++;
                k=0;
                while(str[i]>='0'&&str[i]<='9')
                {
                    k=10*k+str[i]-'0';
                    i++;
                }
            }
            for(j=0; j<k; j++)
                num*=x;
            ans+=f*num; //現在整合之前的加減
        }
    }
    return ans;
}

int tstr[10000], lt;
int ts[10000], ls;

int main()
{
    int prob, i, j, k, n, t, ls;
    char str[100];
    scanf("%d", &prob);
    while(prob--)
    {
        scanf("%d", &n);
        lt=0;
        while(n--)
        {
            getchar();
            scanf("%s%d",str, &t);
            t=fun(str, t);
            ls=0;
            while(t!=0) //轉為二進制
            {
                ts[ls]=t%2;
                t/=2;
                ls++;
            }
            for(i=ls-1; i>=0; i--) //倒過來
            {
                tstr[lt]=ts[i];
                lt++;
            }
        }
        t=0;
        for(i=0; i<lt; i++)
        {
            t=t*2+tstr[i];
            if(i%5==4) //滿5個則變為字母
            {
                if(t>=1&&t<=26)
                    printf("%c", 'A'-1+t);
                else
                    printf(" ");
                t=0;
            }
        }
        printf("\n%d\n", lt%5);
    }
    return 0;
}

