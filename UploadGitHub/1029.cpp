#include<cstdio>
#include<algorithm>

using namespace std;

struct qujian
{
    int a, b;
};

bool cmp(qujian p, qujian q)
{
    return p.a<q.a;
}

int main()
{
    struct qujian qj[50010];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &qj[i].a, &qj[i].b);
    sort(qj, qj+n, cmp);
    int left=qj[0].a;
    int right=qj[0].b;
    for(int i=1; i<n; i++)
    {
        if(qj[i].a<=right)
        {
            if(qj[i].b>right)
            {
                right=qj[i].b;
            }
        }
        else
        {
            printf("%d %d\n", left, right);
            left=qj[i].a;
            right=qj[i].b;
        }
    }
    printf("%d %d\n", left, right);
    return 0;
}
