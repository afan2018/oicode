#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int prpr,tar,ten=0,ans[20]={0},num=1,m=0;
	string pre;
	cin>>prpr>>pre>>tar;
	int len=pre.length();
	for(int i=len-1;i>=0;i--)
	{
		if((pre[i]>='0')&&(pre[i]<='9')){
			ten+=(pre[i]-'0')*num;
			num*=prpr;
		}
		else{
			ten+=(pre[i]-'A'+10)*num;
			num*=prpr;
		}
	}
	while(ten!=0){
		m++;
		ans[m]=ten%tar;
		ten/=tar;
	}
	for(int i=1;i<=m/2;i++) swap(ans[i],ans[m-i+1]);
	for(int i=1;i<=m;i++){
		if(ans[i]>9)cout<<char(ans[i]-10+'A');
		else cout<<ans[i];
	}
	//cout<<m;
	return 0;
}
/*
16
FF
10
*/