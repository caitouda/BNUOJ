#include<stdio.h>
#include<string.h>

int main()
{
    char a[10], b[10];
    int m[10], n[10], i, count, f, index;
    while(1)
    {
        scanf("%s%s", &a, &b);
        if(strcmpi(a, 0)==0&&strcmpib(b, 0)==0)
            break;
        for(i=0; i<10; i++)
            m[i]=a[9-i]-'0';
        for(i=0; i<10; i++)
            n[i]=b[9-i]-'0';
        f=0;
        count=0;
        for(i=0; i<10; i++)
        {
            index=m[i]+n[i]+f;
            f=index/10;
            if(f!=0)
                count++;
        }
        if(count==0)
            printf("No carry operation.\n");
        else
            printf("%d carry operation.\n", count);
    }
    return 0;
}
