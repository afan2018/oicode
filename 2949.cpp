#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,c,seq[200005]={0},cnt=0,tmp[200005]={0},sum[200005]={0};
int BS(int x)
{
	int l=1,r=tmp[0],mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(tmp[mid]==x) return mid;
		if(tmp[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&seq[i]);
	sort(seq+1,seq+n+1);
	tmp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(seq[i]!=seq[i-1]) tmp[++tmp[0]]=seq[i];
		sum[tmp[0]]++;
	}
	for(int i=1;i<=tmp[0];i++)
	{
		int ret=BS(tmp[i]-c);
		if(ret!=-1) cnt+=sum[i]*sum[ret];
	}
	printf("%d",cnt);
	return 0;
}