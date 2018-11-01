#include<iostream>
#include<cstring>
using namespace std;
struct node{int next,to;}edge[20005];
int flag=0,n,m,a,b,cnt,h[20005]={0},used[20005]={0},rd[20005]={0},ans[20005]={0};
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
void print()
{for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;}
void topsort(int dep)
{
	if(flag==1) return;
	if(dep>n){print();flag=1;return;}
	for(int i=1;i<=n;i++)
		if(used[i]>0&&!rd[i])
		{
			ans[dep]=i;
			used[i]--;
			for(int j=h[i];j;j=edge[j].next)rd[edge[j].to]--;
			topsort(dep+1);
			for(int j=h[i];j;j=edge[j].next)rd[edge[j].to]++;
			used[i]++;
			ans[dep]=0;
		}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a>>b,AddEdge(a,b),rd[b]++;
	for(int i=1;i<=n;i++) used[i]=1;
	topsort(1);
	if(!flag)cout<<"no solution";
	return 0;
}
