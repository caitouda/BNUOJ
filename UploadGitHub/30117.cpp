#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n, ans[100];
bool flag;

void dfs(int cur, int depth)
{
    if(flag)
        return;
    if(cur==depth)
    {
        if(ans[cur]==n)
            flag=true;
        return ;
    }
    for(int i=0; i<=cur; ++i)
    {
        for(int j=i; j<=cur; ++j)
            if(ans[i]+ans[j]>ans[cur]&&ans[i]+ans[j]<=n ) //�o�̤]�i��ŪK
            {
                //�U���o�Ӵ�K�������n�I�I�p�G�q��e�@�����U���O��̤ܳj�������٬O����F��n�A���L
                bool ok = false;
                int sum=ans[i]+ans[j];
                for(int k=cur+2; k<=depth; ++k)
                    sum*=2;
                if(sum<n)
                    continue;
                ans[cur+1] = ans[i]+ans[j];
                dfs(cur+1, depth);
                if(flag)
                return;
            }
    }
}

int main()
{
    while(scanf("%d", &n), n)
    {
        memset(ans, 0, sizeof(ans));
        ans[0]=1;
        flag=false;
        //�p��X�ܤֻݭn�h�֨B
        int m=1, depth=0;
        while(m<n)
        {
            m*=2;
            depth++;
        }
        //�q�̤֨B�}�l�i�歡�N�[�`�j��
        while(true)
        {
            dfs(0, depth);
            if(flag)
                break;
            depth++;
        }
        printf("%d", ans[0]);
        for(int i=1; i<=depth; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}


