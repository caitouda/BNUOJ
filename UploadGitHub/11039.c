#include<stdio.h>

int main()
{
    int n, w, t, i, k, MMax;
    double a[110], Max, sum;
    while(1)
    {
        scanf("%d%d", &n, &w);
        if(n==0&&w==0)
            break;
        Max=-1;
        for(i=0; i<n; i++)
        {
            scanf("%lf", &a[i]);
            if(Max<a[i])
                Max=a[i];
        }
        t=Max/w;
        //printf("%d",t);
        int count[110]={0};
        k=0;
        for(i=0; i<n; i++)
        {
            while(1)
            {
                if(a[i]>=k*w&&a[i]<(k+1)*w)
                {
                    count[k]++;
                    k=0;
                    break;
                }
                else
                    k++;
            }
        }
        MMax=-1;
        for(i=0; i<=t; i++)
        {
            if(MMax<count[i])
                MMax=count[i];
        }
        sum=0;
        for(i=0; i<=t; i++)
        {
            sum=sum+(double)(count[i]*(t-i))/(MMax*t);
        }
        printf("%f\n", sum+0.01);
    }
    return 0;
}
