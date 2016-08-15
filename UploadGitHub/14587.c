#include<stdio.h>

int main()
{
    int i, t;
    double R[16], G[16], B[16], r, g, b, Min, sum;
    for(i=0; i<16; i++)
    {
        scanf("%lf%lf%lf", &R[i], &G[i], &B[i]);
    }
    while(1)
    {
        scanf("%lf%lf%lf", &r, &g, &b);
        if(r==-1&&g==-1&&b==-1)
            break;
        Min=20000000;
        for(i=0; i<16; i++)
        {
            sum=(R[i]-r)*(R[i]-r)+(G[i]-g)*(G[i]-g)+(B[i]-b)*(B[i]-b);
            if(Min>sum)
            {
                Min=sum;
                t=i;
            }
        }
        printf("(%.0f,%.0f,%.0f) maps to (%.0f,%.0f,%.0f)\n", r, g, b, R[t], G[t], B[t]);
    }
    return 0;
}
