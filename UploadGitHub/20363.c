#include<stdio.h>

int main()
{
    int T, j, zheng, zheng1, zheng2;
    double i, m, sum, pj;
    scanf("%d", &T);
    for(j=1; j<=T; j++)
    {
        sum=0;
        for(i=0; i<12; i++)
        {
            scanf("%lf", &m);
            sum=sum+m;
        }
        pj=sum/12;
        zheng=pj;
        if(zheng>=1000000)
        {
            printf("%d $", j);
            zheng1=zheng/1000000;
            printf("%d,", zheng1);
            zheng=zheng%1000000;
            zheng2=zheng/1000;
            printf("%d,", zheng2);
            printf("%.2f\n", pj-zheng2*1000-zheng1*1000000);

        }
        else if(zheng>=1000)
        {
            printf("%d $", j);
            zheng2=zheng/1000;
            printf("%d,", zheng2);
            printf("%.2f\n", pj-zheng2*1000);
        }
        else
        {
            printf("%d $", j);
            printf("%.2f\n", pj);
        }
    }
    return 0;
}



