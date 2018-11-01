#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const double Pi=3.141592654;
struct node{double x,y;}sit[1005];
int n,used[1005]={0},stack[1005]={0},top=0,maxt=0,cnt=0;
double cir=0,l;
inline node operator -(const node &a,const node &b)
{
	node c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	return c;
}
inline int operator *(const node &a,const node &b)
{return a.x*b.y-a.y*b.x;}
bool cmp(node a,node b)
{return a.y<b.y||((a.y==b.y)&&(a.x<b.x));}
bool Direction(node a,node b,node ori)
{return (a-ori)*(b-ori)>=0;}
double EuclidDis(node a,node b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void Init()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		cin>>sit[i].x>>sit[i].y;
}
void ConvexHull()
{
	sort(sit+1,sit+n+1,cmp);
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
	maxt=top;
	cnt=n-1;
	while(cnt>=1)
	{
		while(used[cnt]) cnt--;
		while(top>maxt&&Direction(sit[stack[top]],sit[cnt],sit[stack[top-1]]))
			used[stack[top--]]=0;
		stack[++top]=cnt;
		used[cnt--]=1;
	}
}
void Calc()
{
	for(int i=1;i<top;i++)
	{
		node sit1=sit[stack[i]],sit2=sit[stack[i+1]];
		cir+=EuclidDis(sit1,sit2);
	}
	cir+=2*Pi*l;
	cout<<fixed<<setprecision(2)<<cir<<'\n';
}
int main()
{
	Init();
	ConvexHull();
	Calc();
	return 0;
}