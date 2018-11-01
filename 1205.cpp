#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int prpr,pree[55]={0};
	long long max=0,ans1,ans2=0,ans3=0;
	string pre;
	cin>>pre;
	int len=pre.length();
	for(int i=1;i<=len;i++)pree[i]=pre[i-1]-'A';
	max=pree[1];
	for(int i=2;i<=len;i++)if(pree[i]>max)max=pree[i];
	prpr=max+1;
	ans1=pree[1];
	for(int i=1;i<len;i++){
		ans3=ans3*prpr;
		ans2=ans2*prpr;
		ans1=ans1*prpr+pree[i+1];
		if(ans1>10000000000000) {ans2+=ans1/10000000000000;ans1=ans1%10000000000000;}
		if(ans2>10000000000000) {ans3+=ans2/10000000000000;ans2=ans2%10000000000000;}
	}
	if(ans3>0) {
		cout<<ans3<<ans2<<ans1;
		return 0;
	}
	if(ans2>0) cout<<ans2<<ans1;
	else cout<<ans1;
	return 0;
}