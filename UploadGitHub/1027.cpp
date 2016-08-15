#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXN=10001;
long long f[MAXN];
int n;

int main()
{
    int t, v, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &v, &n);
        int vi;
        memset(f, 0, sizeof(f));
        while(v--)
        {
            scanf("%d", &vi);
            for(i=0; i<=n; i++)
            {
                if(i==0&&i+vi<=n)
                {
                    f[i+vi]=f[i+vi]+1;
                }
                else
                {
                    if(f[i]>0&&i+vi<=n)
                    {
                        f[i+vi]+=f[i];
                    }
                }
            }
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}

