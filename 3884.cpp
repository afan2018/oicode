#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f;
ll cnt=0,n,m,k,hspe[100005]={0},spe[6]={0},h[1000005]={0},anss=INF,hhh[100005]={0},dist[60][100005]={0},que[100005]={0},vis[100005]={0};
struct node {ll to,nx,val;}edge[1000005];
void Addedge(ll a,ll b,ll c)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt,edge[cnt].val=c;}
void SPFA(ll *dis,ll sou)
{
	memset(que,0,sizeof(que));
	memset(vis,0,sizeof(vis));
	for(ll i=1;i<=n;i++) dis[i]=INF;
	dis[sou]=0;
	que[1]=sou;
	vis[sou]=1;
	ll head=0,tail=1;
	while(head<tail)
	{
		head++;
		ll x=que[head];
		vis[x]=0;
		for(ll i=h[x];i;i=edge[i].nx)
		{
			ll to=edge[i].to;
			if(dis[x]+edge[i].val<dis[to])
			{
				dis[to]=dis[x]+edge[i].val;
				if(!vis[to])
				{
					vis[to]=1;
					tail++;
					que[tail]=to;
				}
			}
		}
	}
}
void Calc(ll step,ll fr,ll val,ll head)
{
	if(step==k)
	{
		for(ll i=1;i<=n;i++)
			if(!hspe[i])
				anss=min(anss,val+dist[head][i]+dist[fr][i]);
	}
	for(ll i=1;i<=k;i++)
	{
		if(!hhh[i])
		{
			hhh[i]=1;
			if(!step) head=i;
			Calc(step+1,i,val+dist[fr][spe[i]],head);
			hhh[i]=0;
		}
	}
}
int main(){
	cin>>n>>m>>k;
	for(ll i=1;i<=k;i++)
		cin>>spe[i],hspe[spe[i]]=1;
	for(ll i=1,a,b,c;i<=m;i++)
	{
		cin>>a>>b>>c;
		Addedge(a,b,c);
		Addedge(b,a,c);
	}
	for(ll i=1;i<=k;i++)
		SPFA(dist[i],spe[i]);
	Calc(0,0,0,0);
	cout<<anss;
	return 0;
}
