#include<iostream>

using namespace std;

int main()
{
    int Joseph[14]={0}; //����������kֵ������mֵ
    int k;
    while(cin>>k)
    {
        if(!k)
            break;
        if(Joseph[k])
        {
            cout<<Joseph[k]<<endl;
            continue;
        }
        int n=2*k; //���˔�
        int ans[30]={0}; //��i݆���􌦑���ǰ݆�ľ�̖��ans[i]����
        //PS:ÿһ݆���Ԉ󔵞顰1�������_ʼ���¾�̖
        int m=1; //��������ٵĈ�
        for(int i=1; i<=k; i++) //݆��
        {
            ans[i]=(ans[i-1]+m-1)%(n-i+1); //n-i��ʣ�N���˔�
            if(ans[i]<k) //�Ѻ��˚����ˣ�mֵ��������
            {
                i=0;
                m++; //ö�emֵ
            }
        }
        Joseph[k]=m;
        cout<<m<<endl;
    }
    return 0;
}

