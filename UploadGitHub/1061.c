#include<stdio.h>

int main()
{
    int T, n, m, i;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d%d", &n, &m);
        if(n%(m+1)==0)
            printf("second\n");
        else
            printf("first\n");
    }
    return 0;
}
