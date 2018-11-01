#include<iostream>
#include<cmath>
using namespace std;
const int INF=1<<30;
int f[2][65][25][25][25][25]={0},n;
int DFS(int sta,int step,int a,int b,int c,int d)
{
	if(step>3*n) return INF;
	if(a==c&&b==d)
	{
		if(sta==1) return INF;
		return 0;
	}
	if(f[sta][step][a][b][c][d]) return f[sta][step][a][b][c][d];
	int ans=0;
	if(sta)
	{
		ans=1<<30;
		if(c>1) ans=min(ans,DFS(0,step+1,a,b,c-1,d));
		if(d>1) ans=min(ans,DFS(0,step+1,a,b,c,d-1));
		if(c<n) ans=min(ans,DFS(0,step+1,a,b,c+1,d));
		if(d<n) ans=min(ans,DFS(0,step+1,a,b,c,d+1));
		if(c>2) ans=min(ans,DFS(0,step+1,a,b,c-2,d));
		if(d>2) ans=min(ans,DFS(0,step+1,a,b,c,d-2));
		if(c<n-1) ans=min(ans,DFS(0,step+1,a,b,c+2,d));
		if(d<n-1) ans=min(ans,DFS(0,step+1,a,b,c,d+2));
	}
	else 
	{
		if(a>1) ans=max(ans,DFS(1,step+1,a-1,b,c,d));
		if(b>1) ans=max(ans,DFS(1,step+1,a,b-1,c,d));
		if(a<n) ans=max(ans,DFS(1,step+1,a+1,b,c,d));
		if(b<n) ans=max(ans,DFS(1,step+1,a,b+1,c,d));
	}
	return f[sta][step][a][b][c][d]=++ans;
}
int main()
{
	int a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	if(abs(a-c)+abs(b-d)<=1) cout<<"WHITE 1\n";
	else cout<<"BLACK "<<DFS(0,0,a,b,c,d);
	return 0;
} 
