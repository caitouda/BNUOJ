#include<stdio.h>
#include<string.h>

int main()
{
    int T, lg, i, j, count, sum;
    char a[200];
    int b[200];
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        gets(a);
        lg=strlen(a);
        count=0;
        sum=0;
        for(i=0; i<lg; i++)
        {
            if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='1'&&a[i]<='9'))
            {
                count++;
                b[count]=a[i];
            }
        }
        for(j=1; j<=count; j++)
        {
            sum=sum+b[j];
        }
        printf("%d\n", sum%100);
    }
    return 0;
}
