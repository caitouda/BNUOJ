#include<stdio.h>

int main()
{
    int T, i, a, b;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", a-2*b+2); //先一直套用b公式，然後套用c
    }
    return 0;
}
