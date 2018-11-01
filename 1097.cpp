#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct node{int x,y,tms;}q[5000079];
int n,m,x,y,vis[205][205]={{0},{0}},nm,map[205][205]={{0},{0}},dir[2005]={0};
char ch;
string str;
void BFS()
{
	q[1].x=x;q[1].y=y;q[1].tms=0;
	int head=0,tail=1;
	while(head!=tail)
	{
		head=(head+1)%5000007;
		int i=q[head].tms+1,nx,ny;
		//if(dx[i]||dy[i])
		if(i==nm+1) continue;
		{
			for(int j=1;;j++)
			{
				nx=q[head].x+dx[dir[i]]*j;
				ny=q[head].y+dy[dir[i]]*j;
				if(nx<1||ny<1||nx>n||ny>m||!map[nx][ny]) break;
				if(vis[nx][ny]==q[head].tms+1) continue;
				tail=(tail+1)%5000007;
				q[tail].x=nx,q[tail].y=ny,q[tail].tms=q[head].tms+1;
				vis[nx][ny]=q[tail].tms;
			}
		}
		//for(int i=head;i<=tail;i++) cout<<q[i].x<<" "<<q[i].y<<" "<<q[i].tms<<endl;
		//cout<<endl;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch==' '||ch=='\n') {j--;continue;}
			else if(ch=='.') map[i][j]=1;
			else if(ch=='X') map[i][j]=0;
			else if(ch=='*') x=i,y=j,map[i][j]=1;
		}
	cin>>nm;
	for(int i=1;i<=nm;i++)
	{
		cin>>str;
		if(str[0]=='N') dir[i]=0;
		else if(str[0]=='S') dir[i]=1;
		else if(str[0]=='W') dir[i]=2;
		else if(str[0]=='E') dir[i]=3;
	}
	BFS();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==nm) {cout<<'*';continue;}
			if(map[i][j]==0) {cout<<'X';continue;}
			cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}
