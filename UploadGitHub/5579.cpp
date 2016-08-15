#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct dna
{
    int pos;
    int key;
    string str;
};

/*sort比較函數*/
bool cmp(const dna &a, const dna &b)
{
    if(a.key!=b.key)
        return a.key<b.key;
    else
        return a.pos<b.pos;
}

int main()
{
    int t, n, m, count;
    dna inv[110];
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        /*求逆序數對的個數*/
        for(int i=0; i<m; i++)
        {
            cin>>str;
            count=0;
            for(int j=0; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(str[j]>str[k])
                        count++;
            /*保存信息*/
            inv[i].key=count;
            inv[i].pos=i;
            inv[i].str=str;
        }
        /*按逆序數對大小/序號排序*/
        sort(inv, inv+m, cmp);
        /*輸出結果*/
        for(int i=0; i<m; i++)
            cout<<inv[i].str<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}


