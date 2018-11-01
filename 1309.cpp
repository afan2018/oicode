#include<iostream>
using namespace std;
struct ndoe{int next,to;}edge[205];
int cnt,h[205]={0},n,a,b,ans[205]={0},rd[205]={0};
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
bool TopSort()
{
	int now,too,tot=0;
	for(int i=1;i<=n;i++)
		if(!rd[i])ans[++ans[0]]=i;
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
	cin>>n;
	while(cin>>a>>b)AddEdge(a,b),rd[b]++;
	if(TopSort())for(int i=1;i<=ans[0];i++)cout<<ans[i]<<' ';
	else cout<<"No answer";
	return 0;
}