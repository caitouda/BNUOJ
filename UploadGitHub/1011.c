#include<stdio.h>
#include<math.h>

int main()
{
    char str[1000];
    int N, n=1; //N��ʾ����ѭ�h�Δ���n��ʾ��ǰ���Д�
    scanf("%d", &N);
    getchar(); //���ջ�܇
    while(1)
    {
        if(N==0)
            break;
        gets(str);
        printf("Problem #%d\n", n);
        int i, xsd, j; //С���c
        double sum;
        double P=0, I=0, U=0;
        for(i=0; str[i]!='\0'; i++)
        {
            sum=0;
            if(str[i]=='=')
            {
                xsd=0;
                for(j=i+1; str[j]!='A'&&str[j]!='V'&&str[j]!='W'; j++)
                {
                    if(str[j]=='m')
                        sum*=0.001;
                    else if(str[j]=='k')
                        sum*=1000;
                    else if(str[j]=='M')
                        sum*=1000000;
                    else if(str[j]=='.')
                        xsd=j;
                    else
                    {
                        if(xsd==0)
                            sum=sum*10+str[j]-'0';
                        else
                            sum+=(str[j]-'0')*pow(10, (xsd-j));
                    } //else
                } //for j
                if(str[j]=='A')
                    I=sum;
                else if(str[j]=='V')
                    U=sum;
                else
                    P=sum;
            } //if '='
        } //for i
        if(I==0)
            printf("I=%.2lfA\n\n", P/U);
        else if(U==0)
            printf("U=%.2lfV\n\n", P/I);
        else if(P==0)
            printf("P=%.2lfW\n\n",I*U);
        n++;
        N--;
    } //while
    return 0;
}
