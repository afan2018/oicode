#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int num[100005]={0},sum=0,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	{
		if(num[i]<=sum+1) sum+=num[i];
		else {cout<<sum+1;return 0;}
	}
	cout<<sum+1;
	return 0;
}