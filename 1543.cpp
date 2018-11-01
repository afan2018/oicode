#include<iostream>
using namespace std;
int main(){
	int x,n,count=0,d[10005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		d[x]+=1;
	}
	int flag=1;
	for(int i=10000;i>=1;i--)
	{
		if(d[i]!=0)count++;
		if(d[i]!=0&&flag==2)cout<<d[i]<<' ',flag=3;
		if(d[i]!=0&&flag==1)cout<<d[i]<<' ',flag=2;
	}
	cout<<count;
	return 0;
}
