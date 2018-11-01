#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int,vector<int>,greater<int> >big;
priority_queue<int,vector<int>,less<int> >small;
int n,sb=0,ss=0;
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(big.empty()||x>=big.top()) big.push(x),sb++;
		else small.push(x),ss++;
		if(i&1)
		{
			while(ss+1<sb)
			{
				small.push(big.top());
				big.pop();
				sb--;ss++;
			}
			while(ss+1>sb)
			{
				big.push(small.top());
				small.pop();
				sb++;ss--;
			}
			printf("%d\n",big.top());
		}
	}
	return 0;
}