#include<stdio.h>

int main()
{
    int a;
    while(a!=0)
    {
        scanf("%d", &a);
        if(a==0)
            break;
        printf("%d\n", -a);
    }
    return 0;
}
