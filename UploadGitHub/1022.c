#include<stdio.h>

int fun(char *str, int x)
{
    int i, num, ans, f, tn, k, j;
    ans=0;
    i=0;
    f=1;
    while(str[i])
    {
        if(str[i]=='-')
        {
            f=-1; //�ஔ출p
            i++;
        }
        else if(str[i]=='+')
        {
            f=1; //�ஔ춼�
            i++;
        }
        num=0;
        tn=0;
        while(str[i]>='0'&&str[i]<='9') //�������g������
        {
            num=10*num+str[i]-'0';
            i++;
            tn=1; //�����ϵ�����
        }
        if(str[i]!='x') //����x�t����֮ǰ�ļӜp���˕r�϶���+��-���t�ص���ѭ�h�����Д�
        {
            ans+=f*num;
        }
        else //��x
        {
            i++;
            if(tn==0) //�]�������t��1
                num=1;
            k=1; //3x+5�t���M��if��������Ҫk��1
            if(str[i]=='^') //��x�K�ҽ����ǳ˷�����3x^5
            {
                i++;
                k=0;
                while(str[i]>='0'&&str[i]<='9')
                {
                    k=10*k+str[i]-'0';
                    i++;
                }
            }
            for(j=0; j<k; j++)
                num*=x;
            ans+=f*num; //�F������֮ǰ�ļӜp
        }
    }
    return ans;
}

int tstr[10000], lt;
int ts[10000], ls;

int main()
{
    int prob, i, j, k, n, t, ls;
    char str[100];
    scanf("%d", &prob);
    while(prob--)
    {
        scanf("%d", &n);
        lt=0;
        while(n--)
        {
            getchar();
            scanf("%s%d",str, &t);
            t=fun(str, t);
            ls=0;
            while(t!=0) //�D����M��
            {
                ts[ls]=t%2;
                t/=2;
                ls++;
            }
            for(i=ls-1; i>=0; i--) //���^��
            {
                tstr[lt]=ts[i];
                lt++;
            }
        }
        t=0;
        for(i=0; i<lt; i++)
        {
            t=t*2+tstr[i];
            if(i%5==4) //�M5���t׃����ĸ
            {
                if(t>=1&&t<=26)
                    printf("%c", 'A'-1+t);
                else
                    printf(" ");
                t=0;
            }
        }
        printf("\n%d\n", lt%5);
    }
    return 0;
}

