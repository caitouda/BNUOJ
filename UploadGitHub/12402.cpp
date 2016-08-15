#include<iostream>

using namespace std;

int main()
{
    int Joseph[14]={0}; //打表，保存各個k值對應的m值
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
        int n=2*k; //總人數
        int ans[30]={0}; //第i輪殺掉對應當前輪的編號為ans[i]的人
        //PS:每一輪都以報數為“1”的人開始重新編號
        int m=1; //所求的最少的報數
        for(int i=1; i<=k; i++) //輪數
        {
            ans[i]=(ans[i-1]+m-1)%(n-i+1); //n-i為剩餘的人數
            if(ans[i]<k) //把好人殺掉了，m值不是所求
            {
                i=0;
                m++; //枚舉m值
            }
        }
        Joseph[k]=m;
        cout<<m<<endl;
    }
    return 0;
}

