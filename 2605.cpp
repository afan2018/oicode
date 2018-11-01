#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int cost[205][205]={0},f[2][205][205]={0},n,l,q[1005]={0};
inline int getint()
{	
	int bj=1;
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')bj=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*bj;
}
int main()
{
	l=getint();
	n=getint();
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			cost[i][j]=getint();
	for(int i=1;i<=n;i++)
		q[i]=getint();
	memset(f,127,sizeof(f));
	q[0]=1;
	f[0][2][3]=f[0][3][2]=0;
	for(int i=1;i<=n;i++)
	{
		memset(f[i%2],127,sizeof(f[i%2]));
		for(int j=1;j<=l;j++)
			for(int k=1;k<=l;k++)
				if(j!=k&&j!=q[i-1]&&k!=q[i-1])
				{
					f[i%2][j][k]=min(f[i%2][j][k],f[(i+1)%2][j][k]+cost[q[i-1]][q[i]]);
					f[i%2][j][q[i-1]]=min(f[i%2][j][q[i-1]],f[(i+1)%2][j][k]+cost[k][q[i]]);
					f[i%2][k][q[i-1]]=min(f[i%2][k][q[i-1]],f[(i+1)%2][j][k]+cost[j][q[i]]);
				}
	}
	int maxx=0x7f7f7f7f;
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			maxx=min(maxx,f[n%2][i][j]);
	printf("%d",maxx);
	return 0;
}