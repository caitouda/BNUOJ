#include<cmath>
#include<iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    for(int c=1; c<=cases; c++)
    {
        char left[3][6], right[3][6], status[3][6];
        int time['L'+1]={0}; //��ӛ������ĸ�����ɵĴΔ�
        bool zero['L'+1]={false}; //��ӛ�^������ŵ���ĸ��������ƽ���������ĸ��
        for(int k=0; k<3; k++)
            cin>>left[k]>>right[k]>>status[k];
        for(int i=0; i<3; i++)
        {
            switch(status[i][0]) //�z�����Ҡ�B
            {
            case 'u': //up�������������p
            {
                for(int j=0; left[i][j]; j++)
                {
                    time[left[i][j]]++; //����
                    time[right[i][j]]--; //���p
                }
                break;
            }
            case 'd': //down���������p����
            {
                for(int j=0; left[i][j]; j++)
                {
                    time[left[i][j]]--; //���p
                    time[right[i][j]]++; //����
                }
                break;
            }
            case 'e': //even������ƽ��
            {
                for(int j=0; left[i][j]; j++)
                {
                    zero[left[i][j]]=true; //�^�����
                    zero[right[i][j]]=true; //�^�����
                }
                break;
            }
            }
        }
        int max=-1; //���ұ����ɳ̶���ߵ�Ӳ�ţ��َţ�
        char alpha;
        for(int j='A'; j<='L'; j++)
        {
            if(zero[j]) //�^�����
                continue;
            if(max<=abs(time[j]))
            {
                max=abs(time[j]);
                alpha=j;
            }
        }
        cout<<alpha<<" is the counterfeit coin and it is ";
        if(time[alpha]>0)
            cout<<"heavy."<<endl;
        else
            cout<<"light."<<endl;
    }
    return 0;
}

