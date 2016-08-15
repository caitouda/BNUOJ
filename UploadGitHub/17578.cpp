#include<stdio.h>

int queue[100][2], r, w;
int u[10][10];
int dx[8]={1, 2, 2, 1, -1, -2, -1, -2};
int dy[8]={2, 1, -1, -2, 2, 1, -2, -1};
int xx, yy;

bool judge(int x, int y)
{
    if(x<0||y<0)
        return false;
    else if(x<8&&y<8)
        return true;
    return false;
}

void makeset()
{
    int i, j;
    w=r=0;
    for(i=0; i<=9; i++)
        for(j=0; j<=9; j++)
            u[i][j]=0;
}

int main()
{
    char left[3], right[3];
    int lx, ly, rx, ry, i;
    while(~scanf("%s%s", left, right))
    {
        makeset();
        lx=left[0]-'a';
        ly=left[1]-'0'-1;
        rx=right[0]-'a';
        ry=right[1]-'0'-1;
        queue[w][0]=lx;
        queue[w++][1]=ly;
        u[lx][ly]=1;
        while(r<w)
        {
            xx=queue[r][0];
            yy=queue[r][1];
            if(xx==rx&&yy==ry)
            {
                break;
            }
            for(i=0; i<8; i++)
            {
                if(judge(xx+dx[i], yy+dy[i])&&!u[xx+dx[i]][yy+dy[i]])
                {
                    u[xx+dx[i]][yy+dy[i]]=u[xx][yy]+1;
                    queue[w][0]=xx+dx[i];
                    queue[w++][1]=yy+dy[i];
                }
            }
            r++;
        }
        printf("To get from %s to %s takes %d knight moves.\n", left, right, u[xx][yy]-1);
    }
    return 0;
}

