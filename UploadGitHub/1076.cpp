#include<cstdio>
#define MX 1000010
#define LL long long

using namespace std;

inline LL read()
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

bool win[1000010];
int T, n, mx, mn;

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=9; i++)
        win[i]=1;
    for(int i=10; i<=MX; i++)
    {
        int s=i, t;
        mx=-1;
        mn=10;
        while(s)
        {
            t=s%10;
            if(t>mx&&t)
                mx=t;
            if(t<mn&&t)
                mn=t;
            s/=10;
        }
        if(mx!=-1)
            win[i]|=(!win[i-mx]);
        if(mn!=10)
            win[i]|=(!win[i-mn]);
    }
    while(T--)
    {
        int x=read();
        if(win[x])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

