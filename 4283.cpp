#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct jgt{int ne,t;}a[400005]={0};
int n,cnt=0,h[200005]={0},mmin=0x7fffffff/2,bh,ans[200005]={0},sum[200005]={0};
void D(int x,int y)
    {cnt++;a[cnt].t=y;a[cnt].ne=h[x];h[x]=cnt;}
void dfs(int x,int prt)
    {int y,i,tp=0;
     sum[x]=1;
     for(i=h[x];i;i=a[i].ne)
      {y=a[i].t;
       if(y==prt)continue;
       dfs(y,x);
       tp=max(tp,sum[y]);
       sum[x]+=sum[y];
	  }
	  tp=max(tp,n-sum[x]);
	  if(tp==mmin){ans[++ans[0]]=x;}
	  else if(tp<mmin){ans[0]=1;ans[1]=x;mmin=tp;}
	}
int main()
{   int x,y,i;
    cin>>n;
    for(i=1;i<=n-1;i++){scanf("%d%d",&x,&y);x++;y++;D(x,y);D(y,x);}
    dfs(1,0);
    cout<<mmin<<' '<<ans[0]<<endl;
    for(i=1;i<=ans[0];i++)cout<<ans[i]-1<<' ';
	return 0;
}