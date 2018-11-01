#include<iostream>
using namespace std;
int n,m,a,b,h[20005]={0},cnt=0,vis[20005]={0},rd[20005]={0},ans[20005]={0};
int cost[20005]={0},sum=0;
struct node{int next,to;}edge[20005];
void AddEdge(int x,int y)
{edge[++cnt].to=y,edge[cnt].next=h[x],h[x]=cnt;}
bool TopSort()
{
    int now,too,tot=0;
    for(int i=1;i<=n;i++)
        if(!rd[i])ans[++ans[0]]=i,cost[i]=100;
    while(tot<ans[0])
    {
        now=ans[++tot];
        for(int i=h[now];i;i=edge[i].next)
        {
            too=edge[i].to;
            if(!--rd[too])ans[++ans[0]]=too;
            cost[too]=cost[now]+1;
        }
    }
    return tot==n;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a>>b,AddEdge(b,a),rd[a]++;
    if(TopSort())
	{
		for(int i=1;i<=n;i++)
			sum+=cost[i];
		cout<<sum;
	}
    else cout<<"Poor Xed"<<endl;
    return 0;
}