#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100001

int du[2][N]; //滾動數組

int main()
{
    int i, j, k, n, m, kk, top, tt;
    double sum, result;
    while(scanf("%d%d%d", &n, &m, &kk), n||m||kk)
    {
        sum=pow(m, n); //總情況數
        for(i=1; i<=m; i++)
            du[0][i]=1;
        top=m;
        tt=0;
        for(i=2; i<=n; i++)
        {
            memset(du[!tt], 0, sizeof(du[tt]));
            for(j=top; j>=1; j--)
                for(k=1; k<=m; k++)
                    du[!tt][j+k]+=du[tt][j];
            tt=!tt;
            top+=m;
        }
        result=0;
        //printf("%d\n", tt);
        for(i=n; i<=kk; i++) //du[tt][i]求出的是和為i的情況數
            result+=du[tt][i]*1.0/sum;
        for(i=kk+1; i<=top; i++)
            result+=du[tt][i]*(i-kk)*1.0/sum;
        printf("%.8f\n", result);
    }
    return 0;
}
