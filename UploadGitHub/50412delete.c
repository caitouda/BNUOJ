#include<stdio.h>
#include<math.h>

int main()
{
    int N, i, ZZ;
    double  X, Y ,area, Z;
    scanf("%d", &N);
    for(i=1; i<=N; i++)
    {
        scanf("%lf%lf", &X, &Y);
        area=acos(-1.0)*(X*X+Y*Y)/2;
        //printf("%lf\n", area);
        Z=area/50;
        ZZ=(int)Z;
        if(Z-ZZ>0)
            printf("Property %d: This property will begin eroding in year %d.\n", i, ZZ+1);
        else
            printf("Property %d: This property will begin eroding in year %d.\n", i, ZZ);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}

