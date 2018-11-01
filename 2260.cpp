#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,maxx=0,minn=0;
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		maxx=max(maxx,max(n+1-x,x));
		minn=max(minn,min(n+1-x,x));
	}
	printf("%d %d\n",minn,maxx);
	return 0;
}
