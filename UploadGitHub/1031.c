#include<stdio.h>

int main()
{
    int n, k, i, j;
    while(1)
    {
        scanf("%d%d", &n, &k);
        if(n==0&&k==0)
            break;
        int a[n], b[n];
        for(i=0; i<n; i++)
        {
            a[i]=0;
        }
        for(i=0; i<k; i++)
        {
            scanf("%d", &b[i]);
        }
        for(i=0; i<k; i++)
        {
            int flag=0;
            for(j=b[i]-1; j<n; j++)
            {

                if(a[j]==0)
                {
                    a[j]=b[i];
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0; j<b[i]-1; j++)
                {

                    if(a[j]==0)
                    {
                        a[j]=b[i];
                        break;
                    }
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%d\n", a[i]);
        }
        printf("\n");
    }
    return 0;
}
