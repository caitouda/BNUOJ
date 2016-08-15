#include<stdio.h>
#include<math.h>

int main()
{
    int casen, n, i;
    scanf("%d", &casen);
    for(i=0; i<casen; i++)
    {
        scanf("%d", &n);
        printf("%0.lf\n", pow(8, n));
    }
    return 0;
}
