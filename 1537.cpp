#include<iostream>
using namespace std;
int main(){
	int n,m,b1,b2,b3,b4,b5;
	cin>>n;
	for(m=1;m<=n;m++)
	{
		b1=m%10;
		b2=m%100/10;
		b3=m%1000/100;
		b4=m%10000/1000;
		b5=m%100000/10000;
	    if(m==b1*b1*b1+b2*b2*b2+b3*b3*b3+b4*b4*b4+b5*b5*b5)
	    cout<<m<<endl;
	}
	return 0;
}