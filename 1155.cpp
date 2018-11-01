#include<iostream>
using namespace std;
int main(){
    int a,b[15],len,i=1;
    cin>>a;
    while(a!=0)
	{
        b[i]=a%2;
    	i++;
		a=a/2;
    }
	for(int j=i-1;j>=1;j--)
	cout<<b[j];
	return 0;
}
