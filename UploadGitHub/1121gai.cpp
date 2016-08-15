#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[100010][44], c[44], d[44];

int cmp_string(const void * _a, const void *_b) //比較函數
{
    char *a=(char *)_a;
    char *b=(char *)_b;
    return strcmp(a, b);
}

int main()
{
    int t=1, temp=0;
    long i, j, z, n;
    scanf("%ld\n", &n);
    for(i=0; i<n; i++) //轉化成標準形式
    {
        gets(d);
        for(j=0,z=0; d[z]!='\0'; z++)
        {
            if(d[z]!='-')
            {
                if(j==3)
                    a[i][j++]='-';
                if('0'<=d[z]&&d[z]<='9')
                    a[i][j++]=d[z];
                else
                {
                    if(d[z]=='A'||d[z]=='B'||d[z]=='C')
                        a[i][j++]='2';
                    else if(d[z]=='D'||d[z]=='E'||d[z]=='F')
                        a[i][j++]='3';
                    else if(d[z]=='G'||d[z]=='H'||d[z]=='I')
                        a[i][j++]='4';
                    else if(d[z]=='J'||d[z]=='K'||d[z]=='L')
                        a[i][j++]='5';
                    else if(d[z]=='M'||d[z]=='N'||d[z]=='O')
                        a[i][j++]='6';
                    else if(d[z]=='P'||d[z]=='R'||d[z]=='S')
                        a[i][j++]='7';
                    else if(d[z]=='T'||d[z]=='U'||d[z]=='V')
                        a[i][j++]='8';
                    else if(d[z]=='W'||d[z]=='X'||d[z]=='Y')
                        a[i][j++]='9';
                }
            }
        }
    }
    qsort(a,n,sizeof(a[0]), cmp_string); //按字典排序字符串
    strcpy(c, a[0]);
    for(i=1; i<n; i++) //統計字符串若有相同即輸出
    {
        while(strcmp(c, a[i])==0)
        {
            i++;
            t++;
        }
        if(t>1)
        {
            printf("%s %d\n", c, t);
            temp=1;
        }
        strcpy(c, a[i]);
        t=1;
    }
    if(temp!=1) //若沒有相同的就輸出一下內容
        printf("No duplicates. \n");
    return 0;
}
