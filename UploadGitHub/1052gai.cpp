#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct heroname
{
    char name[23];
    int t;
} p[1010];

char hero[23];

void gengxin(int k, char name[], int t)
{
    int mod=k*100+150;
    if(abs(t-mod)<abs(p[k].t-mod)||(abs(t-mod)==abs(p[k].t-mod)&&t>p[k].t))
    {
        strcpy(p[k].name, name);
        p[k].t=t;
    }
}

int main()
{
    int t, n;
    for(scanf("%d", &n); n--;)
    {
        scanf("%s%d", hero, &t);
        if(100<t&&t<200)
        {
            gengxin(0, hero, t);
        }
        else if(200<t&&t<300)
        {
            gengxin(1, hero, t);
        }
        else if(300<t&&t<400)
        {
            gengxin(2, hero, t);
        }
        else if(400<t&&t<500)
        {
            gengxin(3, hero, t);
        }
        else if(500<t&&t<600)
        {
            gengxin(4, hero, t);
        }
    }
    for (int i=0; i<5; ++i)
    {
        printf("%s %d\n", p[i].name, p[i].t);
    }
    return 0;
}

