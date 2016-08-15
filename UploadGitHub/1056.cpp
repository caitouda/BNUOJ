#include<stdio.h>
using namespace std;

int n, e[310][310], mark[310];
int main()
{
    int i, j, T, temp, ti, tj, sum=0;
    temp=200000;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &e[i][n+1]);
        e[n+1][i]=e[i][n+1]; //建立虛擬n+1表示在該城市建設發電廠
        if(e[i][j]!=0&&temp>e[i][j])
        {
            temp=e[i][j];
            ti=i;
            tj=j;
        }
    }
    e[n+1][n+1]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d", &e[i][j]);
            if(e[i][j]!=0&&temp>e[i][j])
            {
                temp=e[i][j];
                ti=i;
                tj=j;
            }
        }
    sum+=e[ti][tj];
    e[ti][tj]=0;
    mark[ti]=1;
    mark[tj]=1;
    T=n-1;
    while(T--)
    {
        temp=200000;
        for(i=1; i<=n+1; i++) //mark來標記是否已被選中
        {
            if(mark[i]==1)
                for(j=1; j<=n+1; j++)
                {
                    if(mark[j]==0)
                    {
                        if(e[i][j]!=0&&temp>e[i][j])
                        {
                            temp=e[i][j];
                            ti=i;
                            tj=j;
                        }
                    }
                }
        }
        sum+=e[ti][tj];
        e[ti][tj]=0;
        mark[ti]=1;
        mark[tj]=1;
    }
    printf("%d\n", sum);
    return 0;
}

