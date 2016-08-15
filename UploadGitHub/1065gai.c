#include<stdio.h>

int main()
{
    int t, i, j;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, num[17]={0};
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &k);
            for(j=0; j<17; j++)
                num[j]+=1-(k&1), k>>=1;
        }
        int ans=0;
        for(i=16; i>=0; i--)
            ans=2*ans+n*n-num[i]*num[i];
        printf("%d\n", ans);
    }
    return 0;
}
