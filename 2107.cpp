#include<iostream>
#include<algorithm>
using namespace std;
struct node{int fr,to,val;}edge[2005]={0};
int sum=0,n,fa[1005]={0},cnt=0,ans=0,map[105][105]={0};
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int Get(int x)
{return fa[x]==x?x:fa[x]=Get(fa[x]);}
void K()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=sum;i++)
	{
		int fa1=Get(edge[i].fr);
		int fa2=Get(edge[i].to);
		if(fa1!=fa2)
		{
			fa[fa1]=fa2;
			cnt++;
			ans+=edge[i].val;
			if(cnt==n-1) break;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			edge[++sum].fr=i;
			edge[sum].to=j;
			edge[sum].val=map[i][j];
		}
	sort(edge+1,edge+sum+1,cmp);
	K();
	printf("%d\n",ans);
	return 0;
}
