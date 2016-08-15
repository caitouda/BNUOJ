#include<algorithm>
#include<iostream>

using namespace std;

typedef struct
{
    int length; //木棒的長度
    bool mark; //木棒是否被使用過
} Sticks;

int total, l; //total：能組成的木棒的組數，l：組成的木棒的長度
int num, sum; //num：輸入的整數，sum：總長度
Sticks sticks[70];

bool cmp(Sticks a, Sticks b)
{
    return a.length>b.length;
}

//s：已組成的木棒數目，len：已經組成的長度，pos：搜索的木棒的下標的位置
bool dfs(int s, int len, int pos)
{
    if(s==total)
        return true;
    for(int i=pos+1; i<num; i++)
    {
        //如果這個木棒已經用過，則繼續下一根
        if(sticks[i].mark)
            continue;
        if(len+sticks[i].length==l)
        {
            sticks[i].mark=true;
            if(dfs(s+1, 0, -1))
                return true;
            sticks[i].mark=false;
            return false;
        }
        else if(sticks[i].length+len<l)
        {
            sticks[i].mark=true;
            if(dfs(s, len+sticks[i].length, i))
                return true;
            sticks[i].mark=false;
            //剪枝：如果当前搜索时，前边的长度为0，而第一根没有成功的使用，
            //说明第一根始终要被废弃，所以这种组合必定不会成功
            //此处的剪枝必须有，因为这里的剪枝会节省很多的无用搜索，
            //我试了一下，此处剪枝省去就会超时的。。。。
            if(len==0)
                return false;
            //剪枝：如果当前和上一次搜到的木棒是一样长的则没必要再搜一次了
            while(sticks[i].length==sticks[i+1].length)
                i++;
        }
    }
    return false;
}

int main()
{

    while(cin>>num&&num!=0)
    {
        sum=0; //標記為0
        for(int i=0; i<num; i++)
        {
            cin>>sticks[i].length;
            sum+=sticks[i].length;
            sticks[i].mark=false;
        }
        //将木棒按照长度从长到短的顺序排序
        sort(sticks, sticks+num, cmp);
        //從木棒的最長的那根開始搜索，因為最小的組合也會大於等於最長的那根
        for(l=sticks[0].length; l<=sum; l++)
        {
            //剪枝一：如果不能被整除說明不能組成整數根木棒，搜下一個
            if(sum%l!=0)
                continue;
            total=sum/l; //得到木棒總數目
            if(dfs(0, 0, -1))
            {
                cout<<l<<endl;
                break;
            }
        }
    }
    return 0;
}

