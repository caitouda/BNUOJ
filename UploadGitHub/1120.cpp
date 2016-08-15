#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define END -1

using namespace std;

const int maxn=1001;
int BigNumber[maxn]={0};

void multiple(int a[], int n) //���������
{
    int i, j;
    int c=0; //�Mλ
    for(i=1; i<=a[0]; i++)
    {
        a[i]=a[i]*n+c;
        c=a[i]/10;
        a[i]%=10;
    }
    while(c)
    {
        a[i++]=c%10;
        c/=10;
    }
    a[0]=i-1; //a[0]���������λ��
    return;
}

void output(int pos)
{
    int i, j;
    if(BigNumber[0]>pos) //������
    {
        for(j=0, i=BigNumber[0]; j<BigNumber[0]-pos; j++, i--) //������ݔ��С���cǰ�Ĕ���
            printf("%d", BigNumber[i]);
        for(j=1; BigNumber[j]==0; j++) //ȥ��
            BigNumber[j]=END;
        if(BigNumber[i]==END||i==0) //������Ԓ
            return;
        printf(".");
        for(; BigNumber[i]!=END&&i>=1 ; i--) //ݔ��С���c��Ĕ���
            printf("%d", BigNumber[i]);
    }
    else //�o����
    {
        printf(".");
        for(i=0; i<pos-BigNumber[0]; i++)
            printf("0");
        for(j=1; BigNumber[j]==0; j++) //ȥ��
            BigNumber[j]=END;
        for(i=BigNumber[0]; BigNumber[i]!=END&&i>=1; i--)
            printf("%d", BigNumber[i]);
    }
    return ;
}

int main()
{
    char s[10];
    int n;
    int pos, num;
    while(~scanf("%s%d", s, &n))
    {
        int i, j;
        int l=strlen(s);
        num=0;
        memset(BigNumber, 0 ,sizeof(BigNumber));
        for(i=0, pos=5; i<l ; i++) //POS=5 ���fһ�]��С���c���tPOS=5
        {
            if(s[i]=='.')
                pos=i;
            else
                num=num*10+s[i]-'0'; //��С���D�Q������
        }
        BigNumber[0]=BigNumber[1]=1;
        pos=(5-pos)*n; //һ���Ў�λС��
        while(n--)
        {
            multiple(BigNumber, num); //�����
        }
        output(pos); //ݔ��
        printf("\n");
    }
    return 0;
}

