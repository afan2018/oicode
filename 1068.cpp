#include <iostream>
using namespace std;
int tree[305][305]={0},map[305][305],n,m,ans=0x7f7f7f7f;
void Make(int rt)
{
    for(int i=1;i<=n;i++)
        if(map[rt][i])
        {
            tree[rt][++tree[rt][0]]=i;
            map[rt][i]=0;
            map[i][rt]=0;
            Make(i);
        }
}
void DFS(int fa,int cnt)
{
    if(cnt+tree[fa][0]-1>=ans) return;
    if(tree[fa][0]<=1) {ans=min(ans,cnt);return;}
    for(int i=1;i<=tree[fa][0];i++)
    {
        int numfa=(i==1)?2:1;//number of new fa
        int nfa=tree[fa][numfa];//new fa
        int sonfa=tree[nfa][0];//son of new fa
        for(int j=1;j<=tree[fa][0];j++)
        {
            if(i!=j&&j!=numfa)
            {
                int nxfa=tree[fa][j];
                for(int k=1;k<=tree[nxfa][0];k++)
                    tree[nfa][++tree[nfa][0]]=tree[nxfa][k];
            }
        }
        DFS(nfa,cnt+tree[fa][0]-1);
        tree[nfa][0]=sonfa;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        map[x][y]=1;
        map[y][x]=1;
    }
    Make(1);
    DFS(1,1);
    cout<<ans;
    return 0;
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
3 7
*/
