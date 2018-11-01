#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,k,l,r,mid,len,cnt=0,ccnt=0;
string str,che;
bool C(int wid)
{
	ccnt=0;
	for(int i=1;i<=n;)
	{
		while(str[i]=='0') i++;
		if(i>n) break;
		ccnt++;
		i+=wid;
	}	
	return (ccnt<=k);
}
int main()
{
	cin>>n>>k>>str;
	str=" "+str;
	l=0,r=n;
	int ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(C(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}