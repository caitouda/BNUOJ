#include<stdio.h>

int main()
{
    char a[4][65], b[4][65];
    int i, j, k;
    for(i=0; i<64; i++)
    {
        if((i+1)%8==0)
        {
            scanf("%c", &a[0][i]);
            getchar();
        }
        else
            scanf("%c", &a[0][i]);
    }
    for(i=0; i<64; i++)
    {
        if((i+1)%8==0)
        {
            scanf("%c", &b[0][i]);
            getchar();
        }
        else
            scanf("%c", &b[0][i]);
    }
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            a[1][8*j+7-i]=a[0][8*i+j];
            b[1][8*j+7-i]=b[0][8*i+j];
            a[2][63-8*i-j]=a[0][8*i+j];
            b[2][63-8*i-j]=b[0][8*i+j];
            a[3][56-8*j+i]=a[0][8*i+j];
            b[3][56-8*j+i]=b[0][8*i+j];
        }
    }
    double sum=0;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            for(k=0; k<64; k++)
            {
                if(a[i][k]=='.'&&b[j][k]=='.')
                {
                    sum+=1;
                }
                if(a[i][k]=='*'&&b[j][k]=='*')
                {
                    sum+=2;
                }
                if(a[i][k]=='#'&&b[j][k]=='#')
                {
                    sum+=3;
                }
            }
        }
    }
    sum/=16;
    printf("%.2f\n", sum);
    return 0;
}

