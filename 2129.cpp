#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int boa[55]={0},req[1025]={0},n,m,tot=0,sum[1025]={0},wat=0,fl=0;
void DFS(int res,int num,int dep)
{
	if(res==0) {fl=1;return;}
	if(wat+sum[dep]>tot) return;
	for(int i=num;i>=1;i--)
	{
		if(boa[i]<req[res]) continue;
		boa[i]-=req[res];
		if(boa[i]<req[1]) wat+=boa[i];
		if(req[res-1]==req[res]) DFS(res-1,i,dep);
		else DFS(res-1,n,dep);
		if(boa[i]<req[1]) wat-=boa[i];
		boa[i]+=req[res];
		if(fl) return;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>boa[i],tot+=boa[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>req[i];
	sort(boa+1,boa+n+1);
	sort(req+1,req+m+1);
	int l=0,r=m,mid;
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+req[i];
	while(l<=r)
	{
		wat=0;
		fl=0;
		mid=(l+r)/2;
		DFS(mid,n,mid);
		if(fl) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}