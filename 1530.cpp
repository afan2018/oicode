#include<iostream>
using namespace std;
int main(){
	int a,i,c;
	cin>>a;
	for(i=1;i<=a;i++)
	{
		for(c=1;c<=i-1;c++) cout<<" ";
		for(c=i;c<=2*a-i;c++) cout<<"*";
		cout<<endl;
	}
	return 0;
}
