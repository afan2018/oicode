#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio> 
using namespace std;
int sum[5000005]={0},n,arr[5000005]={0},ave_delta={0},m,cnt0=0;
char seq[5000005]={0};
void Villa()
{
	memset(arr,0,sizeof(arr));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
	    sum[i]=sum[i-1];
		if(seq[i]=='1') sum[i]++;
		else sum[i]--;
		cnt0+=(sum[i]==0);
	}
	if(sum[n]==0&&cnt0>=m) ave_delta=0;
	  else ave_delta=(abs(sum[n])-1)/m+1;
	  
//	  cout<<ave_delta<<endl;
	int cnt=0,peo=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=m-1) {arr[m]=n-i+1;return;}
		if(abs(sum[n]-sum[i])<=ave_delta*(m-cnt-1))
		{
			arr[++cnt]=i-peo;
			peo=i;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("hh.in","r",stdin);
	freopen("hh.out","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>seq[i];
	Villa();
	for(int i=1;i<=m;i++)
		cout<<arr[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n/2;i++)
		swap(seq[i],seq[n-i+1]);
	cnt0=0;
	Villa();
	for(int i=1;i<=m;i++)
		cout<<arr[m-i+1]<<' ';
	return 0;
}