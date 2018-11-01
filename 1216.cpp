#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int seq[105]={0},n,dp[105][15][15][15],ans=0;
bool vis[105][15][15][15];
int DFS(int num,int cla,int clb,int clc)
{
	int clear=cla+clb+clc;
	for(int i=1;i<=10-clear;i++)
	{
		num++;
		if(num>n) break;
		switch(seq[num])
		{
			case 1: cla++;break;
			case 2: clb++;break;
			case 3: clc++;break;
		}
	}
	if(num>=n)
	{
		vis[n][cla][clb][clc]=1;
		return dp[n][cla][clb][clc]=(cla>0)+(clb>0)+(clc>0);
	}
	if(!vis[num][cla][clb][clc])
	{
		vis[num][cla][clb][clc]=1;
		dp[num][cla][clb][clc]=INF;
		if(cla) dp[num][cla][clb][clc]=min(dp[num][cla][clb][clc],DFS(num,0,clb,clc)+1);
		if(clb) dp[num][cla][clb][clc]=min(dp[num][cla][clb][clc],DFS(num,cla,0,clc)+1);
		if(clc) dp[num][cla][clb][clc]=min(dp[num][cla][clb][clc],DFS(num,cla,clb,0)+1);
	}
	return dp[num][cla][clb][clc];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		seq[i]=ch-'A'+1;
	}
	cout<<DFS(0,0,0,0)<<'\n';
	return 0;
}
