#include<iostream>
#include<cstring>
#define MAXN 100

using namespace std;

int num[MAXN+50][MAXN+50], mat1[MAXN+50][MAXN+50], mat2[MAXN+50][MAXN+50];

int main()
{
    int n, i, j, k, l;
    int ans, sum;
    while(cin>>n)
    {
        if(n==0)
            continue;
        ans=-9000000;
        memset(mat1, 0, sizeof(mat1));
        memset(mat2, 0, sizeof(mat2));
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                cin>>num[i][j];
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
            {
                for(i=1; i<=j; i++)
                {
                    sum=0;
                    for(l=i; l<=j; l++)
                        sum+=num[k][l];
                    mat2[i][j]=max(sum, mat1[i][j]+sum);
                    if(mat2[i][j]>ans)
                        ans=mat2[i][j];
                }
            }
            memcpy(mat1, mat2, sizeof(mat1));
        }
        cout<<ans<<endl;
    }
    return 0;
}

