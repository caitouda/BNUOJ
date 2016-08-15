#include<stdio.h>

int main()
{
    int n, k;
    while(1)
    {
        scanf("%d%d", &n, &k);
        if(n==0&&k==0)
            break;
        else
            printf("%d\n", k);
    }
    return 0;
}
