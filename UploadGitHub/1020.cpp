#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int,vector<int>, greater<int> >doct; //�������

int main()
{
    int i, p, m, n, t;
    double re;
    scanf("%d", &t);
    while(t--)
    {
        while(!doct.empty())
        {
            doct.pop();
        }
        scanf("%d%d%d", &n, &m, &p);
        int a[n+1];
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a,a+n); //�˔���С��������
        for(i=0; i<m; i++)
        {
            doct.push(a[n-1-i]); //�Ĵ�С���β����
        }
        //printf("%d\n", doct.top());
        for(i=m; i<n; i++) //���D�ɵ�Ĭ�J���ȼ����Ĵ�С���������޸ă��ȼ���С����
        {
            int temp;
            temp=doct.top()+a[n-1-i];
            //printf("%d\n%d\n", temp, doct.top());
            doct.pop();
            doct.push(temp);
        }
        for(i=0; i<m-1; i++)
        {
            doct.pop();
        }
        re=(1.0*doct.top())/p;
        printf("%.3lf\n", re);
    }
    return 0;
}
