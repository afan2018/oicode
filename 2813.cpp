#include<iostream>
#include<algorithm>
using namespace std;
struct node{long long x,y;}k[1111111];
bool cmp(node m,node n)
{
	if(m.x>n.x)return true;
	  else return false;
}
int main(){
	k[0].x=0;
	long long n,x1,y1,x2,y2,a,b;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		k[i].x=(a-x1)*(a-x1)+(b-y1)*(b-y1);
		k[i].y=(a-x2)*(a-x2)+(b-y2)*(b-y2);
	}
	sort(k+1,k+n+1,cmp);
	int max=0,min=0x7f7f7f7f,xh=0;
	k[n+1].y=0;
	for(int i=1;i<=n;i++)
	{
		if(k[i-1].y>max)max=k[i-1].y;
		xh=k[i].x+max;
		if(xh<min)min=xh;
	}
	cout<<min;
	return 0;
}
