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
        //若n是行數
        //還原二維數組
        int index=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                word[j][i]=miwen[index++];
            }
        }
        //拿到明文
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                tureMingWen.append(1, word[i][j]);
            }
        }
        //判斷是否正確
        if(tureMingWen.find(mingwen)!=string::npos)
        {
            //找到了，輸出tureMingWen
            cout<<tureMingWen<<endl;
        }
        else
        {
            tureMingWen="";
            //n是列數
            //還原數組
            int index=0;
            for(int i=0; i<n; i++)
            {
                for (int j=0; j<m; j++)
                {
                    word[j][i]=miwen[index++];
                }

            }
            //拿到明文
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
