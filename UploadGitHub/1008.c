#include<stdio.h>
#include<math.h>

const double PI=3.141592653589793;

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double a, b, c, ya, sa, r, s;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF)
    {
        a=sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
        b=sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));
        c=sqrt(pow(x3-x2, 2)+pow(y3-y2, 2));
        ya=(pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c);
        sa=sqrt(1-ya*ya);
        r=a/(2*sa);
        s=2*PI*r;
        printf("%.2lf\n", s);
    }
    return 0;
}
