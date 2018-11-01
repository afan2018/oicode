#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,val[35]={0},v;
bool f[20005]={0};
int main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
	memset(f,false,sizeof(f));
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=v;j>=val[i];j--)
			if(f[j-val[i]]) f[j]=1;
	for(int i=v;i>=0;i--)
		if(f[i]){cout<<v-i;break;}
	return 0;
}