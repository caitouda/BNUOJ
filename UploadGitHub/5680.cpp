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
        int time['L'+1]={0}; //標記各個字母被懷疑的次數
        bool zero['L'+1]={false}; //標記絕對為真幣的字母（令天枰平衡的所有字母）
        for(int k=0; k<3; k++)
            cin>>left[k]>>right[k]>>status[k];
        for(int i=0; i<3; i++)
        {
            switch(status[i][0]) //檢查天枰狀態
            {
            case 'u': //up，天枰左重右輕
            {
                for(int j=0; left[i][j]; j++)
                {
                    time[left[i][j]]++; //左重
                    time[right[i][j]]--; //右輕
                }
                break;
            }
            case 'd': //down，天枰左輕右重
            {
                for(int j=0; left[i][j]; j++)
                {
                    time[left[i][j]]--; //左輕
                    time[right[i][j]]++; //右重
                }
                break;
            }
            case 'e': //even，天枰平衡
            {
                for(int j=0; left[i][j]; j++)
                {
                    zero[left[i][j]]=true; //絕對真幣
                    zero[right[i][j]]=true; //絕對真幣
                }
                break;
            }
            }
        }
        int max=-1; //查找被懷疑程度最高的硬幣（假幣）
        char alpha;
        for(int j='A'; j<='L'; j++)
        {
            if(zero[j]) //絕對真幣
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

