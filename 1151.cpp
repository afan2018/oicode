#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,n,t,a[101];   
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
	sort(a+1,a+n+1);
    for(i=1;i<=n;i++) 
	cout<<a[i]<<" ";  
	return 0;
}
