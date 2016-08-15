#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int N, K, L, a[100010], i, sum, count=0;
    scanf("%d%d%d", &N, &L, &K);
    for(i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    sum=L;
    for(i=0; i<N; i++)
    {
        if(a[i]<=sum)
        {
            count++;
            sum=sum+K;
        }
        else
            break;
    }
    printf("%d", count);
    return 0;
}

