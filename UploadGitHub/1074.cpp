#include<cstdio>
#include<cstring>

using namespace std;

struct edge
{
    int to, next, v;
} e[200001];

int head[50001];
int dis[50001];
int q[500001];
bool mark[50001];
int n, m, cnt, t, w=1, mx=0, rep, num;

inline int read()
{
    int x=0, f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void ins(int u, int v, int w)
{
    e[++cnt].v=w;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

inline void insert(int u, int v, int w)
{
    ins(u, v, w);
    ins(v, u, w);
}

inline void spfa()
{
    memset(dis, 127/3, sizeof(dis));
    q[1]=1;
    dis[1]=0;
    mark[1]=1;
    while(t<w)
    {
        int now=q[++t];
        for(int i=head[now]; i; i=e[i].next)
            if(dis[e[i].to]>dis[now]+e[i].v)
            {
                dis[e[i].to]=dis[now]+e[i].v;
                if(!mark[e[i].to])
                {
                    q[++w]=e[i].to;
                    mark[e[i].to]=1;
                }
            }
        mark[now]=0;
    }
}

int main()
{
    n=read();
    m=read();
    for(int i=1; i<=m; i++)
    {
        int x=read(), y=read();
        insert(x, y, 1);
    }
    spfa();
    for(int i=n; i>=2; i--)
    {
        if(dis[i]>mx)
        {
            mx=dis[i];
            num=i;
            rep=1;
        }
        else if(dis[i]==mx)
        {
            num=i;
            rep++;
        }
    }
    printf("%d %d %d\n", num, mx, rep);
    return 0;
}
