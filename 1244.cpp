#include<iostream>
using namespace std;
int main(){
    int a,b[233333],i=1,n,j;
    cin>>a>>n;
    cout<<"("<<a<<")"<<"10=(";
    while(a!=0)
	{
        b[i]=a%n;
    	i++;
		a=a/n;
    }
	for(j=i-1;j>=1;j--)
	{
		if(b[j]>9) cout<<char(65+b[j]-10);
		else cout<<b[j];
	}
	cout<<")"<<n;
	return 0;
}
