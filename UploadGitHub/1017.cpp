#include<bits/stdc++.h>

using namespace std;

int v[10], n, m, ans;

void dfs(int p, int x)
{
    //printf("%d %d\n", p, x);
    if(p==n)
    {
        ans++;
        printf("%d\n", x);
    }
    for(int i=1; i<=p+m+1&&i<=n; i++) //從這裡循環i遞增
    {
        //printf("i=%dok\n", i);
        if(v[i])
            continue;
        v[i]=1;
        //printf("ii=%dok\n", i);
        dfs(p+1, x*10+i); //從這裡進入循環從1開始
        //printf("iii=%dok\n", i);
        v[i]=0;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    dfs(0, 0);
    printf("%d\n", ans);
}
