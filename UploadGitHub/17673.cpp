#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 10000+5
#define eps 1e-8
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

using namespace std;

double dis[205];
int x[1005], y[1005];
int tag[205];

int main()
{
    int n, i, j, k, q=0;
    while(scanf("%d", &n)&&n)
    {
        for(i=0; i<n; i++)
            scanf("%d%d", &x[i], &y[i]);
        for(i=0; i<n; i++)
        {
            tag[i]=0;
            dis[i]=1e8;
        }
        tag[0]=1;
        dis[0]=0;
        for(k=1; k<n; k++)
        {
            double mm=1e8+1;
            int con;
            for(i=0; i<n; i++)
            {
                if(tag[i]==1)
                {
                    for(j=0; j<n; j++)
                    {
                        if(tag[j]==0)
                        {
                            double tmpdis;
                            tmpdis=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
                            double tmp=max(tmpdis, dis[i]);
                            dis[j]=min(dis[j], tmp);
                            if(dis[j]<mm+eps)
                            {
                                mm=dis[j];
                                con=j;
                            }
                        }
                    }
                }
            }
            tag[con]=1;
            dis[con]=mm;
        }
        if(q==0)
            printf("Scenario #%d\nFrog Distance = %.3f\n", ++q, dis[1]);
        else
            printf("\nScenario #%d\nFrog Distance = %.3f\n", ++q, dis[1]);
    }
    return 0;
}

