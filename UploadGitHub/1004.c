#include<stdio.h>

int main()
{
    int a;
    while(1)
    {
        if(scanf("%d", &a)==EOF)
            break;
        printf("%d\n", -a);
    }
    return 0;
}
