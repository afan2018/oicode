#include<iostream>
using namespace std;
int main()
{
	long long n,a,b,s,minn=1ll<<50,c,k;
	cin>>n>>a>>b;n*=6;
	if(a*b>=n){cout<<a*b;return 0;}
    if(a>b)swap(a,b);
    int i=a;
    while(1)
    {
    	if(n%i==0)c=n/i;
    	else c=n/i+1;
    	s=c*i;
    	if(minn>s)minn=s;
    	i++;
    	if(i>b)break;
    	
	}
	cout<<minn;
	return 0;
}