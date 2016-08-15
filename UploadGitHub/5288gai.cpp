#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        double a,b;
        scanf("%lf%lf", &a, &b);
        double ans=(a*a+b*b)/100*3.1415926;
        int m=ans;
        m++;
        printf("Property %d: This property will begin eroding in year %d.\n", i, m);
    }
    puts("END OF OUTPUT.");
    return 0;
}
