#include<bits/stdc++.h>

using namespace std;

const double Pi=acos(-1.0);

map<int, int> m;

void Input(int x, int y)
{
    if(m.count(x)==0)
        m[x]=y;
    else
        m[x]|=y;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int l, h, n, x, y;
        m.clear();
        scanf("%d%d%d", &l, &h, &n);
        while(n--)
        {
            scanf("%d%d", &x, &y);
            Input(x+y*l, 1);
            Input(x+y*l-l, 2);
            Input(x+y*l-l+1, 4);
            Input(x+y*l+1, 8);
        }
        double res=l*h;
        for(map<int,int>::iterator it=m.begin(); it!=m.end(); it++)
        {
            int s=it->second;
            if(s==1||s==2||s==4||s==8)
                res-=Pi/4.0;
            else if(s==3||s==6||s==9||s==12)
                res-=sqrt(3.0)/4.0+Pi/6.0;
            else
                res-=1.0;
        }
        printf("%.2lf\n", res);
    }
    return 0;
}
