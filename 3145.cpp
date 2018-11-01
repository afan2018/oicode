#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int f[200005][20]={0},n,val[200005],cn,minn,ans=0,ha[55]={0},hot[200005]={0},col[55][200005]={0};
void ST()
{
	for(int i=1;i<=(int)log2(n);i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			f[j][i]=f[j][i-1];
			if(val[f[j][i-1]]>val[f[j+(1<<(i-1))][i-1]]) f[j][i]=f[j+(1<<(i-1))][i-1];
		}
}
int RMQ(int l,int r)
{
	int idx=log2(r-l+1);
	return min(val[f[l][idx]],val[f[r-(1<<idx)+1][idx]]);
}
int main()
{
	scanf("%d%d%d",&n,&cn,&minn);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&hot[i],&val[i]);
		f[i][0]=i;
		col[hot[i]][++col[hot[i]][0]]=i;
	}
	ST();
	for(int i=0;i<cn;i++)
		for(int j=1;j<col[i][0];j++)
			for(int k=j+1;k<=col[i][0];k++)
				if(RMQ(col[i][j],col[i][k])<=minn) {ans+=col[i][0]-k+1;break;}
	printf("%d",ans);
	return 0;
}