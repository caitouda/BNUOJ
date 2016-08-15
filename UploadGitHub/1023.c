#include<stdio.h>

int main()
{
    int K, M, N, I, J, P, X, Y, i, j, a[220][220], flag;
    scanf("%d", &K);
    while(K--)
    {
        scanf("%d%d", &M, &N);
        for(i=1; i<=M; i++)
            for(j=1; j<=N; j++)
            {
                scanf("%d", &a[i][j]);
            }
        scanf("%d%d", &I, &J);
        scanf("%d", &P);
        flag=0;
        while(P--)
        {
            scanf("%d%d", &X, &Y);
            if(a[X][Y]>=a[I][J])
                flag=1;
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
