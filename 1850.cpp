#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int INF=1e8;
int n,maxx=0,maxy=0,minx=INF,miny=INF,tst=0,sump=0,sum=0;
struct node{double x,y;}sit[205],flat[205],tmp[205];
inline node operator -(const node &a,const node &b)
{
	node c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	return c;
}
inline double operator *(const node &a,const node &b)
{return a.x*b.y-a.y*b.x;}
double cross(node a,node b,node c)
{return (a-c)*(b-c);}
node getp(node &a1,node &a2,node &b1,node &b2)
{
	double s1=fabs(cross(b1,a2,a1)),s2=fabs(cross(b2,a2,a1));
	node ret;
	ret.x=(s1*b2.x+s2*b1.x)/(s1+s2);
	ret.y=(s1*b2.y+s2*b1.y)/(s1+s2);
	return ret;
}
void Cut(node a,node b)
{
	int tot=0;
	node temp[10005];
	flat[sum+1]=flat[1];
	for(int i=2;i<=sum+1;i++)
	{
		double l=cross(flat[i-1],b,a),r=cross(flat[i],b,a);
		if(l>=0)
		{
			tmp[++tot]=flat[i-1];
			if(r<0)tmp[++tot]=getp(a,b,flat[i-1],flat[i]);
		}
		else if(r>0)tmp[++tot]=getp(a,b,flat[i-1],flat[i]);
	}
	for(int i=1;i<=tot;i++) flat[i]=tmp[i];
	sum=tot;
}
void Init()
{
	memset(flat,0,sizeof(flat));
	memset(tmp,0,sizeof(tmp));
	maxx=maxy=sump=sum=0;
	double maxx=-INF,maxy=-INF,minx=INF,miny=INF;
	minx=miny=INF;
	for(int i=1;i<=n;i++)
	{
		cin>>sit[i].x>>sit[i].y;
		if(sit[i].x>maxx)maxx=sit[i].x;
		if(sit[i].x<minx)minx=sit[i].x;
		if(sit[i].y>maxy)maxy=sit[i].y;
		if(sit[i].y<miny)miny=sit[i].y;
	}
	flat[1]=node{minx,miny};
	flat[2]=node{minx,maxy};
	flat[3]=node{maxx,maxy};
	flat[4]=node{maxx,miny};
	sum=4;
}
int main(){
	while(cin>>n)
	{
		if(!n)break;
		tst++;
		Init();
		cout<<"Floor #"<<tst<<"\nSurveillance is ";
		for(int i=1;i<n;i++)
			Cut(sit[i],sit[i+1]);
		Cut(sit[n],sit[1]);
		if(!sum) cout<<"impossible.";
		else cout<<"possible.";
		cout<<endl<<endl;
	}
	return 0;
}
