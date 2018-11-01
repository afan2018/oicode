#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	double x,y;
	node(){x=y=0;};
}sit[30005];
int maxtop=0,stack[30005]={0},used[30005]={0},top=0,n,cnt=0;
double ans=0;
inline node operator -(const node &a,const node &b)
{
	node c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	return c;
}
inline long long operator *(const node &a,const node &b)
{return a.x*b.y-a.y*b.x;}
bool cmp(node a,node b)
{return (a.y<b.y||a.y==b.y&&a.x<b.x);}
bool Direction(node x,node y,node ori)
{return (x-ori)*(y-ori)>=0;}
void Init()
{
	memset(stack,0,sizeof(stack));
	memset(used,0,sizeof(used));
	maxtop=top=cnt=ans=0;
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
double dist(node a,node b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
double Calipers()
{
	double anss=0;
	int r=1;
	stack[0]=stack[top];
   	for(int l=0;l<top;l++)
    {
		while((sit[stack[l]]-sit[stack[l+1]])*(sit[stack[r+1]]-sit[stack[l+1]])>(sit[stack[l]]-sit[stack[l+1]])*(sit[stack[r]]-sit[stack[l+1]]))
			r=(r+1)%top;
  		anss=max(anss,max(dist(sit[stack[l]],sit[stack[r]]),dist(sit[stack[l+1]],sit[stack[r+1]]))); 
	}
	return anss;
}
int main(){
	while(cin>>n)
	{
		Init();
		ConvexHull();
		ans=Calipers();
		cout<<fixed<<setprecision(2)<<sqrt(ans);
	}
	return 0;
}
/*
4
0 0
1 1
0 1
1 0
*/
