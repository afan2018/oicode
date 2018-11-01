#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int num,g;}sto[100005];
int f[100005]={0},n;
bool cmp(node a,node b)
{
	if(a.num==b.num) return a.g>b.g;
	return a.num<b.num;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sto[i].num;
	for(int i=1;i<=n;i++)
		sto[i].g=i-sto[i].num;
	sort(sto+1,sto+n+1,cmp);
	int head,tail,mid,len;
	f[0]=0;
	len=0;
	for(int i=1;i<=n;i++)
	{
		if(sto[i].g>=f[len]){f[++len]=sto[i].g;continue;}
		head=1,tail=len;
		while(head<tail)
		{
			mid=(head+tail)/2;
			if(sto[i].g>=f[mid]) head=mid+1;
			else tail=mid;
			
		}
		f[head]=sto[i].g;
	}
	cout<<len;
	return 0;
}