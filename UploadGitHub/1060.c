#include<stdio.h>
#include<math.h>

int main()
{
    int t, n;
    int i, b, c, j;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        b=sqrt(n);
        for(j=b; j>=1; j--)
        {
            if(n%j==0)
            {
                c=n/j;
                break;
            }
        }
        printf("%d\n", 2*(j+c));
    }
    return 0;
}
