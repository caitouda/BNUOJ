#include<stdio.h>

int main()
{
    int t, i, j, o, sum, k, mark;
    int all, count, max, c[1001], d[1001];
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d", &sum, &k);
        all=0;
        count=0;
        for(j=1; j<=k; j++)
        {
            scanf("%d", &c[j]);
            d[j]=c[j];
        }
        for(j=1; j<=k; j++)
        {
            max=d[j];
            mark=j;
            for(o=j; o<=k; o++)
            {
                if(max<d[o])
                {
                    max=d[o];
                    mark=o;
                }
            }
            d[mark]=d[j];
            d[j]=max;
            all=all+max;
            count++;
            if(all>=sum)
                break;
        }
        for(j=1; j<=k; j++)
        {
            for(o=1; o<=count; o++)
                if(c[j]==d[o])
                    printf("%d\n", j);
        }
        printf("\n");
    }
    return 0;
}
