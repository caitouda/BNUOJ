#include<stdio.h>

int main()
{
    int a[100][100], h[100], l[100], i, j, n, x, y;
    while(1)
    {
        int p=0, q=0; //pq不能放while前面
        scanf("%d", &n);
        if(n==0)
            break;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &a[i][j]);
                h[i]=h[i]+a[i][j];
            }
        }
        for(j=0; j<n; j++)
        {
            for(i=0; i<n; i++)
                l[j]=l[j]+a[i][j];
        }
        for(i=0; i<n; i++)
        {
            if(h[i]%2!=0)
            {
                p++;
                x=i+1;
            }
            if(l[i]%2!=0)
            {
                q++;
                y=i+1;
            }
        }
        if(p==0&&q==0)
            printf("OK\n");
        else
        {
            if(p==1&&q==1)
                printf("Change bit (%d,%d)\n", x, y);
            else
                printf("Corrupt\n");
        }
        for(i=0; i<n; i++)
        {
            h[i]=0;
            l[i]=0;
        }
    }
    return 0;
}
