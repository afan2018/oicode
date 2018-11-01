#include<iostream>
#include<cstring>
using namespace std;
const int dirx[]={0,0,-1,1},diry[]={1,-1,0,0};
struct node{int l,r;}seg[2000005];
int n,m,map[505][505]={0},vis[505][505]={0};
void DFS(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dirx[i];
        int ny=y+diry[i];
        if(nx>n||nx<1||ny>m||ny<1||vis[nx][ny]||map[x][y]<=map[nx][ny])
            continue;
        vis[nx][ny]=1;
        DFS(nx,ny);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>map[i][j];
    for(int i=1;i<=m;i++)
        if(!vis[1][i])
            DFS(1,i);
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(!vis[n][i])
            cnt++;
    if(cnt) {cout<<"0\n"<<cnt<<'\n';return 0;}
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        DFS(1,i);
        for(int j=1;j<=m;j++)
        {
            if(vis[n][j])
            {
                seg[++sum].l=j;
                seg[sum].r=j;
                while(vis[n][seg[sum].r+1])
                    seg[sum].r++;
                break;
            }
        }
    }
    int ans=0,r=0,tail=0,i=0;
    while(i<sum)
    {
        if(seg[i].r==m) break;
        ans++;
        r=tail;
        while(seg[i+1].l<=tail+1&&i<sum)
        {
            r=max(r,seg[i+1].r);
            i++;
        }
        tail=r;
    }
    cout<<"1\n"<<ans<<'\n';
    return 0;
}
