#include<iostream>

using namespace std;

int main()
{
    int a, b, c, d, t;
    cin>>t;
    while(t--)
    {
        int temp=0;
        while(cin>>a>>b>>c>>d)
        {
            if(a==-1&&b==-1&&c==-1&&d==-1)
                break;
            int n=(5544*a+14421*b+1288*c)%21252;
            int ans=n>d?n-d:21252+n-d ;
            cout<<"Case "<<++temp<<": the next triple peak occurs in "<<ans<<" days."<<endl;
        }
    }
    return 0 ;
}

