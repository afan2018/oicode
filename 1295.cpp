#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int biao[1000000]={0};
int ptr=1,n,ans,flag=1;;
int main(){
	cin>>n;
	n*=2;
	while(1)
	{
		if(ptr==1&&flag==0) break;
		if(ptr<=n/2) ptr*=2,ans++;
		else if(ptr>n/2) ptr=(ptr-n/2)*2-1,ans++;
		flag=0;
	}
	cout<<ans;
	return 0;
}
