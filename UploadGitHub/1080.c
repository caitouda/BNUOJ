#include<stdio.h>

int main()
{
    int NR, NC, a[110][110], Min=0, sum, i, j, tx, ty;
    scanf("%d%d", &NR, &NC);
    for(i=1; i<=NR; i++)
        for(j=1; j<=NC; j++)
            scanf("%d", &a[i][j]);
    for(i=1; i<=NR-2; i++)
        for(j=1; j<=NC-2; j++)
        {
            sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            if(Min<sum)
            {
                Min=sum;
                tx=i;
                ty=j;
            }
        }
    printf("%d\n", Min);
    printf("%d %d", tx, ty);
    return 0;
}
