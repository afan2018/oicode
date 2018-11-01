#include<iostream>
#include<cstring>
using namespace std;
struct node{int next,to;}edge[20005];
int n,m,a,b,cnt,h[20005]={0},rd[20005]={0},ans[20005]={0};
bool hhh[2000][2000]={0};
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
bool TopSort()
{
	int now,too,tot=0;
	for(int i=1;i<=n;i++)
		if(rd[i]==0) ans[++ans[0]]=i;
	while(tot<ans[0])
	{
		now=ans[++tot];
		for(int i=h[now];i;i=edge[i].next)
		{
			too=edge[i].to;
			if(!--rd[too])ans[++ans[0]]=too;
		}
	}
	return tot==n;
} 
int main(){
	while(1)
	{
		memset(hhh,0,sizeof(hhh));
		memset(rd,0,sizeof(rd));
		memset(h,0,sizeof(h));
		memset(ans,0,sizeof(ans));
		cnt=0;
		cin>>n>>m;
		if(n==0&&m==0)break;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			if(a>b)swap(a,b);
			hhh[a][b]=hhh[b][a]=1;
			rd[a]++;
			AddEdge(b,a);
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(!hhh[i][j]&&!hhh[j][i])
					rd[j]++,AddEdge(i,j);	
	if(TopSort()) 
	{
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<endl;	
	}
	else cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
/*
5 4
1 2
1 3
2 3
1 4
0 0
*/