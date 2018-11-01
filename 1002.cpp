#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int t[505]={0},tap[505]={0},n,sum=0,tn;
int main()
{
	cin>>n>>tn;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	sort(t+1,t+n+1);
	int ptr=0;
	for(int i=1;i<=n;i++)
	{
		ptr++;
		if(ptr>tn) ptr=1;
		tap[ptr]+=t[i];
		sum+=tap[ptr];
	}
	cout<<sum;
	return 0;
}
