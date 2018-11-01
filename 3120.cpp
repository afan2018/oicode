#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int L,T,ans[70005]={0},n;
int main()
{
	scanf("%d%d%d",&L,&T,&n);
	for(int i=1,x;i<=n;i++)
	{
		char ch;
		cin>>x>>ch;
		if(ch=='D')
		{
			int foo=x+T;
			if(foo<=L) {ans[i]=foo;}
			else if(((foo)/L)%2==1) {ans[i]=((foo)/L+1)*L-(foo);}
			else ans[i]=((foo)-((foo)/L)*L);
		}
		else
		{
			if(x-T>=0) {ans[i]=x-T;}
			else
			{
				int foo=abs(x-T);
				if(foo<=L) {ans[i]=foo;}
				else if(((foo)/L)%2==1) {ans[i]=((foo)/L+1)*L-(foo);}
				else ans[i]=((foo)-((foo)/L)*L);
			}
		}
	}
	sort(ans+1,ans+n+1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
7 22
3
5 D
3 L
1 L
*/