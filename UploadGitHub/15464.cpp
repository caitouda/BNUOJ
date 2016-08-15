#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char ch;
    struct Node *left;
    struct Node *right;
}Node;

char mid[27];
char pre[27];
int n=-1;

void make_tree(int i, int j);

int main()
{
    int i, j, k;
    while(scanf("%s%s", pre, mid)==2)
    {
        make_tree(0, strlen(pre)-1);
        printf("\n");
        n=-1;
    }
    return 0;
}

void make_tree(int i, int j)
{
    int k;
    if(i>j)
        return;
    n++;
    for(k=i; k<=j; k++)
    {
        if(pre[n]==mid[k])
        {
            break;
        }
    }
    make_tree(i, k-1);
    make_tree(k+1, j);
    printf("%c", mid[k]);
}

