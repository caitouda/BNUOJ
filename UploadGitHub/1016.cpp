#include<string>
#include<iostream>

using namespace std;

char word[40005][40005];

int main()
{
    int n;
    while(cin>>n)
    {
        string mingwen, miwen;
        string tureMingWen="";
        cin>>mingwen>>miwen;
        int m=miwen.length()/n;
        //��n���Д�
        //߀ԭ���S���M
        int index=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                word[j][i]=miwen[index++];
            }
        }
        //�õ�����
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                tureMingWen.append(1, word[i][j]);
            }
        }
        //�Д��Ƿ����_
        if(tureMingWen.find(mingwen)!=string::npos)
        {
            //�ҵ��ˣ�ݔ��tureMingWen
            cout<<tureMingWen<<endl;
        }
        else
        {
            tureMingWen="";
            //n���Д�
            //߀ԭ���M
            int index=0;
            for(int i=0; i<n; i++)
            {
                for (int j=0; j<m; j++)
                {
                    word[j][i]=miwen[index++];
                }

            }
            //�õ�����
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    tureMingWen.append(1, word[i][j]);
                }
            }
            cout<<tureMingWen<<endl;
        }
    }
    return 0;
}
