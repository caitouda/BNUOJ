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

/*sort������*/
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
        /*�D�f�Ǽƹ諸�Ӽ�*/
        for(int i=0; i<m; i++)
        {
            cin>>str;
            count=0;
            for(int j=0; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(str[j]>str[k])
                        count++;
            /*�O�s�H��*/
            inv[i].key=count;
            inv[i].pos=i;
            inv[i].str=str;
        }
        /*���f�Ǽƹ�j�p/�Ǹ��Ƨ�*/
        sort(inv, inv+m, cmp);
        /*��X���G*/
        for(int i=0; i<m; i++)
            cout<<inv[i].str<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}



