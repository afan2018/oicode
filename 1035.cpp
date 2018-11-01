#include<iostream>
using namespace std;
int q[15]={0},ans=0,vst[15]={0},test,n;
struct node{int x,y;}sit[15];
int Cross(node a,node b,node c)
{return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);}
bool Qcross(node a,node b,node c,node d)
{return (Cross(a,b,c)*Cross(a,b,d)<0&&Cross(c,d,a)*Cross(c,d,b)<=0);}
bool finCheck()
{
	int fl=1;
	for(int i=1;i<=n-2;i++)
		if(Qcross(sit[q[i]],sit[q[i+1]],sit[q[n]],sit[q[1]]))
			{fl=0;break;}
	return fl;
}
bool preCheck(int x,int y)
{
	int fl=1;
	for(int i=1;i<=x-1;i++)
		if(Qcross(sit[q[i]],sit[q[i+1]],sit[q[x]],sit[y]))
			{fl=0;break;}
	return fl;
}
void DFS(int dep)
{
	if(dep==n)
		if(finCheck())
			{ans++;return;}
	for(int i=1;i<=n;i++)
		if(!vst[i])
			if(preCheck(dep,i))
			{
				vst[i]=1;
				q[dep+1]=i;
				DFS(dep+1);
				vst[i]=0;
			}
}
void Solve()
{
	vst[1]=true;
	q[0]=q[1]=1;
	test=1;
	while(cin>>sit[test].x>>sit[test].y)
	{
		if(sit[test].x==sit[test].y&&!sit[test].y)break;
		test++;
	}
	n=test;
	DFS(1);
	cout<<ans/2;
}
int main(){
	Solve();
	return 0;
}
