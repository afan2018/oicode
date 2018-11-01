#include<iostream>
using namespace std;
struct node{int next,to;}edge[20005];
int n,m,cnt,h[20005]={0},hmp,ans=0;
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
int main(){
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a>>b,AddEdge(a,b);
	cin>>hmp;
	for(int i=h[hmp];i!=0;i=edge[i].next)ans++;
	cout<<ans;
	return 0;
}