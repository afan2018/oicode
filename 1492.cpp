#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int h[1000005]={0},n;
int main(){
	cin>>n;
	for(int i=1,x;i<=n-2;i++)
		cin>>x,h[x]=1;
	for(int i=1;i<=n;i++)
		if(!h[i]) cout<<i<<' ';
	return 0;
}
