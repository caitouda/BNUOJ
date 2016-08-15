#include<stdio.h>
#include<string.h>

int main()
{
    char a[25][25];
    char b[25][25];
    char c[25];
    int L, N, i, j, lg, flag;
    scanf("%d%d", &L, &N);
    for(i=0; i<L; i++)
    {
        scanf("%s", a[i]);
        scanf("%s", b[i]);
    }
    for(j=0; j<N; j++)
    {
        scanf("%s", c);
        lg=strlen(c);
        flag=0;
        for(i=0; i<L; i++)
        {
            if(strcmp(c, a[i])==0)
            {
                printf("%s\n", b[i]);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(c[lg-1]=='y'&&c[lg-2]!='a'&&c[lg-2]!='e'&&c[lg-2]!='i'&&c[lg-2]!='o'&&c[lg-2]!='u')
            {
                c[lg-1]='i';
                c[lg]='e';
                c[lg+1]='s';
                for(i=0; i<lg+2; i++)
                {
                    printf("%c", c[i]);
                }
                printf("\n");
            }
            else if(c[lg-1]=='o'||c[lg-1]=='s'||c[lg-1]=='x'||(c[lg-2]=='c'&&c[lg-1]=='h')||(c[lg-2]=='s'&&c[lg-1]=='h'))
            {
                c[lg]='e';
                c[lg+1]='s';
                for(i=0; i<lg+2; i++)
                {
                    printf("%c", c[i]);
                }
                printf("\n");
            }
            else
            {
                c[lg]='s';
                for(i=0; i<lg+1; i++)
                {
                    printf("%c", c[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
