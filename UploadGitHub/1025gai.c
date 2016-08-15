#include<stdio.h>
#include<math.h>

int main()
{
    int prime(int m);
    int n, i, j=0, count, a[10000], flag=0; //j不能等於-1
    scanf("%d", &n);
    for(i=1; i<=n; i=i+2)
    {
        if(prime(i)==1)
        {
            a[j++]=i;
        }
    }
    count=j;
    for(j=0; j<=count; j++)
    {
        if((a[j+1]-a[j])==2&&(a[j+2]-a[j+1])==2)
        {
            printf("%d %d %d\n", a[j], a[j+1], a[j+2]);
            flag=1;
        }
    }
    if(flag==0)
        printf("No triple");
    return 0;
}

int prime(int m)
{
    int i, n;
    if(m==1)
        return 0;
    n=sqrt(m);
    for(i=2; i<=n; i++)
        if(m%i==0)
        {
            return 0;
        }
    return 1;
}

