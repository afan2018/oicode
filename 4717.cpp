#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
int n,m,k,h[10005]={0},lev[10005]={0},dis[10005][25]={0},cnt=0;
bool vis[10005][25]={0};
struct node{int nx,to,val;}edge[2000005];
struct nodee{int lev,num;}temp;
vector<nodee>vec;
void Add(int a,int b,int c)
{edge[++cnt].to=b,edge[cnt].nx=h[a],h[a]=cnt,edge[cnt].val=c;}
void SPFA()
{
	memset(dis,0x7f,sizeof(dis));
	dis[1][lev[1]]=0;
	vec.clear();
	int head=0,tail=1;
	temp.lev=0,temp.num=0;
	vec.push_back(temp);
	temp.lev=lev[1],temp.num=1;
	vec.push_back(temp);
	while(head!=tail)
	{
		nodee get=vec[++head];
		vis[get.num][get.lev]=0;
		for(int i=h[get.num];i;i=edge[i].nx)
		{
			int to=edge[i].to;
			if(lev[to]>get.lev+1) continue;
			int nowl=max(lev[to],get.lev);
			if(dis[to][nowl]>dis[get.num][get.lev]+edge[i].val)
			{
				dis[to][nowl]=dis[get.num][get.lev]+edge[i].val;
				if(!vis[to][nowl])
				{
					vis[to][nowl]=1;
					tail++;
					temp.lev=nowl;
					temp.num=to;
					vec.push_back(temp);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,a;i<=k;i++)
	{
		while(1)
		{
			scanf("%d",&a);
			if(a==0) break;
			lev[a]=i;
		}
	}
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		Add(a,b,c);
		Add(b,a,c);
	}
	SPFA();
	int minn,maxx,tmp;
	for(int i=1;i<=k;i++)
	{
		minn=0x7f7f7f7f/2,maxx=0;
		for(int j=1;j<=n;j++)
		{
			if(lev[j]==i)
			{
				tmp=0x7f7f7f7f/2;
				for(int hh=i;hh<=k;hh++) tmp=min(tmp,dis[j][hh]);
				minn=min(tmp,minn);
				maxx=max(tmp,maxx);
			}			
		}
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}