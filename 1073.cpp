#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105]={0},ave=0,n,ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		ave+=a[i];
	}
	ave/=n;
	for(int i=1;i<=n;i++) a[i]-=ave;
	for(int i=1;i<n;i++)
		if(a[i])
		{
			a[i+1]+=a[i];
			ans++;
		}
	printf("%d",ans);
	return 0;
}
