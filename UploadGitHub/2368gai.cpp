#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

long long C(int n, int m)
{
    m=m<(n-m)?m:(n-m);
    if(m==0)
        return 1;
    long long ans=1;
    for(int i=1; i<=m; i++)
        ans=ans*(n-i+1)/i;
    return ans;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        printf("%lld\n", C(n, m));
    }
    return 0;
}
