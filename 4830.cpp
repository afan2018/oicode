#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node{int val,num;}patch[1005];
struct nodee{int to,nx;}edge[200005]={0};
int h[2005]={0},cnt=0,n,e,vis[1005]={0},dp[1005]={0},dis[1005][1005]={0},ans=0;
queue<int>q;
inline void FStar(int x,int y)
{edge[++cnt].to=y,edge[cnt].nx=h[x],h[x]=cnt;}
inline bool cmp(const node &a,const node &b)
{return a.val<b.val;}
void SPFAs()
{
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        q.push(i);
        dis[i][i]=0;
        vis[i]=1;
        while(!q.empty())
        {
            int mid=q.front();
            q.pop();
            for(int j=h[mid];j;j=edge[j].nx)
            {
                int to=edge[j].to;
                if(dis[i][mid]+1<dis[i][to])
                {
                    dis[i][to]=dis[i][mid]+1;
                    if(!vis[to])
                    {
                    	q.push(to);//
                    	vis[to]=1;
					}
                        
                }
            }
            vis[mid]=0;//
        }
    }
}
int main()
{
    cin>>n>>e;
    for(int i=1,x,y;i<=n;i++)
    {
        cin>>x>>y;
        patch[i].val=x;
        patch[i].num=i;
        for(int j=1,z;j<=y;j++)
        {
            cin>>z;
            FStar(i,z);
            FStar(z,i);
        }
    }
    sort(patch+1,patch+n+1,cmp);
    memset(dis,0x7f,sizeof(dis));
    SPFAs();
    for(int i=1;i<=n;i++)
        dp[i]=patch[i].val;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            if(dis[patch[i].num][patch[j].num]!=0x7f7f7f7f)
                dp[i]=max(dp[i],dp[j]+patch[i].val-e*dis[patch[i].num][patch[j].num]);
            ans=max(ans,dp[i]);
        }
    cout<<ans;
    return 0;
}