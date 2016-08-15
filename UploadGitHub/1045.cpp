#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int T, N, M, a[10010], b[10010], c[10010], count, i, j;
    scanf("%d", &T);
    while(T--)
    {
        count=-1;
        scanf("%d", &N);
        for(i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &M);
        for(i=0; i<M; i++)
        {
            scanf("%d", &b[i]);
        }
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(b[j]==a[i])
                {
                    count++;
                    c[count]=a[i];
                    break;
                }
            }
        }
        if(count==-1)
            printf("empty\n");
        else
        {
            sort(c, c+count+1);
            for(i=0; i<count; i++)
            {
                printf("%d ", c[i]);
            }
            printf("%d\n", c[count]);
        }
    }
    return 0;
}
