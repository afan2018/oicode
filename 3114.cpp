#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int fr,to,val;}edge[205];
int f[5][1005]={0},n,t,s,e;
int main()
{
	scanf("%d%d%d%d",&n,&t,&s,&e);
	for(int i=1;i<=t;i++) scanf("%d%d%d",&edge[i].val,&edge[i].fr,&edge[i].to);
	memset(f[0],0x7f,sizeof(f[0]));
	f[0][s]=0;
	for(int i=1;i<=n;i++)
	{
		memset(f[i&1],0x7f,sizeof(f[i&1]));
		for(int j=1;j<=t;j++)
		{
			f[i&1][edge[j].to]=min(f[i&1][edge[j].to],f[(i-1)&1][edge[j].fr]+edge[j].val);
			f[i&1][edge[j].fr]=min(f[i&1][edge[j].fr],f[(i-1)&1][edge[j].to]+edge[j].val);
		}
	}
	printf("%d",f[n&1][e]);
	return 0;
}
