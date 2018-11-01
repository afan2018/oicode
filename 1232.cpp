#include<cstdio>
const int Maxn=1001;
struct List{int next,to;}a[20001];
int n,m,cnt,h[Maxn],lowlink[Maxn],dfn[Maxn],sign,prt[Maxn],ans=0,ans1=0,st,ed;
void Addedge(int x,int y)
{a[++cnt].to=y;a[cnt].next=h[x];h[x]=cnt;}
void Dfs(int x)
{dfn[x]=lowlink[x]=++sign;
  for(int i=h[x];i;i=a[i].next)
 {int y=a[i].to;
  if(prt[x]==y)continue;
  if(!dfn[y])
  {prt[y]=x;
   Dfs(y);
   if(lowlink[x]>lowlink[y])lowlink[x]=lowlink[y];
  }
   else if(lowlink[x]>dfn[y])lowlink[x]=dfn[y];
 }
}
int main()
{
scanf("%d%d",&n,&m);
 for(int i=1,x,y;i<=m;i++)
 {scanf("%d%d",&x,&y);
  Addedge(x,y);Addedge(y,x);
 }
 scanf("%d%d",&st,&ed);
 Dfs(ed);
 for(int i=st;prt[i]!=ed;i=prt[i])//割点
  if(lowlink[i]>=dfn[prt[i]])ans1++;
 for(int i=st;i!=ed;i=prt[i])//割边
  {if(lowlink[i]>dfn[prt[i]])ans++; }
 printf("%d\n%d",ans,ans1);
 return 0;
}