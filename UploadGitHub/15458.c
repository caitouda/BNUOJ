#include<stdio.h>

int main()
{
    double n, k;
    while(scanf("%lf%lf", &n, &k)==2)
    {
        if(n==0&&k==0)
            break;
        double ans=1;
        if(2*k>n)
            k=n-k; //�`�N�u��
        while(k>=1) //���l�On*n-1*...*n-k+1 �@k��,�����Ok*k-1*...*1�@k���A�ҥH�_���ר��M��k���j�p
        {
            ans*=n/k;
            n--, k--;
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}
