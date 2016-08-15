#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int T=3e4+5;
int dp[T];

int begin1(int n, int m, int kk)
{
    for(int i=1; i<=m; i++)
        dp[i]=1;
    for(int i=m+1; i<=n*m; i++)
        dp[i]=0;
    for(int i=2; i<=n; i++)
        for(int j=i*m; j>=i; j--)
        {
            dp[j]=0;
            for(int k=j-1; k>=1; k--)
            {
                if(j-k>m)
                    continue;
                if(k>(i-1)*m||k<i-1)
                    continue;
                dp[j]+=dp[k];
            }
        }
    int sum=0;
    for(int i=n; i<=n*m; i++)
        sum+=dp[i]*(i-kk>1?i-kk:1);
    return sum;
    for(int i=1; i<=m*n; i++)
        printf("%d ", dp[i]);
    printf("\n");
}

int main()
{
    int n, m, k;
    while(scanf("%d%d%d", &n, &m, &k), (m+n+k))
    {
        printf("%.8lf\n", begin1(n, m, k)/pow(m, n));
    }
    return 0;
}
