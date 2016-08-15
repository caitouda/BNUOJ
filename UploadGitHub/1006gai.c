#include<stdio.h>

int main()
{
    int a, b, x, y, i, f, count;
    while(1)
    {
        scanf("%d%d", &a, &b);
        if(a==0&&b==0)
            break;
        f=0;
        count=0;
        for(i=0; i<10; i++)
        {
            x=a%10;
            y=b%10;
            if(x+y+f>=10)
                count++;
            a=a/10;
            b=b/10;
            f=(x+y+f)/10;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("%d carry operation.\n", count);
        else
            printf("%d carry operations.\n", count);
    }
    return 0;
}
