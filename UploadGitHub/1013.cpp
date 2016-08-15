#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node
{
    int a, b;
};

bool cmp(node a, node b)
{
    if(a.a==b.a)
        return a.b<b.b;
    else return
    a.a<b.a;
}

int main()
{
    int t, k, i, j, m;
    scanf("%d", &t);
    node ans[3100];
    for(k=1; k<=t; k++)
    {
        scanf("%d", &m);
        for(i=1; i<=m; i++)
        {
            scanf("%d", &ans[i].a);
            ans[i].b=i;
        }
        sort(ans+1, ans+m+1, cmp);
        printf("Case %d:", k);
        for(i=1; i<=m; i++)
            printf(" %d", ans[i].b);
        printf("\n");
    }
    return 0;
}
