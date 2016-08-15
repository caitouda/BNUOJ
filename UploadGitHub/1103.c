#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, k, n, m, a, b, f, c, count=1;
    float r[40][40], r1;
    char huo[40][20], t1[20], t2[20];
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        for(i=1; i<=n; i++) //初始化
            for(j=1; j<=n; j++)
            {
                if(i==j)
                {
                    r[i][j]=1;
                }
                r[i][j]=0;
            }
        for(i=1; i<=n; i++) //將貨幣種類和其編號對應起來
            scanf("%s", huo[i]);
        scanf("%d", &m);
        for(i=1; i<=m; i++)
        {
            scanf("%s %f %s", t1, &r1, t2);
            f=0;
            for (j=1; j<=n; j++) //根據編號建立r
            {
                if(strcmp(huo[j], t1)==0)
                {
                    f++;
                    a=j;
                }
                if(strcmp(huo[j], t2)==0)
                {
                    f++;
                    b=j;
                }
                if(f==2)
                    break;
            }
            r[a][b]=r1;
        }
        getchar();
        for(k=1; k<=n; k++) //弗洛伊德
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    if(r[i][j]<r[i][k]*r[k][j])
                        r[i][j]=r[i][k]*r[k][j];
        c=0;
        for(i=1; i<=n; i++) //判斷是否有匯率大於的點
            if(r[i][i]>1)
            {
                c=1;
                break;
            }
        if(c)
            printf("Case %d: Yes\n", count++);
        else
            printf("Case %d: No\n", count++);
    }
    return 0;
}

