#include<stdio.h>

int main()
{
    int T, i, a, b, c, m[16]= {1, 4, 10, 20, 35, 56, 81, 108, 135, 160, 181, 196, 206, 212, 215, 216};
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d%d", &a, &b);
        c=(a+b)%19;
        if(c==0||c==1||c==2)
            printf("1.0000\n");
        else
            printf("%.4f\n", m[18-c]*1.00000/216);
    }
    return 0;
}
