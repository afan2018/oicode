#include<algorithm>
#include<cstdio>
using namespace std;
static struct node{int val,id;}sum[100005];
static int n,ans=0,target[100005]={0},vis[100005]={0};
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
inline int getint()
{
	int bj=1;
	char ch=getchar();
	if(ch=='-')bj=-1;
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
		if(ch=='-')bj=-1;
	}
	int ret=0;
	while(ch>='0'&&ch<='9')
	{
		ret=ret*10+(ch-'0');
		ch=getchar();
	}
	return ret*bj;
}
int main()
{
	n=getint();
	for(int i=1,x;i<=n;i++)
	{
		x=getint();
		sum[i].id=i;
		sum[i].val=sum[i-1].val+x;
	}
	sort(sum+1,sum+n+1,cmp);
	for(int i=1;i<=n;i++)
		target[sum[i].id]=i;
	static int ptr;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans++;
			ptr=i;
			vis[i]=1;
			while(target[ptr]!=i)
			{
				ptr=target[ptr];
				vis[ptr]=1;
			}
		}
	}
	printf("%d",n-ans);
	return 0;
}