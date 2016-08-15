#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

char word1[104][32];
char word2[104][32];
int F[104][104], dp[104][104];

void output(int id, int flag)
{
    if(id/1000&&id%1000)
    {
        output(F[id/1000-1][id%1000-1], 1);
        printf("%s", word1[id/1000-1]);
        if(flag)
            printf(" ");
    }
}

int main()
{
    while(cin>>word1[0])
    {
        int count1=1, count2=0;
        if(strcmp(word1[0], "#"))
        {
            while(cin>>word1[count1]&&strcmp(word1[count1], "#"))
                count1++;
        }
        else
            count1=0;
        while(cin>>word2[count2]&&strcmp(word2[count2], "#"))
            count2++;
        for(int i=0; i<102; ++i)
            for(int j=0; j<102; ++j)
            {
                F[i][j]=0;
                dp[i][j]=0;
            }
        for(int i=1; i<=count1; ++i)
            for(int j=1; j<=count2; ++j)
                if(!strcmp(word1[i-1], word2[j-1]))
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    F[i][j]=1000*i+j;
                }
                else if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    F[i][j]=F[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    F[i][j]=F[i-1][j];
                }
        if(F[count1][count2])
            output(F[count1][count2], 0);
        printf("\n");
    }
    return 0;
}

