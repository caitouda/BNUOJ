#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int n, i, year;
    double x, y, r, s;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%lf%lf", &x, &y);
        r=x*x+y*y;
        s=0.5*PI*r;
        year=(int)(s/50)+1;
        printf("Property %d: This property will begin eroding in year %d.\n", i, year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
