#include<stdio.h>

int main()
{
    int i;
    double length, sum;
    while(1)
    {
        scanf("%lf", &length);
        if(length==0.00)
            break;
        sum=0;
        i=1;
        while(1)
        {
            if(sum>=length)
                break;
            i++;
            sum=sum+(double)1/i;
        }
        printf("%d card(s)\n", i-1);
    }
    return 0;
}
