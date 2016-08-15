#include<stdio.h>

int main()
{
    double n, k;
    while(scanf("%lf%lf", &n, &k)==2)
    {
        if(n==0&&k==0)
            break;
        double ans=1;
        if(2*k>n)
            k=n-k; //注意優化
        while(k>=1) //分子是n*n-1*...*n-k+1 共k項,分母是k*k-1*...*1共k項，所以復雜度取決於k的大小
        {
            ans*=n/k;
            n--, k--;
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}
