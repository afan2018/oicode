#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int map[20][20]={0},n,m,dp[550000][20]={0};
int Getint()
{
	int ret=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=ret*10+ch-'0';ch=getchar();}
	return ret*fl;
}
int main()
{
	n=Getint();
	m=Getint();
	memset(map,0x3f,sizeof(map));
	for(int i=1,x,y,z;i<=m;i++)
	{
		x=Getint();
		y=Getint();
		z=Getint();
		map[x][y]=z;
		map[y][x]=z;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;
	for(int i=1;i<(1<<n);i++)
		for(int fr=1;fr<=n;fr++)
		{
			if(!i&(1<<(fr-1))) continue;
			for(int to=1;to<=n;to++)
			{
				if(i&(1<<(to-1))) continue;
				int foo=i|(1<<(to-1));
				dp[foo][to]=min(dp[foo][to],dp[i][fr]+map[fr][to]);
			}
		}
	int ans=0x3f3f3f3f;
	for(int i=1;i<(1<<n);i++)
	{
		int min1=0x3f3f3f3f;
		int min2=0x3f3f3f3f;
		for(int j=1;j<=n;j++) min1=min(min1,dp[i][j]);
		for(int j=1;j<=n;j++) min2=min(min2,dp[(1<<n)-i][j]);
		ans=min(ans,max(min1,min2));
	}
	printf("%d",ans);
	return 0;
}
