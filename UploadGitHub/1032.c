#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j, lg, b, c, k;
    char a[80];
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++)
    {
        gets(a);
        lg=strlen(a);
        k=0;
        for(j=0; j<lg; j++)
        {
            if(a[j]!=' ')
            {
                if(a[j]>='A'&&a[j]<='Z')
                {
                    c='Z'-a[j];
                    b=2*k%26;
                    if(b<=c)
                        printf("%c", a[j]+b);
                    else
                        printf("%c", a[j]-(26-b));
                    k++;
                }
                else
                {
                    c='z'-a[j];
                    b=2*k%26;
                    if(b<=c)
                        printf("%c", a[j]+b);
                    else
                        printf("%c", a[j]-(26-b));
                    k++;
                }
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
