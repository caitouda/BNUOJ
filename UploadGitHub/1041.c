#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j;
    char s[100];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &s);
        int b=strlen(s);
        for(j=0; j<b; j++)
        {
            if(s[j]=='\\')
                printf("\\\\");
            else if(s[j]=='\"')
                printf("\\\"");
            else if(s[j]=='%')
                printf("%%%%");
            else
                printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}
