#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct node{int x,y;}sit[105];
int maxtop=0,stack[105]={0},used[105]={0},top=0,n,cnt=0;
double ans1=0,ans2=0;
inline node operator -(const node &a,const node &b)
{
	node c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	return c;
}
inline int operator *(const node &a,const node &b)
{return a.x*b.y-a.y*b.x;}
bool Direction(node x,node y,node ori)
{return (x-ori)*(y-ori)>=0;}
void Init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sit[i].x>>sit[i].y;
}
void ConvexHull()
{
	for(int i=1;i<n;i++)
		for(int j=1;j<=n-i;j++)
		{
			if(sit[j].y>sit[j+1].y||(sit[j].y==sit[j+1].y&&sit[j].x>sit[j+1].x))
			swap(sit[j],sit[j+1]);
		}
	stack[0]=0;
	stack[++top]=1;
	cnt=2;
	while(cnt<=n)
	{
		while(top>1&&Direction(sit[stack[top]],sit[cnt],sit[stack[top-1]]))
			used[stack[top--]]=0;
		stack[++top]=cnt;
		used[cnt++]=1;
	}
	maxtop=top;
	cnt=n-1;
	while(cnt>=1)
	{
		while(used[cnt]) cnt--;
		while(top>maxtop&&Direction(sit[stack[top]],sit[cnt],sit[stack[top-1]]))
			used[stack[top--]]=0;
		stack[++top]=cnt;
		used[cnt--]=1;
	}
}
void Cal()
{
	for(int i=1;i<top;i++)
	{
		node sit1=sit[stack[i]],sit2=sit[stack[i+1]];
		ans1+=sqrt((sit2.x-sit1.x)*(sit2.x-sit1.x)+(sit2.y-sit1.y)*(sit2.y-sit1.y));
		ans2+=(sit2.x-sit1.x)*(sit1.y+sit2.y);
	}
	ans2/=2;
	if(!ans2)ans1/=2;
	cout<<fixed<<setprecision(2)<<ans1<<'\n'<<ans2;
}
int main(){
	Init();
	ConvexHull();
	Cal();
	return 0;
}
/*
4
0 0
1 0
0 1
1 1
*/
