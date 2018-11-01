#include<iostream>
using namespace std;
long long n,a[100005]={0},temp[100005]={0},tot=0;
void prpr(int op,int ed)
{
	if(op==ed)return;
	int mid=(op+ed)/2;
	prpr(op,mid);
	prpr(mid+1,ed);
	int i=op,p=op,j=mid+1;
	while(i<=mid&&j<=ed)
	{
		if(a[i]>a[j])
		{
			tot+=mid-i+1;
			temp[p++]=a[j++];
		}
		else temp[p++]=a[i++];
	}
	while(i<=mid)temp[p++]=a[i++];
	while(j<=ed)temp[p++]=a[j++];
	for(int m=op;m<=ed;m++)a[m]=temp[m];
}
int main()
{
	cin>>n;
	for(int q=1;q<=n;q++)cin>>a[q];
	prpr(1,n);
	cout<<tot;
	return 0;
}