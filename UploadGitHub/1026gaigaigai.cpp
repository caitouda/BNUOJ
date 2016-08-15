#include<stdio.h>

int a[2][1000001];
int n;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", a[0]+i), ++a[1][a[0][i]];
    for(int i=1000000; i>=1; --i)
        if(a[1][i])
            for(int j=i+i; j<=1000000; j+=i)
                a[1][j]+=a[1][i];
    for(int i=1; i<=n; ++i)
        printf("%d\n", a[1][a[0][i]]-1);
    return 0;
}
