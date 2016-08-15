#include<stdio.h>

int main()
{
    double a, b, c, d;
    for(a=0.01; a<7.11; a=a+0.01)

        for(b=a; b<7.11-a; b=b+0.01)

            for(c=b; c<7.11-a-b; c=c+0.01)
            {
                d=7.11-a-b-c;
                if(d>=c&&(int)(a*b*c*d*100000000)==711000000)

                    printf("%.2lf %.2lf %.2lf %.2lf", a, b, c, d);
            }
    return 0;
}
