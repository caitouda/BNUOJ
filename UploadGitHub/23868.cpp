#include<algorithm>
#include<iostream>

using namespace std;

typedef struct
{
    int length; //ľ�����L��
    bool mark; //ľ���Ƿ�ʹ���^
} Sticks;

int total, l; //total���ܽM�ɵ�ľ���ĽM����l���M�ɵ�ľ�����L��
int num, sum; //num��ݔ���������sum�����L��
Sticks sticks[70];

bool cmp(Sticks a, Sticks b)
{
    return a.length>b.length;
}

//s���ѽM�ɵ�ľ����Ŀ��len���ѽ��M�ɵ��L�ȣ�pos��������ľ�����˵�λ��
bool dfs(int s, int len, int pos)
{
    if(s==total)
        return true;
    for(int i=pos+1; i<num; i++)
    {
        //����@��ľ���ѽ����^���t�^�m��һ��
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
            //��֦�������ǰ����ʱ��ǰ�ߵĳ���Ϊ0������һ��û�гɹ���ʹ�ã�
            //˵����һ��ʼ��Ҫ������������������ϱض�����ɹ�
            //�˴��ļ�֦�����У���Ϊ����ļ�֦���ʡ�ܶ������������
            //������һ�£��˴���֦ʡȥ�ͻᳬʱ�ġ�������
            if(len==0)
                return false;
            //��֦�������ǰ����һ���ѵ���ľ����һ��������û��Ҫ����һ����
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
        sum=0; //��ӛ��0
        for(int i=0; i<num; i++)
        {
            cin>>sticks[i].length;
            sum+=sticks[i].length;
            sticks[i].mark=false;
        }
        //��ľ�����ճ��ȴӳ����̵�˳������
        sort(sticks, sticks+num, cmp);
        //��ľ�������L���Ǹ��_ʼ�����������С�ĽM��Ҳ����춵�����L���Ǹ�
        for(l=sticks[0].length; l<=sum; l++)
        {
            //��֦һ��������ܱ������f�����ܽM��������ľ��������һ��
            if(sum%l!=0)
                continue;
            total=sum/l; //�õ�ľ������Ŀ
            if(dfs(0, 0, -1))
            {
                cout<<l<<endl;
                break;
            }
        }
    }
    return 0;
}

