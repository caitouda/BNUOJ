#include<stdio.h>
#define MAX 101

int main()
{
    int n;
    int a[MAX][MAX]={0};
    int colsum[MAX][MAX]={0};
    int max=0, sum;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &a[i][j-1]);
            colsum[i][j]=colsum[i][j-1]+a[i][j-1];
        }
    for(int i=0; i<n; i++)
        for(int j=i; j<=n; j++) //從第i行到第j行
        {
            sum=0;
            for(int k=0; k<n; k++) //每列的和，寬度固定的情況下從上往下計算
            {
                sum+=colsum[k][j]-colsum[k][i];
                if(sum<0)
                    sum=0; //從下一個重新開始
                else if(sum>max)
                    max=sum;
            }
        }
    printf("%d\n", max);
    return 0;
}
