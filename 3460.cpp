#include<iostream>
#include<cstring>
using namespace std;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct node{int x,y,tms;}q[1000005];
int n,map[1005][1005]={{0},{0}},sx,sy,mx=0,my=0,val[1005][1005]={{0},{0}};
void BFS()
{
	int head=0,tail=1;
	q[1].x=sx,q[1].y=sy,q[1].tms=val[sx][sy]=0;
	while(head!=tail)
	{
		head=(head+1)%1000000;
		for(int i=0;i<=3;i++)
		{
			int hx=q[head].x,hy=q[head].y;
			int tx=hx+dx[i],ty=hy+dy[i];
			if(tx<0||tx>mx+1||ty<0||ty>my+1) continue;
			if(q[head].tms+map[tx][ty]<val[tx][ty])
			{
				tail=(tail+1)%1000000;
				q[tail].x=tx,q[tail].y=ty,q[tail].tms=q[head].tms+map[tx][ty];
				val[tx][ty]=q[tail].tms;
			}
		}
	}
}
int main()
{
	cin>>n>>sx>>sy;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
		mx=max(mx,x);
		my=max(my,y);
	}
	memset(val,0x3f,sizeof(val));
	BFS();
	cout<<val[0][0];
	return 0;
}
