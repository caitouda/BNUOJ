#include<cstring>
#include<iostream>

using namespace std;

/*壓縮數字串n，存放到t*/
void R(char* n, char* t)
{
    int i, j;
    int time[10]= {0}; //記錄n中各個數​​字出現的次數
    for(i=0; n[i]; i++)
        time[n[i]-'0']++;
    for(i=0, j=0; i<10; i++)
    {
        if(time[i])
        {
            if(time[i]<10) //數字i出現次數<10，即佔1位
            {
                t[j++]=time[i]+'0';
                t[j++]=i+'0';
            }
            else //數字i出現次數>=10，即佔2位
            {
                t[j++]=time[i]/10+'0';
                t[j++]=time[i]%10+'0';
                t[j++]=i+'0';
            }
        }
    }
    t[j]='\0';
    return;
}

int main()
{
    int t, i, j;
    char n[16][85]; //n[0]為原串，n[1~15]分別為n連續壓縮15次的數字串
    cin>>t;
    while(t--)
    {
        while(cin>>n[0]&&n[0][0]!='-')
        {
            bool flag1=false; //屬性1，n is self-inventorying
            int flag2=0; //屬性2，n is self-inventorying after j steps，順便記錄j
            int flag3=0; //屬性3，n is enters an inventory loop of length k，順便記錄k
            for(i=1; i<=15; i++)
                R(n[i-1], n[i]);
            if(!strcmp(n[0], n[1])) //屬性1，n壓縮1次就是其本身
                flag1=true;
            if(!flag1)
            {
                for(j=1; j<15; j++)
                    if(!strcmp(n[j], n[j+1])) //屬性2， n壓縮j次後的數字串n[j]具有屬性1
                    {
                        flag2=j;
                        break;
                    }
                if(!flag2)
                {
                    for(j=1; j<=15; j++) //屬性3，兩兩枚舉各次壓縮的數字串，注意循環間隔>=2
                    {
                        for(i=0; i<=j-2; i++)
                        {
                            if(!strcmp(n[j], n[i]))
                            {
                                flag3=j-i;
                                break;
                            }
                        }
                        if(flag3)
                            break;
                    }
                }
            }
            if(flag1)
                cout<<n[0]<<" is self-inventorying"<<endl;
            else if(flag2)
                cout<<n[0]<<" is self-inventorying after "<<flag2<<" steps"<<endl;
            else if(flag3)
                cout<<n[0]<<" enters an inventory loop of length "<<flag3<<endl;
            else
                cout<<n[0]<<" can not be classified after 15 iterations"<<endl;
        }
        if(t)
            cout<<endl;
    }
    return 0;
}
