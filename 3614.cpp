#include<iostream>
using namespace std;
int main(){
	int a,b,ans=1;
	while(cin>>a>>b)
	{
		if(a==b&&a==0)break;
		ans=1;
		for(int i=1;i<=b;i++)ans*=a,ans%=1000;
		cout<<ans%1000<<endl;
	}
	return 0;
}
