#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int map[1005][1005]={0},n,m,ans=0,L[1005][1005]={0},R[1005][1005]={0},H[1005][1005]={0};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			ch=getchar();
			while(ch!='R'&&ch!='F')ch=getchar();
			map[i][j]=(ch=='F');
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!map[i][j]) L[i][j]=H[i][j]=0;
			else
			{
				L[i][j]=L[i][j-1]+1;
				H[i][j]=H[i-1][j]+1;
			}
		}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			if(!map[i][j]) R[i][j]=0;
			else R[i][j]=R[i][j+1]+1;
		}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i-1][j])
			{
				L[i][j]=min(L[i][j],L[i-1][j]);
				R[i][j]=min(R[i][j],R[i-1][j]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,(L[i][j]+R[i][j]-1)*(H[i][j]));
	printf("%d",ans*3);
	return 0;
}