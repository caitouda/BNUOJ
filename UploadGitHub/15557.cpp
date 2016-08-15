#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int an[1010];

void input()
{
    int T, N;
    cin>>T;
    for(int o=1; o<=T; o++)
    {
        cin>>N;
        int sum=0, i=2, k, count=0, count1=0;
        memset(an, 0, sizeof(an));
        while(sum<=N)
        {
            an[i]=i;
            sum+=i;
            i++;
        }
        int flag=sum-N;
        if(flag==1)
        {
            an[2]=0;
            an[i-1]++;
        }
        else
            an[flag]=0;
        for(k=0; k<i; ++k)
        {
            if(an[k])
                count++;
        }
        if(an[k])
            count++;
        for(k=0; k<=i; ++k)
        {
            if(an[k])
            {
                count1++;
                if(count1<count)
                    cout<<an[k]<<" ";
                else
                    cout<<an[k]<<endl;
            }
        }
        if(o!=T)
            cout<<endl;
    }
}

int main()
{
    input();
    return 0;
}



