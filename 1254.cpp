#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,map[10][10],tot=0,ans=0xcfcfcfcf,t=0;
bool Check(int x,int y,int i)
{
    switch(i)
    {
        case 1:
            return y+2<=8&&!map[x][y]&&!map[x][y+1]&&!map[x][y+2];
            break;
        case 2:
            return !map[x][y+1]&&!map[x+1][y+1]&&!map[x][y]&&x+1<=n&&y+1<=8;
            break;
        case 3:
            return !map[x+1][y]&&!map[x+2][y]&&!map[x][y]&&x+2<=n;
            break;
        case 4:
            return !map[x+1][y]&&!map[x+1][y+1]&&!map[x][y]&&x+1<=n&&y+1<=8;
            break;
        case 5:
            return !map[x][y+1]&&!map[x+1][y]&&!map[x][y]&&x+1<=n&&y+1<=8;
            break;
        case 6:
            return !map[x+1][y]&&!map[x+1][y-1]&&!map[x][y]&&x+1<=n&&y-1>=1;
            break;
    }
}
void DFS(int x,int y,int dep,int cnt)
{
	if(x==n+1)
	{
		ans=max(ans,dep);
		return;
	}
    if(t>500) {cout<<ans;exit(0);}
	if(cnt/3+dep<=ans) return;
	if(y>=9) {DFS(x+1,1,dep,cnt);return;}
	if(map[x][y]) {DFS(x,y+1,dep,cnt);return;}
    t++;
	for(int i=1;i<=6;i++)
		if(Check(x,y,i))
		{
			map[x][y]=1;
			switch(i)
			{
				case 1:
					map[x][y+1]=1;
					map[x][y+2]=1;
					break;
				case 2:
					map[x][y+1]=1;
					map[x+1][y+1]=1;
					break;
				case 3:
					map[x+1][y]=1;
					map[x+2][y]=1;
					break;
				case 4:
					map[x+1][y]=1;
					map[x+1][y+1]=1;
					break;
				case 5:
					map[x][y+1]=1;
					map[x+1][y]=1;
					break;
				case 6:
					map[x+1][y]=1;
					map[x+1][y-1]=1;
					break;
			}
			DFS(x,y+1,dep+1,cnt-3);
			map[x][y]=0;
			switch(i)
			{
				case 1:
					map[x][y+1]=0;
					map[x][y+2]=0;
					break;
				case 2:
					map[x][y+1]=0;
					map[x+1][y+1]=0;
					break;
				case 3:
					map[x+1][y]=0;
					map[x+2][y]=0;
					break;
				case 4:
					map[x+1][y]=0;
					map[x+1][y+1]=0;
					break;
				case 5:
					map[x][y+1]=0;
					map[x+1][y]=0;
					break;
				case 6:
					map[x+1][y]=0;
					map[x+1][y-1]=0;
					break;
			}
		}
        DFS(x,y+1,dep,tot);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=8;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==0) tot++;
		}
	DFS(1,1,0,tot);
	cout<<ans;
	return 0;
}
