#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >heap;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        heap.push(x);
    }
    while(n--)
    {
        printf("%d ",heap.top());
        heap.pop();
    }
    return 0;
}
