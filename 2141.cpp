#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
const int INF=0x3f3f3f3f;
using namespace std;
int ans[35]={0},map[35][35]={0},path[35][35]={0},up[35]={0},l[35]={0},r[35]={0},down[35]={0},rd[35]={0},n,m,exi[35]={0},cnt=0;
void Make(int x,int i,int j)
{
	if(!exi[x]) exi[x]=1,cnt++;
	r[x]=max(r[x],j);
	l[x]=min(l[x],j);
	up[x]=min(up[x],i);
	down[x]=max(down[x],i);
}
void DFS(int x)
{
	if(x==cnt+1)
	{
		for(int i=1;i<=cnt;i++)
			cout<<char(ans[i]+64);
		cout<<endl;
		return;
	}
	for(int i=1;i<=26;i++)
	{
		if(rd[i]==0&&exi[i])
		{
			ans[x]=i;
			rd[i]=-1;
			for(int j=1;j<=26;j++)
				if(path[i][j])
					rd[j]--;
			DFS(x+1);
			rd[i]=0;
			for(int j=1;j<=26;j++)
				if(path[i][j])
					rd[j]++;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=26;i++)
		l[i]=INF,up[i]=INF,r[i]=-INF,down[i]=-INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='.')map[i][j]=0;
			else
			{
			   map[i][j]=ch-'A'+1;
			   Make(map[i][j],i,j);
		   }
		}
	for(int i=1;i<=26;i++)
	{
		if(exi[i])
		{
			for(int j=up[i];j<=down[i];j++)
			{
				if(map[j][l[i]]!=i&&!path[i][map[j][l[i]]])
				{
					path[i][map[j][l[i]]]=1;
					rd[map[j][l[i]]]++;
				}
				if(map[j][r[i]]!=i&&!path[i][map[j][r[i]]])
				{
					path[i][map[j][r[i]]]=1;
					rd[map[j][r[i]]]++;
				}
			}
			for(int j=l[i];j<=r[i];j++)
			{
				if(map[up[i]][j]!=i&&!path[i][map[up[i]][j]])
				{
					path[i][map[up[i]][j]]=1;
					rd[map[up[i]][j]]++;
				}
				if(map[down[i]][j]!=i&&!path[i][map[down[i]][j]])
				{
					path[i][map[down[i]][j]]=1;
					rd[map[down[i]][j]]++;
				}
			}
		}
	}
	DFS(1);
	return 0;
}