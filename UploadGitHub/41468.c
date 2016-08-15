#include<stdio.h>

int main()
{
    double i, m, sum=0;
    for(i=0; i<12; i++)
    {
        scanf("%lf", &m);
        sum=sum+m;
    }
    printf("$%.2lf\n", sum/12);
    return 0;
}

