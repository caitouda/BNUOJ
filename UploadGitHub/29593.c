#include<stdio.h>

int main()
{
    int n, m, s, i;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            break;
        n--;
        for(m=1; m<=900; m++)
        {
            s=0;
            for(i=2; i<=n; i++)
                s=(s+m)%i;
            if(s==0)
            {
                printf("%d\n", m);
                break;
            }
        }
    }
    return 0;
}

