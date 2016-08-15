#include<stdio.h>

int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        if(n%2==0)
            printf("%d\n", n*n/4);
        else
            printf("%d\n", (n/2)*(n/2+1));
    }
    return 0;
}
