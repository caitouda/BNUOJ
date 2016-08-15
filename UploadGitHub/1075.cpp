#include<cstdio>
#include<deque>
#include<iostream>

using namespace std;

int main()
{
    int cnt=1;
    int q, num;
    char c, d;
    scanf("%d", &q);
    deque<int> deq;
    while(q--)
    {
        cin>>c;
        if(c=='A')
        {
            cin>>d;
            if(d=='L')
                deq.push_front(cnt++);
            else
                deq.push_back(cnt++);
        }
        else
        {
            cin>>d>>num;
            if(d=='L')
            {
                for(int i=1; i<=num; i++)
                    deq.pop_front();
            }
            else
            {
                for(int i=1; i<=num; i++)
                    deq.pop_back();
            }
        }
    }
    for(int i=0; i<deq.size(); i++)
        printf("%d\n", deq[i]);
    return 0;
}
