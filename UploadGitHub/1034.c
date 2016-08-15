#include <stdio.h>

int main()
{
    int n, i, sum;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        if(n==1)
            printf("%d\n", 0);
        if(n==2)
            printf("%d\n", 1);
        if(n>=3)
        {
            sum=3;
            for(i=4; i<=n; i++)
            {
                if((i-1)%2!=0)
                {
                    sum+=1;
                }
                sum+=(i-1)/2;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
