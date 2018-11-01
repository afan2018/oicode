#include<iostream>
using namespace std;
int main(){
	int n,maxx=0,minn=1<<30,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		if(num>maxx)maxx=num;
		if(num<minn)minn=num;
	}
	cout<<maxx<<' '<<minn;
	return 0;
}
