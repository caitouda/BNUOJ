#include<cstdio>
#define MAXN 3300000

using namespace std;

int ans[1200000];
bool prime[MAXN];

void getPrime()
{
{
    int i, j;
    prime[0]=prime[1]=false;
    for(i=2; i<MAXN; i++)
    {
        prime[i]=true;
    }
    for(i=2; i*i<MAXN; i++)
    {
        if(prime[i])
        {
            for(j=i*i; j<MAXN; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

void init()
{
    int i;
    getPrime();
    ans[1]=0;
    for (i=2; i<=1000000; i++)
    {
        if(prime[3*i+7]==true)
            ans[i]=ans[i-1]+1; //題目中[]不是大括號，是取整
        else
            ans[i]=ans[i-1];
    }
}

int main()
{
    int prob, i, t, n;
    init();
    scanf("%d", &prob);
    while(prob--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}
