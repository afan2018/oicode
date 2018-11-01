#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int a[1000005]={0};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1,x;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]!=a[i-1]) cnt=0;
		cnt++;
		if(cnt>m/2) {cout<<a[i];return 0;}
	}
	cout<<-1;
	return 0;
}
