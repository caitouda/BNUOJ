#include <stdio.h>

int str[20];
int main()
{
    int a, k, b, flag, c, d, e, f, i;
    int frist=1;

    while(scanf("%d", &k)!= EOF && k!=0)
    {
        if(frist==0)printf("\n");
        frist=0;
        for(i=1; i<=k; i++)scanf("%d", &str[i]);
        flag=k-5;
        for(a=1; a<=flag; a++)
        {
            for(b=a+1; b<=flag+1; b++)
            {
                for(c=b+1; c<=flag+2; c++)
                {
                    for(d=c+1; d<=flag+3; d++)
                    {
                        for(e=d+1; e<=flag+4; e++)
                        {
                            for(f=e+1; f<=flag+5; f++)
                            {
                                printf("%d %d %d %d %d %d\n", str[a], str[b], str[c], str[d], str[e], str[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

