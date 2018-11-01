#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct node{double x,y;}ptr[600005],tmp[600006];
int n;
inline bool cmpx(node a,node b)
{return a.x<b.x;}
inline bool cmpy(node a,node b)
{return a.y<b.y;}
inline double afanbs(double x)
{return x>0?x:-x;}
double Find(int l,int r)
{
	if(l==r) return 0x3f3f3f3f;
	if(l+1==r) return ((ptr[l].x-ptr[r].x)*(ptr[l].x-ptr[r].x)+(ptr[l].y-ptr[r].y)*(ptr[l].y-ptr[r].y));
	int mid=(l+r)/2;
	double vmid=(ptr[mid].x+ptr[mid+1].x)/2,vl=Find(l,mid),vr=Find(mid+1,r),minn;
	minn=min(vl,vr);
	int tot=0;
	for(int i=l;i<=r;i++)
		if(afanbs(ptr[i].x-vmid)<minn) tmp[++tot]=ptr[i];
	if(tot>1) sort(ptr+1,ptr+tot+1,cmpy);
	for(int i=1;i<tot;i++)
		for(int j=i+1;j<=i+8;j++)
		{
			if(j>tot) break;
			minn=min(minn,(double)(tmp[i].x-tmp[j].x)*(tmp[i].x-tmp[j].x)+(tmp[i].y-tmp[j].y)*(tmp[i].y-tmp[j].y));
		}
	return minn;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ptr[i].x>>ptr[i].y;
	sort(ptr+1,ptr+n+1,cmpx);
	cout<<fixed<<setprecision(2)<<sqrt(Find(1,n));
	return 0;
}