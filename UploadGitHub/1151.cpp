#include<cstring>
#include<iostream>

using namespace std;

int an[100];

void input()
{
    int N;
    while(cin>>N)
    {
        int sum=0, i=2, j;
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
        for(j=2; j<i; j++)
        {
            if(an[j]==0)
                continue;
            cout<<an[j]<<" ";
        }
        if(an[j])
            cout<<an[j]<<endl;
    }
}

int main()
{
    input();
    return 0;
}


