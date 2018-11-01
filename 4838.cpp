#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1050000]={0},n,l,Mov[25][1005]={{0}},T[25]={0},ans=-1;
inline int Getint()
{
	int ret=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=ret*10+(ch-'0');ch=getchar();}
	return ret;
}
inline int Count(int x)
{return x?1+Count(x&(x-1)):0;}
inline int BS(int val,int kind)
{
	int L=1,R=Mov[kind][0],mid,ret=-1;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(Mov[kind][mid]<=val) ret=mid,L=mid+1;
		else R=mid-1;
	}
	return ret;
}
int main()
{
	n=Getint();
	l=Getint();
	for(int i=1;i<=n;i++)
	{
		T[i]=Getint();
		Mov[i][0]=Getint();
		for(int j=1;j<=Mov[i][0];j++) Mov[i][j]=Getint();
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(!~dp[i]) continue;
		if(dp[i]>=l)
		{
			int foo=Count(i);
			ans=(!~ans)?foo:min(foo,ans);
		}
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))) continue;
			int newi=(i|(1<<(j-1)));
			int pos=BS(dp[i],j);
			if(!~pos) continue;
			dp[newi]=max(dp[newi],Mov[j][pos]+T[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
