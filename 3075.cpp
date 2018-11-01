#include<iostream>
#include<algorithm>
using namespace std;
int tree[200005]={0},val[200005]={0},ans[200005]={0},h[200005]={0},cnt,n,m;
struct node{int nx,to;}edge[200005];
void Addedge(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
void Init() 
{
	cin>>n>>m;
	int num;
	for(int i=1;i<=n;i++)
		cin>>num>>val[i],Addedge(num,i);
}
void DFS(int rt)
{
	int son=-1;
	if(!h[rt]){tree[rt]=val[rt];return;}
	for(int i=h[rt];i;i=edge[i].nx)
	{
		int to=edge[i].to;
		DFS(to);
		if(son==-1){son=to;continue;}
		if(tree[son]<tree[to]){ans[++ans[0]]=tree[son],son=to;}
			else ans[++ans[0]]=tree[to];
	}
	tree[rt]=tree[son]+val[rt];
}
void Solve()
{
	ans[++ans[0]]=tree[0];
	sort(ans+1,ans+ans[0]+1);
	long long hh=0;
	for(int i=1;i<=m;i++)
		hh+=ans[ans[0]-i+1];
	cout<<hh<<endl;
}
int main(){
	Init();
	DFS(0);
	Solve();
	return 0;
}
