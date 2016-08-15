#include<stdio.h>
#include<math.h>

int main()
{
    int t, i;
    double r, n, s;
    double pi=acos(-1.0);
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%lf%lf", &r, &n);
        s=0.5*n*r*r*sin(2*pi/n);
        printf("%.3lf\n", s);
    }
    return 0;
}
