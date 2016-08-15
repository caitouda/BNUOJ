#include<stdio.h>
#include<string.h>

int main()
{
    int X, Y, lg, i, j, p, q, count;
    char a[100000];
    char b[400][400];
    scanf("%d%d", &X, &Y);
    getchar();
    while(gets(a))
    {
        lg=strlen(a);
        p=0;
        q=0;
        for(i=0; i<lg; i++)
        {
            if(a[i]>='A'&&a[i]<='Z')
            {
                b[p][q]=a[i];
                q++;
                if(q==Y)
                {
                    p++;
                    q=0;
                }
            }
            if(a[i]>='a'&&a[i]<='z')
            {
                b[p][q]=a[i]-32;
                q++;
                if(q==Y)
                {
                    p++;
                    q=0;
                }
            }
        }
        count=0;
        while(p!=X)
        {
            b[p][q]=count%26+65;
            count++;
            q++;
            if(q==Y)
            {
                p++;
                q=0;
            }
        }
        /*for(i=0; i<X; i++)
        {
            for(j=0; j<Y; j++)
            {
                printf("%c", b[i][j]);
            }
            printf("\n");
        }*/
        for(j=0; j<Y; j++)
        {
            for(i=0; i<X; i++)
            {
                printf("%c", b[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
