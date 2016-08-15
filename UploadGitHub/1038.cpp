#include <stdio.h>

char map[101][101];
int u[101][101];
int m, n, ans;
int queue[11000][2], r, w;
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

bool pd(int a, int b)
{
    if(a<0||b<0)
        return false;
    if(a<m&&b<n&&map[a][b]!='*')
        return true;
    return false;
}

int main()
{
    int i, j;
    scanf("%d%d", &m, &n);
    for(i=0; i<m; i++)
    {
        scanf("%s", map[i]);
        if(i==0||i==m-1)
        {
            for(j=0; j<n; j++)
                if(map[i][j]=='.')
                {
                    queue[w][0]=i;
                    queue[w++][1]=j; //還是w，然後加1
                    u[i][j]=1;
                }
        }
        else if(map[i][0]=='.')
        {
            queue[w][0]=i;
            queue[w++][1]=0;
            u[i][0]=1;
        }
        else if(map[i][n-1]=='.')
        {
            queue[w][0]=i;
            queue[w++][1]=n-1;
            u[i][n-1]=1;
        }
    }
    while(r<w)
    {
        int xx, yy;
        for(i=0; i<4; i++)
        {
            xx=queue[r][0]+dx[i];
            yy=queue[r][1]+dy[i];
            if(pd(xx, yy)&&!u[xx][yy])
            {
                queue[w][0]=xx;
                queue[w++][1]=yy;
                u[xx][yy]=1;
            }
        }
        r++;
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(u[i][j]==0&&map[i][j]!='*')
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

