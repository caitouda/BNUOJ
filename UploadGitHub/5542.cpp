#include<cstring>
#include<iostream>

using namespace std;

int used[101];
int arry[101];
int p[101];
int n, num;

void print()
{
    cout<<p[1];
    for(int i=2; i<=6; i++)
        cout<<" "<<p[i];
    cout<<endl;
}

void DFS(int d, int m)
{
    if(d>6)
    {
        print();
    }
    else
        for(int i=m; i<=num; i++)
        {
            if(used[i]==0)
            {
                p[d]=arry[i];
                used[i]=1;
                DFS(d+1,i+1);
                used[i]=0;
            }
        }
}

int main()
{
    int v=0;
    while(cin>>num, num)
    {
        memset(used, 0, sizeof(used));
        if(v)
            cout<<endl;
        v++;
        for(int k=1; k<=num; k++)
            cin>>arry[k];
        DFS(1, 1);
    }
    return 0;
}

